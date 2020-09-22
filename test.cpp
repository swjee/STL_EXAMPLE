/*
 *
 *
   template<typename _InputIterator, typename _Function>
    _Function
    for_each(_InputIterator __first, _InputIterator __last, _Function __f)
    {
      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_requires_valid_range(__first, __last);
      for (; __first != __last; ++__first)
	__f(*__first);
      return _GLIBCXX_MOVE(__f);
    }
//
//   *  @brief Find the first occurrence of a value in a sequence.
//   *  @ingroup non_mutating_algorithms
//   *  @param  __first  An input iterator.
//   *  @param  __last   An input iterator.
//   *  @param  __val    The value to find.
//   *  @return   The first iterator @c i in the range @p [__first,__last)
//   *  such that @c *i == @p __val, or @p __last if no such iterator exists.

  template<typename _InputIterator, typename _Tp>
    inline _InputIterator
    find(_InputIterator __first, _InputIterator __last,
	 const _Tp& __val)
    {
      // concept requirements
      __glibcxx_function_requires(_InputIteratorConcept<_InputIterator>)
      __glibcxx_function_requires(_EqualOpConcept<
		typename iterator_traits<_InputIterator>::value_type, _Tp>)
      __glibcxx_requires_valid_range(__first, __last);
      return std::__find(__first, __last, __val,
		         std::__iterator_category(__first));
    }
*
 *
 *
 *
 *
 *
 */


#include <iostream>
#include <utility>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;



/////////////////////////////////////////


template< class In > struct Iseq : public pair<In,In>{
	
	Iseq( In i1, In i2):pair<In,In>(i1,i2){}

};


template < class C > Iseq< typename C::iterator > iseq( C& c){

	return Iseq < typename C::iterator > ( c.begin(),c.end());
}

template<typename _InputContainer, typename _Function>
_Function
for_each(Iseq < _InputContainer > incont  , _Function __f)
{
	return for_each ( incont.first , incont.second , __f);
}


/////////////////////////////////////////

void print(int n){
	cout << n << endl;
}

int main(){

	vector<int>  v_n;

	for ( int i =0 ;i < 10; ++i)
		v_n.push_back( i );

	for( vector<int>::iterator it = v_n.begin() ; it != v_n.end(); ++it)
		cout << *it << endl;

	for_each( v_n.begin(),v_n.end(),print);	

	
	pair < vector < int >::iterator ,vector< int >::iterator > a = iseq( v_n );


	for( vector<int>::iterator it = a.first; it!= a.second ; ++it)
		cout << *it << " ";

	cout <<  endl;

	cout << " test.. input sequence... " << endl;
	//for_each( iseq<vector < int > > (v_n),print);
	for_each( iseq (v_n),print);

	return 0;

}
