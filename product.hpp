#pragma once

using namespace std;

namespace itertools{
	
	template<typename T,typename S> class product{

		public:
		//Varaiables
		T start;
		S start2; 

		//Constructor
		product(T firstValue, S secondValue) : start(firstValue), start2(secondValue){}


		//-------------------------------------------------------------------
		// iterator related code:
		// inner class and methods that return instances of it)
		//-------------------------------------------------------------------
		
		template<typename A,typename B> class iterator {
			private:
			A value;
			B value2;
			public:
			//Constructor
			iterator(T firstStart, S secondStart):  value(firstStart),value2(secondStart){}

			// The method is const as this operator does not allow changing of the iterator.
			// Note that it returns T& as it allows to change what it points to.
			T operator*() const {
				return value;
			}

			T* operator->() const {
				return &value;
			}

			// ++i; 
			iterator* operator++() {
				value++;
				return this;
			}

			// i++; 
			// Usually iterators are passed by value and not by const& as they are small.
			const iterator operator++(int) {
				iterator tmp= *this;
				value++;
				return tmp; 		
			}

			bool operator==(const iterator& other) const {
				return value == (other.value);
			}

			bool operator!=(const iterator& other) const {
				return value != (other.value);
			}
		}; //end iterator

		auto begin() const{
			return (start.begin(), start2.begin());
		}
		
		auto end() const{
			return (start.end(), start2.end());
		}
		

	};//end of class range
};//end namespace itertools