//sending email 10986 uva dijkstra
#include <bits/stdc++.h>

using namespace std;
#define INF 2000000000
struct Edges{
	int from,to,weight;
	Edges(int s=0, int t=0,int w=0){
		from = s;
		to = t;
		weight = w;
	}
};


vector<int> disto(20002,INF);

void sortestpath(int s,vector<Edges> *adj){
	set<pair<int,int>> minq;
	disto[s]=0;
	minq.insert(make_pair(disto[s],s));
	while(!minq.empty()){

		auto top = *minq.begin();
		minq.erase(minq.begin());
		int from = top.second;

		for(auto& vertex: adj[from]){
			int to = vertex.to;
			int weight = vertex.weight;
			if(weight+disto[from]<disto[to]){
				if(disto[to]!=INF) minq.erase(minq.find(make_pair(disto[to],to)));

				disto[to] = weight+disto[from];
				minq.insert(make_pair(disto[to],to));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("inputEmail.txt","r",stdin);
	freopen("outputEmail.txt","w",stdout);
	int N,nodes,m,source,target;
	int u,v,w;
	cin>>N;	
	for(int i=0;i<N;i++){		
		cin>>nodes>>m>>source>>target;
		vector<Edges> *adj = new vector<Edges>[nodes];
		
		while(m--){
			cin>>u>>v>>w;
			adj[u].push_back(Edges(u,v,w));
			adj[v].push_back(Edges(v,u,w));
		}
		sortestpath(source,adj);		
		if(disto[target]!=INF){
			cout<< "Case #"<<(i+1)<<": "<< disto[target] <<"\n";
		}else{
			cout<< "Case #"<<(i+1)<<": unreachable"<<"\n";
		}
		
		fill(disto.begin(),disto.begin()+nodes,INF);			
	}
	return 0;
}
