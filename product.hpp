#pragma once

using namespace std;

namespace itertools {
	
	/*~Class product - represent cartesian product~*/
	template<typename T,typename S> class product{
		private:
		T iterabel1;
		S iterabel2;
		
		//Inner class iterator
		template<typename A,typename B> class iterator{
			private:
			//Variabels(private)
			A first;
			B second;
			
			public:
			//Variabels(public)
			A holder = second;//A holder = first;
			
			//Iterator constructor
			iterator(A iterator_1, B iterator_2) : first(iterator_1), second(iterator_2) {}
			
			//Operator !=
			bool operator!=(product::iterator<A,B> const &other){
// 				if(!(first != other.first)) {
// 					first = holder;
// 					++second;
// 				}
				if(!(second != other.second)) {
					second = holder;
					++first;
				}
				return first != other.first && second != other.second;
			}
			
			//Operator *	
			std::pair<decltype(*first),decltype(*second)> operator*() const {
				return std::pair<decltype(*first),decltype(*second)>(*first, *second);
			}
			
			//Operator ++i
			product::iterator<A,B> &operator++() {
				++second;//++first;
				return *this;
			}
			
		};//end class iterator

		public:
		//Product constructor
		product(T x,S y):iterabel1(x),iterabel2(y){}
		
		auto begin() const{
			return product::iterator<decltype(iterabel1.begin()),decltype(iterabel2.begin())>(iterabel1.begin(),iterabel2.begin());
		}

		auto end() const{
			return product::iterator<decltype(iterabel1.end()),decltype(iterabel2.end())>(iterabel1.end(), iterabel2.end());
		}
		
	};//end class product
	
};//end namespace iteratools
