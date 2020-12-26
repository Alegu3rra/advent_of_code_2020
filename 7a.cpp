#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <sstream>
#include <queue>
#include <set>
using namespace std;

map<string, vector<pair<int,string>>> bag;
vector <string>line;
queue<string>colita;
set<string>bags_shiny;
queue<int>num_bag;

long long DFS(string nodo){
	long long res=1;
	for(auto x: bag[nodo]){
		res+=x.first*DFS(x.second);
	}
	return res;
}

int main(){
	string datos;
	
	while(getline(cin, datos)){//leo
		istringstream isstream(datos);
		while(!isstream.eof()){
			string tempStr;
			isstream >> tempStr;
			while(tempStr[tempStr.size()-1]=='s' or tempStr[tempStr.size()-1]==',' or tempStr[tempStr.size()-1]=='.')
				tempStr.pop_back();
			if(isdigit(tempStr[0])){
				//cout << tempStr << endl;
				num_bag.push(tempStr[0]-'0');
			}else{
				line.push_back(tempStr);
			}
		}
		/*while(!num_bag.empty()){
			cout<<num_bag.front()<<endl;
			num_bag.pop();
		}
		cout<<endl;*/
		/*for(auto c: line)
			cout << c<<" ";
		cout << endl;*/
		string key= line[0]+line[1]+line[2];
		

		if(line[4]=="no"){
			while(!num_bag.empty())
			num_bag.pop();
			line.clear();
			continue;
		}
		int j=4;
		while(j<line.size()){
			string value=line[j]+line[j+1]+line[j+2];
			bag[key].push_back({num_bag.front(),value});
			num_bag.pop();
			j+=3;
		}
		while(!num_bag.empty()){
			cout<<"gatico"<<endl;
			num_bag.pop();
		}
		line.clear();
	}
	//map<string, vector<pair<int,string>>> bag;
	for(auto c:bag){
		cout<<c.first<<" ";
		for(auto v:c.second){
			cout<<v.first<<" "<<v.second<<endl;
		}
	}
	cout<<DFS("shinygoldbag")-1<<endl;
	

}





