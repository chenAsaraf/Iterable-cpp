#pragma once

using namespace std;

namespace itertools{
	
	template<typename T> class powerset{

		private:
		//Varaiables
		T start; 
		public:
		//Constructor
		powerset(T firstValue) : start(firstValue){}


		//-------------------------------------------------------------------
		// iterator related code:
		// inner class and methods that return instances of it)
		//-------------------------------------------------------------------
		class iterator {
			private:
			T value;
			
			public:
			//Constructor
			iterator(T rangeStartElement):  value(rangeStartElement){}

			// The method is const as this operator does not allow changing of the iterator.
			// Note that it returns T& as it allows to change what it points to.
			auto operator*() const {
				return *value;
			}
			
			// ++i; 
			iterator* operator++() {
				value++;
				return *this;
			}

			bool operator!=(const iterator& other) const {
				return value != (other.value);
			}
		}; //end iterator

		auto begin() const {
        	return (start.begin());
    	}

   		auto end() const {
        	return (start.end());
		}

		

	};//end of class range
};//end namespace itertools