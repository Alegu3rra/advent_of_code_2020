#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cctype>
#include <sstream>
#include <queue>
#include <set>
using namespace std;

map<string, vector<string>> bag;
vector <string>line;
queue<string>colita;
set<string>bags_shiny;


int main(){
	string datos;
	
	while(getline(cin, datos)){
		istringstream isstream(datos);
		while(!isstream.eof()){
			string tempStr;
			isstream >> tempStr;
			while(tempStr[tempStr.size()-1]=='s' or tempStr[tempStr.size()-1]==',' or tempStr[tempStr.size()-1]=='.' or isdigit(tempStr[tempStr.size()-1]))
				tempStr.pop_back();
			line.push_back(tempStr);
		}
		string key= line[0]+line[1]+line[2];
		string value;
		/*for(auto a: line)
			cout << " " << a;
		cout << " no mms"<<endl;*/
		int j=4;
		while(j<line.size()){
			value=line[j]+line[j+1]+line[j+2]+line[j+3];
			bag[value].push_back(key);
			j+=4;
		}
		line.clear();
	}
	/*for(auto x: bag){
		cout<<x.first<<"   ";
		for(int k=0; k<x.second.size();k++){
			cout<<x.second[k]<<" ";
		}
		cout<<endl;
	}*/
	string front;
	colita.push("shinygoldbag");
	while(!colita.empty()){
		front=colita.front();
		bags_shiny.insert(front);
		colita.pop();
		for(string nodo: bag[front]){
			colita.push(nodo);
		}
	}
	cout<<bags_shiny.size()-1<<endl;

}





