#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

set<char> si;

int main(){
	string datos;
	int count=0;
	while(getline(cin,datos)){
		if(datos==""){
			count+=si.size();
			si.clear();
		}
		else{
			for(int i=0;i<datos.size();i++){
				si.insert(datos[i]);
			}
		}
		
	}
	cout<<count<<endl;
}