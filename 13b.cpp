#include<bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}
long long ans, lcm;

vector<pair<long long,long long>> nums;
int main(){
	string dato;
	long long marca;
	long long indice=0;
	cin>>marca;
	while(getline(cin,dato,',')){
		if(dato!="x"){
			long long valor;
			string s = dato; 
			stringstream ss(s); 
			ss >> valor;
			long long temp = (2*valor-indice)%valor;
			nums.push_back({temp,valor});
		}
		indice++;
	}
	//teorema chino del residuo
	ans=nums[0].first;
	lcm=nums[0].second;
	for(long long v=1; v<nums.size();v++){
		auto pom = ex_GCD(lcm,nums[v].second);
		long long x1=pom.x;
		long long d=pom.d;
		if((nums[v].first-ans)%d!=0)return cerr <<"No soutions"<<endl,0;
		ans=normalize(ans+x1*(nums[v].first-ans)/d%(nums[v].second/d)*lcm,lcm*nums[v].second/d);
		lcm=LCM(lcm,nums[v].second);
	}
	cout<<ans<<" "<<lcm<<endl;
	for(auto x: nums){
		cout<<x.first<<" "<<x.second<<endl;
	}
}