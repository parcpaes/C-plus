#include <bits/stdc++.h>

using namespace std;

string reveser(string s){
	string r;
	string resul;
	for(int i=0;i<s.length();i++){
		if(s.at(i)==' '){
			resul+= r + s.at(i);
			r="";
		}else{
			r = s.at(i)+ r;
		}
	}
	resul+=r;
	return resul;
}

int main(){
	cout << reveser("Let's take LeetCode contest marcax");
	return 0;
}