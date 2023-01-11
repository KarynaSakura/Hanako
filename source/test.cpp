#include "track.hpp"
#include <iostream>
using namespace std;

int main(){
	Hanako::track<int> a;
	a.resize(5);
	cout<<a.size()<<endl;
	a.access(2,233);
	cout<<a[2]<<endl; 
	return 0;
}
