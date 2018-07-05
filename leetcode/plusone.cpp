#include <bits/stdc++.h>

using namespace std;
vector<int> plusOne(vector<int>& digits){	
	auto r = digits.rbegin();
	int carry = 1;
	while(r != digits.rend() && carry){
		*r = (*r + carry)%10;
		carry = (*r == 0) ? 1 : 0;
		r++;
	}
	if(carry) digits.insert(digits.begin(), carry);	
}
int main(){
	vector<int> array;
	array.push_back(9);
	array.push_back(9);
	array.push_back(9);	
	array = plusOne(array);
	for(auto it = array.begin(); it!=array.end();it++){
		cout<< *it<<" ";
	}

	return 0;
}