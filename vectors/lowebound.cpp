#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> vec = {1,6,8,9};
	cout << *lower_bound(vec.begin(),vec.end(),7) << "\n";
	cout << *upper_bound(vec.begin(),vec.end(),1) << "\n";
	return 0;
}