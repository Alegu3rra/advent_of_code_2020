#include <iostream>
#include <cstring>
#include <sstream> 
#include <math.h> 
#include <math.h> 
#include <cstdlib>
#define PI 3.141592653589793

using namespace std;

float radians(float ang){
	return ang*PI/180;
}
pair<float,float> rotate(pair<float,float>origen, pair<float,float>coord, float radian){
	float orx=origen.first, ory=origen.second;
	float cox=coord.first, coy=coord.second;
	float resx=orx+cos(radian)*(cox-orx)-sin(radian)*(coy-ory);
	float resy=ory+sin(radian)*(cox-orx)+cos(radian)*(coy-ory);
	
	return {round(resx),round(resy)};
}

int main(){
	string dato;
	string accion;
	float valor;
	pair<float,float>coord={0.0,0.0};
	pair<float,float>waypoint={10.0,1.0};
	while(cin>>dato){
		/*leer dato*/
		accion=dato[0];
		string s = dato.substr(1); 
		stringstream ss(s); 
		ss >> valor;
		if(accion=="N"){
			//norte
			waypoint.second+=valor;
		}
		else if(accion=="S"){
			//sur
			waypoint.second-=valor;
		}
		else if(accion=="E"){
			//este
			waypoint.first+=valor;
		}
		else if(accion=="W"){
			//oeste
			waypoint.first-=valor;
		}
		else if(accion=="R" or accion=="L"){
			//gira der o izq
			if(accion=="R")
				valor*=-1;
			waypoint=rotate({0.0,0.0},waypoint,radians(valor));
		}
		else if(accion=="F"){
			//avanza
			coord.second+=waypoint.second*valor;
			coord.first+=waypoint.first*valor;
		}
		cout<<accion<<" "<<valor<<endl;
		cout<<coord.first<<" "<<coord.second<<endl;
		cout<<waypoint.first<<" "<<waypoint.second<<endl;
	}
	cout<<abs(coord.first)+abs(coord.second);
	
}