#include <bits/stdc++.h>

using namespace std;
vector<int> adj[100];
int parent[100];

int find(int x){
	while(x!=parent[x]){
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}
int lca(int a, int b){
	if(parent[a]== parent[b]) return parent[a];
}
void dfs(int v,int w){	
	for(auto u: adj[v]){
		if(u!=w){
			parent[u] = v;
			dfs(u,v);
		}
	}
}
int main(){
	for(int i=0;i<8;i++) parent[i]=i;
	int n = 7,a,b;
	while(n--){
		cin>> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0,-1);	
	while(true){
		cin >> a >>b;		
		cout << lca(a,b) << '\n';
	}
	return 0;
}