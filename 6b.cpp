#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

map<char, int> si;

int main(){
	string datos;
	int cadenas=0;
	int count=0;
	while(getline(cin,datos)){
		if(datos==""){
			int mayor=0;
			for(auto x: si){
				if(x.second==cadenas)
					count++;
				
			}
			cout<<count<<endl;
			si.clear();
			cadenas=0;
		}
		else{
			for(int i=0;i<datos.size();i++){
					si[datos[i]]++;
			}
			cadenas++;
		}
		
	}
	cout<<count<<endl;
}