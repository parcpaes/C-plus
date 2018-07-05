#include <bits/stdc++.h>

using namespace std;

vector<int> twosum(vector<int>& nums, int target){
	map<int,int> mapnum;
	for(int i=0;i<nums.size(); i++){
		int complement = target - nums[i];
		if(mapnum.find(complement) != mapnum.end()){
			return vector<int>({mapnum[complement],i});
		}
		mapnum.insert(make_pair(nums[i],i));
	}
}

int main(){
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(12);
	nums.push_back(11);
	nums.push_back(15);
	nums.push_back(7);
	nums = twosum(nums,9);
	cout<< nums[0]<< " "<< nums[1];
	return 0;
}
