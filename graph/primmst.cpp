#include <bits/stdc++.h>

using namespace std;

struct Edges{
	int from, to;
	int weight;
	Edges(int s=0, int t=0, int w=0){
		from = s;
		to = t;
		weight=w;
	}
};

vector<Edges> adj[1000];
vector<int> disto(1000,900000000);
vector<Edges> edgeto(1000);

void primMST(){
	set<pair<int,int>> minq;
	vector<bool> marked(1000,false);
	disto[0]=0;
	minq.insert(make_pair(disto[0],0));
	while(!minq.empty()){
		auto top = *minq.begin();
		minq.erase(minq.begin());
		int from = top.second;
		marked[from]=true;		
		for(auto& edge: adj[from]){
			int to = edge.to;
			int weight = edge.weight;
			if(marked[to]) continue;			
			if(weight < disto[to]){
				if(disto[to]!=900000000) minq.erase(minq.find({disto[to],to}));
				disto[to] = weight;
				minq.insert(make_pair(disto[to],to));
				edgeto[to]= edge;
			}
		}
	}
}

void addEdge(int s, int t,int weight){
	adj[s].push_back(Edges(s, t, weight));
	adj[t].push_back(Edges(t, s, weight));
}

int main(){
	int v=8;

	addEdge(0, 7, 16);
    addEdge(2, 3, 17);
    addEdge(5, 7, 28);
    addEdge(1, 7, 19);
    addEdge(0, 2, 26);
    addEdge(4, 5, 35);
    addEdge(1, 3, 29);
    addEdge(1, 5, 32);
    addEdge(2, 7, 34);
    addEdge(1, 2, 36);
    addEdge(3, 6, 52);
    addEdge(6, 2, 40);
    addEdge(4, 7, 37);
    addEdge(0, 4, 38);
    addEdge(6, 4, 93);
    addEdge(6, 0, 58);
	primMST();
    for(int i=1;i<v;i++){
    	//cout << edgeto[i].from << "  to " << edgeto[i].to  << " w " << edgeto[i].weight << "\n";
    }
	return 0;
}