#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int,int> cuantos={{1,0},{3,0}};
vector<int> line;
ll memo[1000];

ll funcion(int i){//parece dfs pero no lo es
	if(i==line.size()-1){
		return 1;
	}
	if( memo[i]!=-1){//guarda las respuestas para no tener que consultarlas again
		return memo[i];//mejor conocido como dp
	}
	ll ans=0;
	for(int j=i+1;j<=line.size()-1;j++){
		if(line[j]-line[i]<=3)
		ans+=funcion(j);
	}
	return memo[i]=ans;
}

int main(){
    int dato;
    while(cin>>dato){
        line.push_back(dato);
    }
    line.push_back(0);
    line.push_back(*max_element(line.begin(),line.end())+3);
    sort(line.begin(),line.end());
	memset(memo, -1, sizeof(memo));
	ll temp = funcion(0);
	cout<<temp<<endl;
	
    /*for(int x=1;x<=line.size()-1;x++){
        int temp=line[x]-line[x-1];
        if(temp==1)cuantos[1]++;
        if(temp==3)cuantos[3]++;
    }
    int temp1=1;
    for(auto c: cuantos){
        temp1*=c.second;
    }
    cout<<temp1<<endl;*/
}