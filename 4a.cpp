#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;
map <string, int> arr7= {{"ecl",0} , {"pid",0}, {"eyr",0}, {"hcl",0}, {"byr",0}, {"iyr",0}, {"eyr",0}, {"hgt",0}};
map <string, int> arr8= {{"ecl",0}, {"pid",0}, {"eyr",0}, {"hcl",0}, {"byr",0}, {"iyr",0}, {"eyr",0}, {"hgt",0}, {"cid",0}}; 
map <string, int> arr_in;

int main(){
	string datos;
	int contador=0;
	while(getline(cin,datos)){
		if(datos==""){
			if(arr7==arr_in or arr8==arr_in)
				contador++;
			arr_in.clear();
		}
		else{
			string str(datos);
			istringstream isstream(str);
			while(!isstream.eof()){
				string tempStr;
				isstream >> tempStr;
				tempStr = tempStr.substr(0,3);
				arr_in[tempStr]=0;	
			}
			
		}
	}
	cout<<contador<<endl;

}