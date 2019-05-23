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


		//Iterator Inner class:
		class iterator {
			
			private:
			T it1;
			
			public:
			//Constructor
			iterator(T rangeStartElement):  it1(rangeStartElement){}

			// The method is const as this operator does not allow changing of the iterator.
			T operator*() const {
				return it1;
			}

			//Opertator ++i; 
			iterator* operator++() {
				it1++;
				return this;
			}

			//Operator i++; 
			const iterator operator++(int) {
				iterator tmp= *this;
				it1++;
				return tmp; 		
			}
			
			//Opertor ==
			bool operator==(const iterator& other) const {
				return it1 == (other.it1);
			}
			
			//Operator !=
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
