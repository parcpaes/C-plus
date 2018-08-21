#include <bits/stdc++.h>

using namespace std;

bool visited[1002];
vector<int> adj[1002];
int ranks[1002];
void dfs(int s){
	visited[s] = true;	
	for(int i=0;i<adj[s].size(); i++){	
		if(!visited[adj[s][i]]){			
			ranks[adj[s][i]] = ranks[s]+1;
			dfs(adj[s][i]);
		}	
	}
}

int main(){
	int n,q,u,v,girl;
	set<pair<int,int>> setgirls;
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>girl;
		setgirls.insert(make_pair(ranks[girl],girl));
	}
	auto it = setgirls.begin();
	cout<< it->second << "\n";
	return 0;
}