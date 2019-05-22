#pragma once
#include <algorithm>
#include <string>


using namespace std;

namespace itertools{
 template<typename C, typename U> class chain{
        private:
        
        public:
        //varaiables -Ichanged to reference - 21.5.19
        C first;
		U second;
	

		//Constructor  
		chain(C Itrable1, U Iterable2) : //I changed to reference - 21.5.19
		first(Itrable1), second(Iterable2) {}

        //Inner class iterator:
        template<typename F, typename S>class const_iterator{
            private: 
            F firstBegin;
			F firstEnd;
			S secondBegin;

            public:
			//Constructor
			const_iterator(F firstBegin, F firstEnd, S secondBegin): 
            firstBegin(firstBegin), firstEnd(firstEnd), secondBegin(secondBegin){}

			//Copy constructor
			const_iterator(const_iterator& other) : 
			firstBegin(other.firstBegin), firstEnd(other.firstEnd), secondBegin(other.secondBegin){}

			//Move constructor
			const_iterator(const_iterator&& other) :
			firstBegin(NULL), firstEnd(NULL), secondBegin(NULL){
			cout << "in move constructor " << endl;
			firstBegin = other.begin();
			firstEnd = other.end();
			secondBegin = other.begin();
			}


			// iterator(decltype(second.end()) secondEnd ): 
            // firstBegin(secondEnd), firstEnd(secondEnd), secondBegin(secondEnd){}

            

			auto operator*() const{
				//cout << "inside *" << endl;
				if((*firstBegin > *firstEnd) || (*firstBegin == *firstEnd)){
					cout <<"inside * : if((*firstBegin > *firstEnd) || (*firstBegin == *firstEnd))" << endl;
					return *secondBegin;
				} 
				else return *firstBegin; //if *firstBegin < *firstEnd
			}

            
			// ++i; 
			const_iterator* operator++() {
				//cout << "inside ++ "  << endl;
				*firstBegin++;
				if (*firstBegin < *firstEnd) return this;
				else{ //(*firstBegin == *firstEnd)
					*secondBegin++;
					return this;
				} 
			}

            // i++; 
			const const_iterator operator++(int) {
				//cout << "inside ++ const" << endl;
				const_iterator tmp= *this;
				*firstBegin++;
				if (*firstBegin < *firstEnd) return tmp;
				else{ //(*firstBegin == *firstEnd)
					*secondBegin++;
					return tmp;
				} 		
			}

			bool operator==(const const_iterator& other) const {
				//cout << "inside ==" << endl;
				return *secondBegin == *other.secondBegin && *firstEnd == *other.firstEnd;
			}

			bool operator!=(const const_iterator& other) const {
				//cout << "inside != chain" << endl;
				//cout << " *secondBegin != *other.secondBegin " <<  (*secondBegin != *other.secondBegin) <<endl;
				//cout << "*firstBegin != *other.firstBegin" << (*firstBegin != *other.firstBegin) << endl;
				return *secondBegin != *other.secondBegin;
			}

		};//end iterator



		auto begin() const{
			//cout << "inside begin chain" << endl;
			return  chain<C,U>::const_iterator<decltype(first.begin()), decltype(second.begin())>(first.begin(), first.end(), second.begin());
		}
		
		auto end() const{
			//cout << "inside end chain" << endl;
			return chain<C,U>::const_iterator<decltype(first.end()), decltype(second.end())>(first.end(), first.end(), second.end());
		}

    };//end class chain
};//end namespace itertools


