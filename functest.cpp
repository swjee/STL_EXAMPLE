
#include <iostream>
#include <utility>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

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
	cout << n << " " ;
}


//functor ....
//
/*
template < class T> class Sum{

	private:
		T res;

	public:
		Sum( const Sum& s):res(s.res){ 
			cout << "copy const called. " << s.res << endl;
			cout << this << endl;
			cout << &s << endl;
			cout << "---------------" << endl;
		}
		Sum(T i=0):res(i){}
		void operator()(T x){ 
			res += x; 
			cout << "res: " << res << endl;	
			cout << "whoami:  " << this << endl;
		}
		T result() const{ return res;}
		Sum& operator=(const Sum& s){
			cout << "assign = called " << endl;
			res = s.res;
			cout << this << endl;
			cout << &s << endl;
			cout << "-----------" << endl;
			return (*this);
		}
};
*/
template < class T> class Sum{

	private:
		T res;

	public:
		Sum(T i=0):res(i){}
		void operator()(T x){ 
			res += x; 
		}
		T result() const{ return res;}
};


struct UserName{
	string firstName;
	string lastName;
	UserName(const string& f, const string& l):firstName(f),lastName(l){}

	void print() const {
		cout << firstName << "," << lastName << endl;
	}
};

void printUN( const UserName&  un ){
	un.print();
}

class LastName_eq:public unary_function < UserName , bool >{
		string lastName;
	public:
		LastName_eq(const string& s):lastName(s){}
		bool operator()(const UserName& ss){
			return ss.lastName == lastName;
		}	
};


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

	Sum < int > s;

	s = for_each( iseq(v_n),s);

	cout << " sum is " << s.result() << endl;
	

	cout << " 술어함수 훑어 보기 " << endl; 


	cout << "equal_to" << endl;
	cout << "not_equal_to" << endl;
	cout << "greater" << endl;
	cout << "less" << endl;
	cout << "greater_equal" << endl;
	cout << "less_equal" << endl;
	cout << "logical_and" << endl;
	cout << "logical_or" << endl;
	cout << "logical_not" << endl;
	cout << "---------------" << endl;

	vector<int> v_m;
	for ( int i=9;i>=0; --i)
		v_m.push_back(i);


	for_each( iseq (v_n),print);
	cout << endl;
	for_each( iseq (v_m),print);
	cout << endl;
	pair<vector<int>::iterator , vector<int>::iterator > pair_it = mismatch( v_n.begin(),v_n.end(),v_m.begin(),less<int>());

	cout << *pair_it.first << endl;
	cout << *pair_it.second << endl;

	//         20200920  

	UserName un("hello","world");


	vector < UserName > v_un;


	v_un.push_back( UserName("hello_1","world"));
	v_un.push_back( UserName("hello_2","world"));
	v_un.push_back( UserName("hello_3","world"));
	v_un.push_back( UserName("hello_4","world"));
	v_un.push_back( UserName("hello_5","world"));
	v_un.push_back( UserName("hello_6","world"));
	v_un.push_back( UserName("hello_7","world"));
	v_un.push_back( UserName("hello_8","world"));
	v_un.push_back( UserName("hello_9","world"));
	v_un.push_back( UserName("hello_10","world1"));
	v_un.push_back( UserName("hello_11","world1"));
	v_un.push_back( UserName("hello_12","world1"));
	v_un.push_back( UserName("hello_13","world1"));
	v_un.push_back( UserName("hello_14","world1"));
	v_un.push_back( UserName("hello_15","world1"));


	for_each( iseq( v_un ) , printUN);

	cout << "------------------------" << endl;
	vector<UserName>::iterator it  = v_un.begin();
	while ( v_un.end() !=( it = find_if( it , v_un.end(),LastName_eq("world"))) )  {
		printUN(*it);
		++it;
	}	

	cout << "------------------------" << endl;
	it  = v_un.begin();
	while ( v_un.end() !=( it = find_if( it , v_un.end(),LastName_eq("world1"))) )  {
		printUN(*it);
		++it;
	}
	return 0;

}
