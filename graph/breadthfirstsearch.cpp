#include <bits/stdc++.h>

using namespace std;

bool visited[100];
int level[100];
vector<int> adj[100];

void bfs(int s){
	queue<int> q;
	q.push(s);
	visited[s] = true;
	level[0]=0;

	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i=0;i<adj[v].size();i++){
			if(!visited[adj[v][i]]){
				q.push(adj[v][i]);
				level[adj[v][i]] = level[v] +1;
				visited[adj[v][i]] = true;
			}
		}
	}
}

int main(){
	return 0;
}