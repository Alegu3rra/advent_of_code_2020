#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

vector<int> nums;
int main(){
	string dato;
	int marca;
	cin>>marca;
	while(getline(cin,dato,',')){
		if(dato!="x"){
			int valor;
			string s = dato; 
			stringstream ss(s); 
			ss >> valor;
			nums.push_back(valor);
		}
	}
	long long menordif=100000000000;
	long long res;
	for(auto x: nums){
		int temp1=floor(marca/x)+1;
		int temp2=x-(marca%x);
		if(temp1*x<menordif){
			menordif=temp1*x;
			res=x;
		}
	}
	menordif-=marca;
	res*=menordif;
	cout<<res<<endl;
	/*cout<<marca<<endl;
	for(auto x: nums){
		cout<<x<<endl;
	}*/
}







