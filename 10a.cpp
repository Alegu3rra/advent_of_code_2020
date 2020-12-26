#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
//#include <bits/stdc++.h>
using namespace std;
map<int,int> cuantos={{1,0},{3,0}};
vector<int> line;

int main(){
    int dato;
    while(cin>>dato){
        line.push_back(dato);
    }
    line.push_back(0);
    line.push_back(*max_element(line.begin(),line.end())+3);
    sort(line.begin(),line.end());
    for(int x=1;x<=line.size()-1;x++){
        int temp=line[x]-line[x-1];
        if(temp==1)cuantos[1]++;
        if(temp==3)cuantos[3]++;
    }
    int temp1=1;
    for(auto c: cuantos){
        temp1*=c.second;
    }
    cout<<temp1<<endl;
}