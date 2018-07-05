#include <bits/stdc++.h>

using namespace std;

char nextGreaterLetter(vector<char> &letters, char target){
	auto it = unique(letters.begin(),letters.end());
	letters.erase(it, letters.end());	

	int left = 0, right = letters.size()-1, mid = 0;

	while(left < right){
		mid = (left+right)>> 1;
		if(target <= letters[mid]) right = mid;
		else left = mid + 1;
	}

	if(target>=letters[left]) return letters[(left+1)%letters.size()];
	return letters[left];	
}

int main(){
	vector<char> letters;	
	letters.push_back('e');
	letters.push_back('e');	
	letters.push_back('e');	
	letters.push_back('e');
	letters.push_back('e');	
	letters.push_back('e');	
	letters.push_back('e');	
	letters.push_back('n');	
	letters.push_back('n');	
	letters.push_back('n');	
	letters.push_back('n');	
	//auto it = upper_bound(letters.begin(),letters.end(),'z');
	//cout<< it - letters.begin();]
	char lr;
	nextGreaterLetter(letters, lr);
	while(true){
		cin>>lr;
		cout<< nextGreaterLetter(letters, lr)<< "\n";
	}	
	return 0;
}