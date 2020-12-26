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
		int aux=0;
		for(int i=0; i<str.size();i++){//cuenta letras
			if(str[i]==char_to_str[0])
				aux++;
		}
		
		if(params_sep[0]<=aux and params_sep[1]>=aux)//cuenta validos
			valids++;
	}
	cout<<valids;
	return 0;
}