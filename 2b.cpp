#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int valids=0;
	string param,char_to_str,str;	
	while(cin>>param>>char_to_str>>str){//lee
		
		int num=0;
		int j = 0;
		int params_sep[2];
		
		for(int i=0; i<param.size();i++){//busca nums params
			if(param[i]=='-'){
				params_sep[0]=num;
				num=0;
			}else{
				num= num*10+param[i]-'0';
			}
		}
		params_sep[1]=num;
		
		if(str[params_sep[0]-1]==char_to_str[0] xor str[params_sep[1]-1]==char_to_str[0])//cuenta validos
			valids++;
	}
	cout<<valids;
	return 0;
}