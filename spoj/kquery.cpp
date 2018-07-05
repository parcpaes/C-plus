#include <bits/stdc++.h>
#define ln(n) (n<<1)+1
#define rn(n) (n<<1)+2

using namespace std;

int n;
int data[30005];
vector<int> seg[30005<<2];
long long la;
void build(int node, int left, int right){
	if(left == right){		
		seg[node].push_back(data[left]);
		return;
	}
	int mid = (left + right)>>1;
	build(ln(node), left, mid);
	build(rn(node), mid+1, right);
	merge(seg[ln(node)].begin(), seg[ln(node)].end(), seg[rn(node)].begin(), seg[rn(node)].end(),back_inserter(seg[node]));
	
}

int query(int node, int left, int right, int i, int j, int v){
	if(i> right || j < left) return 0;
	if(i<=left && right<=j) return seg[node].size() - (upper_bound(seg[node].begin(),seg[node].end(), v)-seg[node].begin());	
	int mid = (left + right) >>1;	
	return query(ln(node), left, mid, i,j,v) + query(rn(node), mid+1, right, i, j, v);
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q,val,l,r,x;
	cin>>n;
	for(int i=0; i<n; i++){		
		cin>>val;
		data[i] = val;
	}
	build(0,0,n-1);	
	cin>>q;
	while(q--){		
		cin>>l>>r>>x;		
		cout<<query(0,0,n-1,l-1,r-1,x)<<endl;
	}
	return 0;
}