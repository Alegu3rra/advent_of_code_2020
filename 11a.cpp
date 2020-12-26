#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;
vector<string>nuevo;
vector<string>viejo;
vector<pair<int,int>> coord = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int main(){
    string dato;
    while(getline(cin,dato)){
        viejo.push_back(dato);
		
    }
	bool bandera=true;
	while(bandera){
		
		for(int x=0; x<viejo.size();x++){
			string datonuevo="";
			for(int y=0;y<viejo[x].size();y++){
				/*adyacencias*/
				int ocupa=0;
				for(auto c: coord){
					if(x+c.first>=0 and y+c.second<viejo[x].size() and y+c.second>=0 and x+c.first<viejo.size()){
						if(viejo[x+c.first][y+c.second]=='#'){
							ocupa++;
						}
					}
				}
				if(viejo[x][y]=='L' and ocupa==0){
					datonuevo.push_back('#');
				}else if(viejo[x][y]=='#' and ocupa>=4){
					datonuevo.push_back('L');
				}else{
					datonuevo.push_back(viejo[x][y]);
				}
				
				//cout<<viejo[x][y]<<endl;
			}
			nuevo.push_back(datonuevo);
		}
		int dif=0;
		for(int k=0;k<nuevo.size();k++){
			cout<<viejo[k]<<" "<<nuevo[k]<<endl;
			if(nuevo[k]!=viejo[k]){
				dif++;
			}
		}
		
		if(dif==0){
			bandera=false;
		}else{
			viejo.clear();
			viejo=nuevo;
			nuevo.clear();
		}
		cout<<endl;
		
		//bandera=false;
	}
	for(auto x: nuevo){
		cout<<x<<endl;
	}
	cout<<endl;
	for(auto x: viejo){
		cout<<x<<endl;
	}
	
	int res=0;
	for(int a=0; a<nuevo.size();a++){
		for(int b=0; b<nuevo[a].size(); b++){
			//cout<<nuevo[a][b];
			if(nuevo[a][b]=='#'){
				res++;
			}
		}
		//cout<<endl;
	}
	cout<<res<<endl;

}