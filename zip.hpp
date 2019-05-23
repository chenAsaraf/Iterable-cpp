#pragma once
#include <iostream>

using namespace std;

namespace itertools{
/*~Parallel connection of two container-like~*/
/*We can assume that th inputs are the same length*/
	template<typename T,typename S> class zip{
		
		private:
		//Varaiables
		T start;
		S start2; 
		
		//Inner class iterator:
		template<typename A,typename B> class iterator {
			
			private:
			//Varaiables
			A it1;
			B it2;
			
			public:
			//Iterator constructor
			iterator(A firstStart, B secondStart):  it1(firstStart),it2(secondStart){}
			
			//Operator !=
			bool operator!=(zip::iterator<A,B> const &other){
					return (it1 != other.it1) && (it2 != other.it2);
			}
			
			//Operator *
			std::pair<decltype(*it1),decltype(*it2)> operator*() const {
				return std::pair<decltype(*it1),decltype(*it2)>(*it1,*it2);
			}
					
			//Operator ++i
			zip::iterator<A,B> &operator++() {
				++it1;
				++it2;
				return *this;
			}
			
		}; //end iterator Inner class

		public:

		//Zip constructor
		zip(T firstValue, S secondValue) : start(firstValue), start2(secondValue){}

		auto begin() const{
			return zip::iterator<decltype(start.begin()),decltype(start2.begin())>(start.begin(),start2.begin());
		}

		auto end() const{
			return zip::iterator<decltype(start.end()),decltype(start2.end())>(start.end(), start2.end());
		}
		
	};//end of class zip
	
	//Output operator for std::pair
	template <typename K,typename E>
	std::ostream &operator<<(std::ostream &os, const std::pair<K,E>&p)
	{
    	os << p.first << ',' << p.second;
    	return os;
	}
	
};//end namespace itertools
