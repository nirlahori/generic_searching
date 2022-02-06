#include<iostream>


/*
	Contains Linear Search and Binary Search Algorithms.
	I will update them to more improve versions.

*/




namespace search{

	/* 
		Linear Search Algorithm for searching between ranges
		E_Tp = Data Type of elements
		E_Cmp = Type of user-defined comparison function, will invoke call operator of the given type
	*/

	template<
		typename E_Tp,
		typename E_Cmp = std::equal_to<E_Tp>
	>
	constexpr bool linear_search(const E_Tp *src, const E_Tp *end, const E_Tp key){
		E_Cmp compare;
		const E_Tp *stop = end + 1;
		while(src != stop){
			if(compare(*src, key))
				return true;
			src++;
		}
		return false;
	}
	
	/*
		Linear Search Function Template Overload for collecting the matched elements
	*/

	template<
		typename E_Tp,
		typename E_Cmp = std::equal_to<E_Tp>
	>
	bool linear_search(const E_Tp *src, const E_Tp *end, const E_Tp key, E_Tp* coll){
		E_Cmp compare;
		const E_Tp *stop = end + 1;
		E_Tp* scoll = coll;

		while(src != stop){
			if(compare(*src, key)){
				*coll = *src;
				coll++;
			}
			src++;
		}
		return (scoll == coll) ? false : true;
	}


	/* 
		Binary Search Algorithm for any generic container type which supports subscripting and size function 
		E_Tp = Data Type of elements, the given type must implement comparison operators
		E_Cmp = Type of user-defined comparison function, will invoke call operator of the given type
	*/

	template<
		typename E_Tp,
		typename E_Cmp = std::equal_to<E_Tp>,
		template<typename> typename Cont
	>
	bool binary_search(const Cont<E_Tp>& c, const E_Tp key){
		int first = 0;
		int last = c.size() - 1;
		E_Cmp compare;

		while(first != last && first < last){
			int middle = (first + last) / 2;
			if(compare(c[middle], key))
				return true;

			if(key > c[middle])
				first = middle + 1;
			
			if(key < c[middle])
				last = middle - 1;
		}
		if(compare(c[first], key))
			return true;

		return false;
	}

	/*
		Binary Search Specialization for arrays of ints. 
	*/

	constexpr bool binary_search(const int src[], const int size, const int key){
		int first = 0;
		int last = size - 1;

		while(first != last && first < last){
			int middle = (first + last) / 2;
			if(src[middle] == key)
				return true;

			if(key > src[middle])
				first = middle + 1;
					
			if(key < src[middle])
				last = middle - 1;
		}
		if(src[first] == key)
			return true;
		
		return false;
	}
}

