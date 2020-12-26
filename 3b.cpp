#include <iostream>
#include <string>
#include <vector>

using namespace std;

string mapa;
long long it1=0;
long long tr1=0;
long long one_one(){
	if(mapa[it1]=='#'){
		tr1++;
	}
	it1 = (it1+1)%mapa.size();
	return tr1;
}
long long it2=0;
long long tr2=0;
long long three_one(){
	if(mapa[it2]=='#'){
		tr2++;
	}
	it2 = (it2+3)%mapa.size();
	return tr2;
}
long long it3=0;
long long tr3=0;
long long five_one(){
	if(mapa[it3]=='#'){
		tr3++;
	}
	it3 = (it3+5)%mapa.size();
	return tr3;
}
long long it4=0;
long long tr4=0;
long long seven_one(){
	if(mapa[it4]=='#'){
		tr4++;
	}
	it4 = (it4+7)%mapa.size();
	return tr4;
}
long long it5=0,j=0;
long long tr5=0;
long long one_two(){
	if(j%2==0){
		if(mapa[it5]=='#'){
			tr5++;
		}
		it5 = (it5+1)%mapa.size();
	}
	j++;
	return tr5;
}

int main(){
	while(getline(cin, mapa)){
		one_one();
		three_one();
		five_one();
		seven_one();
		one_two();
	}
	long long res=tr1*tr2*tr3*tr4*tr5;
	cout<<res;
	return 0;
}