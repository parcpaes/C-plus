#include <bits/stdc++.h>

using namespace std;

struct CentroidDecomposition{
	vector<set<int>> tree;
	vector<int> dad;
	vector<int> sub;

	CentroidDecomposition(vector<set<int>> &tree) : tree(tree){
		int n = tree.size();
		dad.resize(n);
		sub.resize(n);
		build(1,-1);
	}

	void build(int u,int p){
		int n = dfssize(u,p);
		int centroid = centroidTree(u,p,n);
		if(p == -1) p = centroid;
		dad[centroid] = p;
		for(auto v: tree[centroid]){
			tree[centroid].erase(v);
			tree[v].erase(centroid);
			build(v,centroid);
		}
	}
	int dfssize(int u,int p){
		sub[u]=1;
		for(auto v: tree[u]){
			if(v!=p) sub[u] += dfssize(v,u);
		}
		return sub[u];
	}
	int centroidTree(int u,int p, int n){
		for(auto v: tree[u]){
			if(v!=p && sub[v]>n/2) return centroidTree(v,u,n);			
		}
		return u;
	}
	int operator[](int i){
		return dad[i];
	}
};
int main(){
	vector<set<int>> tree;
	int n,N,a,b,ed;
	cin>>n>>ed;	
	tree.resize(n+1);
	while(ed--){
		cin>>a>>b;
		tree[a].insert(b);
		tree[b].insert(a);
	}
	cout << "end" << '\n';
	CentroidDecomposition centroid(tree);
	for(int i=0;i<tree.size();i++){
		cout << i<< " " << centroid[i] << '\n'; 
	}
	return 0;
}