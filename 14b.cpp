#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#define endl '\n'
using namespace std;
int main(){
	string dato1,equal,dato2;
	string mascara;
	map<long long,long long> mem;
	
	while(cin>>dato1>>equal>>dato2){
		string key;
		if(dato1=="mask"){
			//cout<<dato1<<","<<dato2<<endl;
			mascara=dato2;
		}else{
			for(int i=0;i<dato1.size();i++){
				if(isdigit(dato1[i]))
					key+=dato1[i];
			}
			//cout<<key<<","<<dato2<<endl;
			//parce to int
			long long keyint=0;
			stringstream ss1(key);
			ss1 >> keyint;
			//parce to bit
			long long datoint=0;
			stringstream ss2(dato2);
			ss2 >> datoint;
			bitset<36> datobit(datoint);
			string value = datobit.to_string();
			//operations
			//cout<<value<<" "<<endl<<mascara<<endl;
			for(int x=mascara.size(); x>=0;x--){
				if(mascara[x]=='1'){
					value[x]='1';
				}else if(mascara[x]=='0'){
					value[x]='0';
				}
			}
			//cout<<value<<endl;
			//save
			bitset<36> datobit2(value);
			long long datoint2=datobit2.to_ullong();
			mem[keyint]=datoint2;
			//cout<<keyint<<" "<<datoint2<<endl<<endl;
		}		
	}
	long long res=0;
	for(auto x: mem){
		//cout << x.second<<","; 
		res+=x.second;
	}
	cout<<res;
}