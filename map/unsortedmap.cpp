#include <bits/stdc++.h>

using namespace std;

int main(){
	unordered_map<int,int> maps;	
	maps.insert(make_pair(0,6));
	maps.insert(make_pair(1,4));	
	maps.insert(make_pair(2,2));
	maps.insert(make_pair(3,5));	
	for(auto it=maps.begin();it!=maps.end(); it++){
		cout<< it->first << " " << it->second <<"\n";
	}
	
	return 0;
}