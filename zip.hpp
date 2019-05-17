#pragma once
#include <iostream>

using namespace std;

namespace itertools{
	template <typename T,typename E>
	std::ostream &operator<<(std::ostream &os, const std::pair<T,E>&p)
	{
    	os << p.first << ',' << p.second;
    	return os;
	}

	template<typename T,typename S> class zip{

		private:
		//Varaiables
		T start;
		S start2; 

		//-------------------------------------------------------------------
		// iterator related code:
		// inner class and methods that return instances of it)
		//-------------------------------------------------------------------
		
		template<typename A,typename B> class iterator {
			private:
			A it1;
			B it2;
			public:
			//Constructor
			iterator(A firstStart, B secondStart):  it1(firstStart),it2(secondStart){}

			bool operator!=(zip::iterator<A,B> const &other){
					return (it1 != other.it1) && (it2 != other.it2);
			}

			std::pair<decltype(*it1),decltype(*it2)> operator*() const {
				return std::pair<decltype(*it1),decltype(*it2)>(*it1,*it2);
			}

			zip::iterator<A,B> &operator++() {
				++it1;
				++it2;
				return *this;
			}
		}; //end iterator

		public:

		//Constructor
		zip(T firstValue, S secondValue) : start(firstValue), start2(secondValue){}

		auto begin() const{
			return zip::iterator<decltype(start.begin()),decltype(start2.begin())>(start.begin(),start2.begin());
		}

		auto end() const{
			return zip::iterator<decltype(start.end()),decltype(start2.end())>(start.end(), start2.end());
		}
		

	};//end of class range
};//end namespace itertools
