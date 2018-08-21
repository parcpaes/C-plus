#include <bits/stdc++.h>

using namespace std;

struct Edges{
	int from, to;
	int weight;
	Edges(int s=0, int t=0, int w=0){
		from = s;
		to = t;
		weight= w;
	}
};

vector<Edges> adj[1000];
vector<Edges> edgeto(1000);
vector<int> disto(1000,900000000);

void dijkstra(int start){
	disto[start]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minq;
	minq.push(make_pair(disto[start],start));	
	while(!minq.empty()){
		auto top = minq.top();
		minq.pop();
		int from = top.second;				
		for(auto& vertex:adj[from]){
			int to = vertex.to;
			int weight = vertex.weight;									
			if(weight+disto[from] < disto[to]){				
				disto[to]=weight+disto[from];				
				minq.push(make_pair(disto[to],to));
				edgeto[to]=vertex;
			}			
		}
	}
}

int main(){
	adj[0].push_back(Edges(0,1,4));
	adj[0].push_back(Edges(0,3,2));
	adj[1].push_back(Edges(1,2,6));
	adj[2].push_back(Edges(2,3,-9));

	dijkstra(0);

	for(int i=0;i<4;i++){
		cout<< disto[i] << "\n";
	}

	return 0;
}