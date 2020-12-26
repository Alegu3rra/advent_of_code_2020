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
	int i=0;
	int contador=0;
	while(hechas.find(i)==hechas.end())
	{
		hechas.insert(i);
		if(vect[i].first=="acc"){
			contador+=vect[i].second;
			i++;
		}
		if(vect[i].first=="nop"){
			i++;
		}
		if(vect[i].first=="jmp"){
			i+=vect[i].second;
		}
		
		cout<<vect[i].first<<" "<<vect[i].second<<" "<<i+1<<endl;
	}
	cout<<contador<<endl;

}