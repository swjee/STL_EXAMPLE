
#include <iostream>
#include <utility>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;


/*
plus
*/

void print( int i ){
	cout << i << "	," ;
}
int main(){
	

	vector < int > v_1;
	vector < int > v_2;

	vector < int > v_r;


	for(int i=0;i<10;++i)
		v_1.push_back(i);

	for(int i=0;i<10;++i)
		v_2.push_back(i+10);



	cout << "v_1:" ;
	for_each(v_1.begin(),v_1.end(),print);
	cout << endl;	

	cout << "v_2:" ;
	for_each(v_2.begin(),v_2.end(),print);
	cout << endl;	

	cout << "-------- v_1 + v_2 --------------" << endl;
	transform( v_1.begin(),v_1.end(),v_2.begin(),back_inserter(v_r), plus<int>()); 
	for_each(v_r.begin(),v_r.end(),print);
	cout << endl;

	cout << "-------- v_1 - v_2 --------------" << endl;
	v_r.clear();
	transform( v_1.begin(),v_1.end(),v_2.begin(),back_inserter(v_r), minus<int>()); 
	for_each(v_r.begin(),v_r.end(),print);
	cout << endl;

	cout << "-------- v_1 * v_2 --------------" << endl;
	v_r.clear();
	transform( v_1.begin(),v_1.end(),v_2.begin(),back_inserter(v_r), multiplies<int>()); 
	for_each(v_r.begin(),v_r.end(),print);
	cout << endl;



	return 0;
}
