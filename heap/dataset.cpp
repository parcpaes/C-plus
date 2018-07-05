#include <bits/stdc++.h>

using namespace std;

int main(){
	set<int> call;
	call.insert(4);
	call.insert(10);
	call.insert(9);
	call.insert(5);
	for(auto it = call.begin(); it!=call.end(); it++){
		cout << *it << " ";
	}
	return 0;
}