#pragma once

using namespace std;

namespace itertools {
	template<typename T,typename S> class chain{
		private:
		T first;
		S second;
		
		template<typename A,typename B> class iterator{
			private:
			A it1;
			B it2;
			public:
			iterator(A i1,B i2):it1(i1),it2(i2){}

			bool isFend = false;

			bool operator!=(chain::iterator<A,B> const &other){
				if(!isFend && it1 == other.it1) isFend = true;
				if(isFend) return it2 != other.it2;
				return it1 != other.it1;
			}

			decltype(*it1) operator*() const {
				if(isFend) return *it2;
				return *it1;
			}

			chain::iterator<A,B> &operator++() {
				if(!isFend) it1++;
				else it2++;
				return *this;
			}
		};

		public:

		chain(T x,S y):first(x),second(y){}

		auto begin() const{
			return chain::iterator<decltype(first.begin()),decltype(second.begin())>(first.begin(),second.begin());
		}

		auto end() const{
			return chain::iterator<decltype(first.end()),decltype(second.end())>(first.end(), second.end());
		}
	};
}