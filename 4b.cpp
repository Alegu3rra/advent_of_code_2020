#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;
map <string, int> arr7= {{"ecl",0} , {"pid",0}, {"eyr",0}, {"hcl",0}, {"byr",0}, {"iyr",0}, {"eyr",0}, {"hgt",0}};
map <string, int> arr8= {{"ecl",0}, {"pid",0}, {"eyr",0}, {"hcl",0}, {"byr",0}, {"iyr",0}, {"eyr",0}, {"hgt",0}, {"cid",0}}; 
string ecl_test[7] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
map <string, int> arr_key;
map <string, string> arr_value;


int main(){
	string datos;
	int tempcon = 0;
	int contador=0;
	while(getline(cin,datos)){
		if(datos==""){
			if(arr7==arr_key or arr8==arr_key){
			
				for (auto x: arr_value) {					
					cout<<x.first<<" : "<<x.second<<endl;
					if(x.first=="byr"){
						string s = x.second; 
						stringstream ss(s);
						int val=0;
						ss >> val;
						if(1920<=val and 2002>=val)
							tempcon++;
					}
					if(x.first=="iyr"){
						string s = x.second; 
						stringstream ss(s);
						int val=0;
						ss >> val;
						if(2010<=val and 2020>=val)
							tempcon++;
						
					}
					if(x.first=="eyr"){
						string s = x.second; 
						stringstream ss(s);
						int val=0;
						ss >> val;
						if(2020<=val and 2030>=val)
							tempcon++;
					}
					if(x.first=="hgt"){
						string s = x.second;
						string temps;
						temps.push_back(s[s.size()-2]);
						temps.push_back(s[s.size()-1]);
						s = s.substr(0,sizeof(s)-2);
						stringstream ss(s);
						int val=0;
						ss >> val;
						if(temps=="cm" and val>=150 and val<=193){
							tempcon++;
						}
						if(temps=="in" and val>=59 and val<=76){
							tempcon++;
						}
					}
					if(x.first=="hcl"){
						string s = x.second; 
						int a=1;
						while((s[a]>='a' and s[a]<='f' or s[a]>='0' and s[a]<='9') and a<sizeof(s)){
							a++;					
						}
						if(a==7)
							tempcon++;
					}
					if(x.first=="ecl"){
						for(int a=0; a<sizeof(ecl_test);a++){
							if(x.second==ecl_test[a])
								tempcon++;
						}
					}
					if(x.first=="pid"){
						if(x.second.size()==9)
							tempcon++;
						
					}
					if(x.first=="cid"){
						//ignorado, faltante o no.
					}
				}
				cout<<tempcon<<endl;
				if(tempcon==7)
					contador++;
				tempcon=0;
			}
			arr_key.clear();
			arr_value.clear();
			
		}
		else{
			string str(datos);
			istringstream isstream(str);
			while(!isstream.eof()){
				string tempStr;
				string tempStr_key;
				string tempStr_value;
				isstream >> tempStr;
				tempStr_key = tempStr.substr(0,3);
				tempStr_value = tempStr.substr(4, sizeof(tempStr));
				arr_key[tempStr_key]=0;
				arr_value[tempStr_key]=tempStr_value;
				
			}
			
		}
	}
	cout<<contador<<endl;

}