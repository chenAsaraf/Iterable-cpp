#pragma once

using namespace std;

namespace itertools {
	/*~Class chain- Represents a concatenation of two container-like.~*/
	template<typename T,typename S> class chain{
		private:
		T iterable1;
		S iterable2;
		
		//Inner class Iterator
		template<typename A,typename B> class iterator{
			private:
			//Variabels (private)
			A first;
			B second;
			
			public:
			//Variabels (public)
			bool isFirstEnd = false;
			
			//Iterator constructor
			iterator(A iterator_1,B iterator_2):first(iterator_1),second(iterator_2){}
			
			//Operator ==
			bool operator ==(chain::iterator<A,B> const &other){
				return (*first==*other.first) && (*second==*other.second);
			}
			
			//Operator i++
			iterator operator++(int) {
				iterator tmp= *this;
				if(!isFirstEnd) first++;
				else second++;
				return tmp;
			}
			
			//Operator !=
			bool operator!=(chain::iterator<A,B> const &other){
				if(!isFirstEnd && first == other.first) isFirstEnd = true;
				if(isFirstEnd) return second != other.second;
				return first != other.first;
			}

			//Operator *
			auto operator*() const {
				if(isFirstEnd) return *second;
				return *first;
			}
			
			//Operator ++i
			chain::iterator<A,B> &operator++() {
				if(!isFirstEnd) first++;
				else second++;
				return *this;
			}
		};

		public:
		
		//Chain constructor
		chain(T t,S s):iterable1(t),iterable2(s){}

		auto begin() const{
			return chain::iterator<decltype(iterable1.begin()),decltype(iterable2.begin())>(iterable1.begin(),iterable2.begin());
		}

		auto end() const{
			return chain::iterator<decltype(iterable1.end()),decltype(iterable2.end())>(iterable1.end(), iterable2.end());
		}
	};//end class chain
	
};//end namespace iteratools
