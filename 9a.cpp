#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
ll previous=25;//cout<<" "<<*max_element(numeros.begin(), numeros.end())+*min_element(numeros.begin(), numeros.end())<<endl;

int main(){
	vector<ll> lista;
	ll dato;
	while(cin>>dato){
		lista.push_back(dato);
	}
	for(int i=0;i<lista.size()-previous;i++){	
		set<ll> sumas;
		for(int y=i; y<previous+i;y++){
			for(int j=y+1; j<previous+i;j++){
				ll suma= lista[y]+lista[j];
				sumas.insert(suma);
			}
		}
		if(sumas.find(lista[previous+i])==sumas.end()){
			cout<<lista[previous+i]<<endl;
			break;
		}
	}
}