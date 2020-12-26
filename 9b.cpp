#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
typedef long long ll;
ll num_search=393911906;

int main(){
	vector<ll> lista;
	ll dato;
	vector<ll> numeros;
	while(cin>>dato){
		lista.push_back(dato);
	}
	ll igualito=0;
	int i=0;
	while(i<lista.size()){	
		if(igualito>num_search){
			igualito-=numeros[0];
			numeros.erase(numeros.begin());
			
		}else if(igualito<num_search){
			numeros.push_back(lista[i]);
			igualito+=lista[i];
			i++;

		}else{
			cout<<" "<<*max_element(numeros.begin(), numeros.end())+*min_element(numeros.begin(), numeros.end())<<endl;
			return 0;
		}
	}
	cout<<"no lo encontraste"<<endl;
	
}