#include <bits/stdc++.h>

using namespace std;

unsigned long long tree[100000<<2];
unsigned long long lazy[100000<<2];

void update(int node, int left,int right, int i, int j, unsigned long long value){
	
	if(lazy[node]!=0){
		tree[node] += (right - left+1)*lazy[node];
		if(left!=right){
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(i>right || j<left) return;
	if(i<= left && right<=j){
		tree[node] += (right-left+1)*value;
		if(left!=right){
			lazy[node<<1] += value;
			lazy[node<<1|1] += value;
		}
		return;
	}

	int mid = (left+right)>>1;
	update(node<<1, left, mid, i,j, value);
	update(node<<1|1, mid+1,right, i, j, value);
	tree[node] = tree[node<<1] + tree[node<<1|1];
}

unsigned long long query(int node, int left, int right, int i, int j){	
	if(lazy[node]!=0){
		tree[node] += (right-left+1)*lazy[node];
		if(left!= right){
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}
		lazy[node] = 0;		
	}
	if(i> right || j<left) return 0;
	if(i<=left && right<= j) return tree[node];

	int mid = (left+right)>>1;
	unsigned long long p = query(node<<1, left, mid, i, j);
	unsigned long long q = query(node<<1|1, mid+1, right, i, j);
	return (p+q);
}

int main(){
	int t, n, c, p,q,v,x;

	while(cin>>t){
		while(t--){			
			memset(lazy, 0, sizeof(lazy));
			memset(tree, 0, sizeof(tree));
			cin >> n >> c;
			while(c--){
				cin >> x;
				if(x){
					cin >> p >> q;
					cout << query(1, 0, n-1,p-1,q-1) << "\n";
				}else{
					cin >> p >> q >> v;
					update(1, 0 , n-1, p-1, q-1, v);
				}
			}			
		}
	}
	return 0;
}