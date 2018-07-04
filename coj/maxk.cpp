//3686
#include <bits/stdc++.h>

using namespace std;

vector<int> maxLsidingWindow(vector<int>& nums,int k){
	deque<int> dq;
	vector<int> res;
	for(int i=0;i< nums.size();i++){
		if(!dq.empty() && dq.front() == i-k){
			dq.pop_front();
		}
		while(!dq.empty() && nums[dq.back()] < nums[i]){
			dq.pop_back();	
		}
		dq.push_back(i);
		if(i>=k-1){
			res.push_back(nums[dq.front()]);
		}
	}
	return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t,n,k,vals;
    cin >> t;  
	vector<int> nums;
    while (t--){
    	nums.clear();
        cin>> n >> k;
        while(n--){
        	cin>> vals;
        	nums.push_back(vals);
        }
        vector<int> resul = maxLsidingWindow(nums,k);
        for(int i=0 ; i< resul.size();i++){        	
        	cout << resul[i];
        	if(i<resul.size()-1) cout<<" ";
        }
        cout <<"\n";
    }

    return 0;
}