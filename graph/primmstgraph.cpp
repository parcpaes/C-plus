#include <bits/stdc++.h>

using namespace std;
struct Edges{
	int to,from,weight;
	Edges(int source=0,int target=0, int w=0){
		from = source;
		to = target;
		weight = w;
	}
};
struct comp{
	bool operator()(const Edges& e1, const Edges& e2){
		return e1.weight < e2.weight;
	}
};
vector<Edges> adj[1000];
vector<Edges> edgeto(1000);
vector<int> disto(1000,9000000);
void primmst(int n){
	disto[0] = 0;
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> mst;
	vector<bool> marked(1000,false);
	mst.push(make_pair(disto[0],0));
	set<Edges,comp> treed;
	while(!mst.empty()){
		auto top = mst.top();
		mst.pop();
		int from = top.second;		
		marked[from] = true;
		for(auto edge: adj[from]){			
			int to = edge.to;
			int weight = edge.weight;
			if(marked[to]) continue;			
			if(weight < disto[to]){			
				disto[to] = weight;
				edgeto[to] = edge;
				mst.push({disto[to],to});
				treed.insert(Edges(from,to,weight));
				treed.insert(Edges(to,from,weight));
			}
		}
	}	
}

int main(){
	int a,b,weight,N,nedges;
	cin>>N;
	cin>>nedges;
	for(int i=0;i<nedges;i++){
		cin >> a >> b >> weight;
		adj[a].push_back(Edges(a,b,weight));
		adj[b].push_back(Edges(b,a,weight));		
	}
	primmst(N);
	return 0;
}
