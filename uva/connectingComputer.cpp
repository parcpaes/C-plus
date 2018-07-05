//908 mst kruskal
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> pairr;
int *parent;
int *size;
priority_queue<pairr,vector<pairr>, greater<pairr>> gmst;

void makeunion(int n){
	parent = new int[n+1];
	size = new int[n+1];
	for(int i=1;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}
}

int find(int p){
	while(parent[p]!=p){
		parent[p]=parent[parent[p]];
		p = parent[p];
	}
	return p;
}

bool unionset(int p, int q){
	int root1 = find(p);
	int root2 = find(q);
	if(root1 == root2) return false;
	if(size[root1]>size[root2]){
		parent[root2]=root1;
		size[root1]+=size[root2];
	}else{
		parent[root1] = root2;
		size[root2]+=size[root1];
	}
	return true;
}

int mstkruskal(int n){
	makeunion(n);
	int amount=0;
	while(!gmst.empty()){
		int v = gmst.top().second.first;
		int w = gmst.top().second.second;
		if(unionset(v,w)){
			int weight = gmst.top().first;
			amount += gmst.top().first;
		}
		gmst.pop();
	}
	return amount;
}

int main(){
	ios::sync_with_stdio(false);
	freopen("conected.txt","r",stdin);
	freopen("conectedout.txt","w",stdout);
	int n,k,m,x,y,weight, oldresult, newresult;
	int p=0;
	while(cin>>n){
		if(p)cout<<"\n";
		for(int i=0;i<n-1;i++){
			cin>>x>>y>>weight;
			gmst.push({weight,{x,y}});
		}
		oldresult = mstkruskal(n);		
		cin>>k;
		for(int i=0;i<k;i++){
			cin>>x>>y>>weight;
			gmst.push({weight,{x,y}});
		}
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>x>>y>>weight;
			gmst.push({weight,{x,y}});	
		}
		newresult = mstkruskal(n);
		cout<<oldresult<<"\n";
		cout<<newresult<<"\n";
		p++;		
	}
	return 0;
}