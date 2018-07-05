#include <bits/stdc++.h>

using namespace std;

int visited[100001];
vector<int> adj[100001];
int dist[100001];
int amount=0;

void bfs(int s, int t){
	queue<int> q;
	q.push(s);
	visited[s]=1;
	amount = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i=0;i<adj[v].size();i++){			
			if(!visited[adj[v][i]]){
				q.push(adj[v][i]);
				visited[adj[v][i]] = 1;
				dist[adj[v][i]] = dist[v]+1;
				if(dist[adj[v][i]] == t) amount = amount+1;
				if(dist[adj[v][i]] > t) break;
			}
		}
	}
}

int main(){
	int node,edge,u,v,querys,t;
	cin>> node >> edge;	
	for(int i=0;i<edge;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cin>>querys;
	while(querys--){
		cin>>node>>t;
		bfs(node,t);
		cout<<amount<<"\n";
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));
	}

	return 0;
}