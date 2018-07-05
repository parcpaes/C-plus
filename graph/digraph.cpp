#include <bits/stdc++.h>

using namespace std;

int visited[100];
vector<int> adj[100];
int edgeto[100][100];
int distto[100][100];

void findParent(int p,int source){	
	while(p != source){	
		cout << p << " - ";
		p = edgeto[source][p];		
	}
}

void bfs(int s){
	queue<int>  q;
	q.push(s);
	visited[s] = 1;
	distto[s][s] = 0;
	int vertex;	
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i=0;i<adj[v].size(); i++){
			vertex = adj[v][i];
			if(!visited[vertex]){
				q.push(vertex);
				visited[vertex] = 1;
				distto[s][vertex] = distto[s][v]+1;
				edgeto[s][vertex] = v;
			}
		}
	}
}

int main(){

	adj[0].push_back(5);
	adj[0].push_back(1);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(5);
	adj[3].push_back(2);
	adj[4].push_back(3);
	adj[4].push_back(2);
	adj[5].push_back(4);
	adj[6].push_back(9);
	adj[6].push_back(4);
	adj[6].push_back(8);
	adj[6].push_back(0);
	adj[7].push_back(6);
	adj[7].push_back(9);
	adj[8].push_back(6);
	adj[9].push_back(11);
	adj[9].push_back(10);
	adj[10].push_back(12);
	adj[11].push_back(4);
	adj[11].push_back(12);
	adj[12].push_back(9);


	bfs(1);
	memset(visited,0,sizeof(visited));
	bfs(7);
	memset(visited,0,sizeof(visited));
	bfs(10);
	
	findParent(2,10);

	return 0;
}