#pragma once

using namespace std;

namespace itertools {
	template<typename T,typename S> class product{
		private:
		T first;
		S second;
		
		template<typename A,typename B> class iterator{
			private:
			A it1;
			B it2;
			public:
			A holder = it1;
			iterator(A i1,B i2):it1(i1),it2(i2){}
			bool operator!=(product::iterator<A,B> const &other){
				if(it1 == other.it1) {
					it1 = holder;
					it2++;
				}
				return it1 != other.it1 && it2 != other.it2;
			}

			std::pair<decltype(*it1),decltype(*it2)> operator*() const {
				return std::pair<decltype(*it1),decltype(*it2)>(*it1,*it2);
			}

			product::iterator<A,B> &operator++() {
				it1++;
				return *this;
			}
		};

		public:

		product(T x,S y):first(x),second(y){}

		auto begin() const{
			return product::iterator<decltype(first.begin()),decltype(second.begin())>(first.begin(),second.begin());
		}

		auto end() const{
			return product::iterator<decltype(first.end()),decltype(second.end())>(first.end(), second.end());
		}
	};
}