#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main(){
	string datos;
	int ID_great=0;
	while(getline(cin,datos)){
		int ID=0;
		float fila_first=0;
		float fila_end=127;
		float fila=0;
		float column_first=0;
		float column_end=7;
		float column=0;
		float i=0;
		while(i<11 and fila_first<fila_end){
			if(datos[i]=='F'){
				fila_end=(fila_end+fila_first)/2;
				fila=floor(fila_end);
			}
			if(datos[i]=='B'){
				fila_first=(fila_end+fila_first)/2;
				fila=ceil(fila_first);
			}
			if(datos[i]=='R'){
				column_first=(column_end+column_first)/2;
				column=ceil(column_first);
				
			}
			if(datos[i]=='L'){
				
				column_end=(column_end+column_first)/2;
				column=floor(column_end);
			}
			i++;
		}
		ID=fila*8+column;
		
		if(ID>ID_great)
			ID_great=ID;
		
	}
	cout<<ID_great<<endl;
}