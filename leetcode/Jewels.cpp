#include <bits/stdc++.h>

using namespace std;

int numJewelsInStones(string J, string S){
	string resul = regex_replace(S, regex("[^"+J+"]"),"");
	return resul.length();
}

int main(){
	cout<< numJewelsInStones("aA","aAAbbAbbaA");
	return 0;
}