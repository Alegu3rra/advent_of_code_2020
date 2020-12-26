#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream> 
#include <math.h> 
#include <cstdlib>
#define PI 3.141592653589793

using namespace std;

int main(){
	string dato;
	string accion;
	int valor;
	int ang=0;
	pair<int,int>coords={0.0,0.0};
	while(cin>>dato){
		/*leer dato*/
		accion=dato[0];
		string s = dato.substr(1); 
		stringstream ss(s); 
		ss >> valor;
		if(accion=="N"){
			//norte
			coords.second+=valor;
		}
		else if(accion=="S"){
			//sur
			coords.second-=valor;
		}
		else if(accion=="E"){
			//este
			coords.first+=valor;
		}
		else if(accion=="W"){
			//oeste
			coords.first-=valor;
		}
		else if(accion=="R" or accion=="L"){
			if(accion=="R"){
				//gira der
				int temp=ang-valor;
				if(temp<0)
					temp+=360;
				ang=temp%360;
			}else{
				//gira izq
				int temp=ang+valor;
				ang=temp%360;
				
			}			
		}
		else if(accion=="F"){
			//avanza
			if(ang==90)
				coords.second+=valor;
			else if(ang==180)
				coords.first-=valor;
			else if(ang==270)
				coords.second-=valor;
			else if(ang==0)
				coords.first+=valor;
			
		}
		cout<<accion<<" "<<valor<<endl;
		cout<<coords.first<<" "<<coords.second<<" "<<ang<<endl;
	}
	cout<<abs(coords.first)+abs(coords.second);
	
}