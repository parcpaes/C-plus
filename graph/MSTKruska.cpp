#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int,int>>> graphMst;
struct DisjoinSets
{
	int *parent, *size;
	int n,components;
	DisjoinSets(int n){
		this->n = n;
		this->components=n;
		parent = new int[n];
		size = new int[n];
		for(int i=0;i<n;i++){
			parent[i]=i;
			size[i]=1;
		}
	}

	int find(int p){
		while(p!=parent[p]){
			parent[p] = parent[parent[p]];
			p = parent[p];
		}
		return p;
	}

	bool unionset(int p, int q){
		int root1 = find(p);
		int root2 = find(q);
		if(find(root1) == find(root2)) return false;
		if(size[root1]>size[root2]){
			parent[root2]=root1;
			size[root1]+=size[root2];
		}else{
			parent[root1]=root2;
			size[root2]+=size[root1];
		}
		components--;
		return true;
	}
};

int mstkruskal(int n){
	int mstweight=0;
	sort(graphMst.begin(),graphMst.end());
	DisjoinSets disjoin(n);

	for(auto& it: graphMst){
		int u= it.second.first;
		int v= it.second.second;
		if(disjoin.unionset(u,v)){
			cout << u << "-" << v << "\n";
			mstweight += it.first;			
		}
	}
	return mstweight;
}

int main(){
	graphMst.push_back({4, {0, 1}});
	graphMst.push_back({8, {0, 7}});
	graphMst.push_back({8, {1, 2}});
	graphMst.push_back({11,{1, 7}});
	graphMst.push_back({7, {2, 3}});
	graphMst.push_back({2, {2, 8}});
	graphMst.push_back({4, {2, 5}});
	graphMst.push_back({9, {3, 4}});
	graphMst.push_back({14,{3, 5}});
	graphMst.push_back({10,{4, 5}});
	graphMst.push_back({2, {5, 6}});
	graphMst.push_back({1, {6, 7}});
	graphMst.push_back({6, {6, 8}});
	graphMst.push_back({7, {7, 8}});

	cout << "mst "<< mstkruskal(9);

	return 0;
}