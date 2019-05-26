#include <set> 
#include <vector>
#include <cmath>
#include <iostream>

namespace itertools{
	/*~Class powerset - represents all sub-groups of container-like~*/
	template <class T> class _powerset{ 
		private:
		//Variabels
		T start;
		
		//Inner class iterator
		template <class E> class iterator {
			
			public:
			E it1;
			E it2;
        		unsigned int I;
       			unsigned int NumOfE;
			
			//Iterator constructor
			iterator(E itr_start, E itr_fin) :
			it1(itr_start), it2(itr_fin), I(0), NumOfE(0) {
				E element_iterator = it1;
            			while (element_iterator != it2){
					++NumOfE;
					++element_iterator;
				}
				NumOfE = std::pow(2, NumOfE);
			}
			
			
			//Operator !=
			bool operator!=(_powerset::iterator<E> const &other) const {
				return ((NumOfE - I) != (other.NumOfE - other.I - 1));
			}
			
			//Operator *
			auto operator*() const {
				E element_iterator = it1;
				std::vector<typename std::remove_const<typename std::remove_reference<decltype(*it1)>::type>::type> S;
				unsigned int i = I;
				while (i != 0 && element_iterator != it2){ 
					unsigned int r = i % 2;
					i = i >> 1; 
					if (r == 1)
						S.emplace_back(*element_iterator);
					++element_iterator;
				}
				return S;
			}
			
			//Operator ++i
			_powerset::iterator<E> &operator++() {
				++I;
				return *this;
			}
			
		};//end class iterator
		
		public:
		//_powerset constructor
		_powerset(T from) : start(from) {}    
		
		auto begin() const {
			return _powerset::iterator<decltype(start.begin())>(start.begin(), start.end());
		} 
		
    		auto end() const { 
			return _powerset::iterator<decltype(start.begin())>(start.end(), start.end()); 
		}
		
	};//end class _powerset
	
	//Function to iterate over the pwerset of container
	template <typename T> _powerset<T> powerset(T from){
		return _powerset<T>(from);
	}
	
	//Output operator for std::vector
	template <typename T> std::ostream &operator<<(std::ostream &stream, const std::vector<T> &S){
		stream << "{";
		auto temp = S.begin();
		if(temp != S.end()){ 
			stream << *temp; 
			++temp;
		}
		while (temp != S.end()){
			stream << ',' << *temp;
			++temp;
		}
		stream << "}";
		return stream;
	}
	
};//end namespace itertools
