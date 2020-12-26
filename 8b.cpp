#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;
set<int> hechas;
vector<pair<string,int>> vect;

int main()
{
	string letras;
	int cant;
	while(cin>>letras>>cant)
	{
		vect.push_back({letras,cant});
	}
    /*for(int y=0; y<vect.size();y++){
		cout<<vect[y].first<<" "<<vect[y].second<<endl;
	}*/
	

	for(int j=0; j<vect.size();j++){
		auto vect_copy=vect;
		int contador=0;	
		if(vect_copy[j].first=="nop"){
			vect_copy[j].first="jmp";
			
		}else if(vect_copy[j].first=="jmp"){
			vect_copy[j].first="nop";
		}
		int i=0;
		int s=0;
		while(s<1000 and i<vect.size() and i>=0){
			hechas.insert(i);
			if(vect_copy[i].first=="acc"){
				contador+=vect_copy[i].second;
				i++;
			}
			if(vect_copy[i].first=="nop"){
				i++;
			}
			if(vect_copy[i].first=="jmp"){
				i+=vect_copy[i].second;
			}
			s++;
		}
		hechas.clear();
		if(i==vect_copy.size()){
			cout<<contador<<endl;
			return 0;
		}

	}
	

}