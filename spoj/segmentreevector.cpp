#include <bits/stdc++.h>
#define ln(n) (n<<1)
#define rn(n) (n<<1|1)

using namespace std;


int n;
int data[100001];
vector<int> va;
vector<int> seg[100001<<2];

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
	if(i>right || j < left) return 0;
	if(i<=left && right<=j){
		int k = upper_bound(seg[node].begin(),seg[node].end(), v)-seg[node].begin();		
		return k;
	}
	int mid = (left + right) >>1;
	int p = query(ln(node), left, mid, i,j,v);
	int q = query(rn(node), mid+1, right, i, j, v);	
	return (p+q);
}


int main(){
	int q;
	//1 2 5 8 3 7 8
	scanf("%d %d", &n, &q);
	for(int i =1; i<= n; i++){
		scanf("%d",&data[i]);
		va.push_back(data[i]);
	}
	sort(va.begin(), va.end());
	for(int i=1; i<=n; i++){		
		data[i] = lower_bound(va.begin(), va.end(), data[i]) - va.begin()+1;		
	}	
	for(int i=1; i<=n; i++){
		cout << data[i] << " ";
	}	
	build(1,1,n);
	cout << "\n";
	/*for(int i=1; i<(n<<1)+4;i++){
		cout <<  i <<" ";
		for(int j=0; j<seg[i].size();j++){
			cout << seg[i][j]<< " ";
		}
		cout << "\n";
	}*/
	while(q--){
		int l,r,x;
		scanf("%d %d %d", &l, &r, &x);
		int low = 1, high=n, mid, ans;
		while(low<=high){
			mid = (low+high)>>1;

			int k = query(1,1,n,l,r,mid);
			cout << "m " << mid << " k "<< k <<"\n";
			if(x<=k){
				ans = mid;
				high = mid-1;
			}else{
				low = mid+1;
			}
		}
		printf("%d\n", va[ans-1]);
	}
	cout <<"--";
	return 0;
}