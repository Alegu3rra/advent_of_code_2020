#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	int num;
	vector <int> gatico;
	while(cin>>num){
		gatico.push_back(num);
	}
	for(int i=0; i<gatico.size(); i++){
		for(int j=i+1; j<gatico.size(); j++){
			for(int k=j+1; k<gatico.size(); k++){
				if(gatico[j]+gatico[i]+gatico[k]==2020)
					cout<<gatico[j]*gatico[i]*gatico[k]<<endl;
		}
		}
	}
}