#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1000];
bool visited[1000];
int colors[1000];
bool bfs(int s){
	queue<int> q;
	q.push(s);
	visited[s]=true;
	colors[s]=1;
	while(!q.empty()){
		int vertex = q.front();		
		q.pop();
		for(auto& value: adj[vertex]){			
			if(!colors[value]){
				q.push(value);			    
			    int c = (colors[vertex]==1)?2:1;
			    colors[value] = c;
			}else if(colors[vertex] == colors[value]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	memset(colors,0,sizeof(colors));
	int n;
	int v,w;
	cin>>n;
	while(n--){
		cin>>v>>w;
		adj[v].push_back(w);
		adj[w].push_back(v);	
	}
	cout << "\n"<< bfs(0);
	return 0;
}