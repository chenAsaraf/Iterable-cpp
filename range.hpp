#pragma once

using namespace std;

namespace itertools{
	
	template<typename T> class range{

		private:
		T start;
		T finish;

		public:

		//Constructor
		range(T firstiValue, T secondiValue) : start(firstiValue), finish(secondiValue){}


		//-------------------------------------------------------------------
		// iterator related code:
		// inner class and methods that return instances of it)
		//-------------------------------------------------------------------
		class iterator {
			private:
			T it1;
			
			public:
			//Constructor
			iterator(T rangeStartElement):  it1(rangeStartElement){}

			// The method is const as this operator does not allow changing of the iterator.
			// Note that it returns T& as it allows to change what it points to.
			T operator*() const {
				return it1;
			}

			T* operator->() const {
				return &it1;
			}

			// ++i; 
			iterator* operator++() {
				it1++;
				return this;
			}

			// i++; 
			// Usually iterators are passed by it1 and not by const& as they are small.
			const iterator operator++(int) {
				iterator tmp= *this;
				it1++;
				return tmp; 		
			}

			bool operator==(const iterator& other) const {
				return it1 == (other.it1);
			}

			bool operator!=(const iterator& other) const {
				return it1 != (other.it1);
			}
		}; //end iterator

		iterator begin() const{
			return iterator{start};
		}
		
		iterator end() const{
			return iterator{finish};
		}

		

	};//end of class range
};//end namespace itertools