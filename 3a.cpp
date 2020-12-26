#include <iostream>
#include <string>

using namespace std;

int main(){
	string mapa;
	int trees=0;
	int open=0;
	int i=0;
	while(getline(cin, mapa)){
		if(mapa[i]=='#'){
			trees++;
			mapa[i]='X';
		}else{
			open++;
			mapa[i]='O';
		}
		i = (i+3)%mapa.size();
		cout<<mapa<<endl;
	}
	cout<<trees;
	return 0;
}