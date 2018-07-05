#include <bits/stdc++.h>

using namespace std;

int bsearch(vector<int>& array, int target){
	int left = 0, right= array.size()-1, mid=0;
	while(left<=right){
		mid = (left+right)>>1;
		if(target < array[mid]){
			right = mid - 1;
		}else if(target > array[mid]){
			left = mid + 1;
		}else{
			return mid;
		}
	}
	return -1;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
	set<int> setjoin;	
	int index;
	sort(nums2.begin(),nums2.end());
	for(auto it=nums1.begin();it!= nums1.end();it++){		
		index = bsearch(nums2,*it);
		if(index>=0 && *it == nums2[index]){
			setjoin.insert(*it);
		}
	}
	vector<int> result(setjoin.begin(),setjoin.end());
	return result;
}

int main(){
	vector<int> numbers1;
	numbers1.push_back(1);
	numbers1.push_back(0);	

	vector<int> numbers2;
	numbers2.push_back(0);
	
		
	vector<int> result;
	result = intersection(numbers1, numbers2);	
	for(auto it=result.begin();it!=result.end();it++){
		cout<< *it << " ";
	}
	return 0;
}
