#include <bits/stdc++.h>

using namespace std;

#define oo 100000000
#define ROSE 1
#define BLUE 0

vector<int> *tree;
int color[100005];

int query(int u,int p){
	if(color[u] == ROSE) return 0;
	int mn = oo;
	for(auto v: tree[u]){		
		if(v!=p){
			mn = min(mn, query(v,u)+1);
		}		
	}
	return mn;
}

void update(int a){
	color[a] = ROSE;
}

int main(){
	int n,m,a,b,t,vi;
	while(cin>>n>>m){
		tree = new vector<int>[100005];
		n=n-1;
		while(n--){
			cin>>a>>b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		memset(color,0,n+1);
		color[1]=1;
		while(m--){
			cin>>t>>vi;
			if(t == 1){
				update(vi);
			}else{
				cout << query(vi,-1) << "\n";
			}
		}
	}
	return 0;
}