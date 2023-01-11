#include "track.hpp"
#include <iostream>
using namespace std;

int main(){
	Hanako::track<int> a;
	a.resize(5);
	cout<<a.size()<<endl;
	for(int i=0;i<a.size();i++){
		a[i]=i;
		cout<<a[i]<<'	';
	}
	cout<<endl;
	a.insert(2,233);
	cout<<a.size()<<endl;
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<'	';
	}
	
	return 0;
}
