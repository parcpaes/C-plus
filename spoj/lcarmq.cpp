#include <bits/stdc++.h>

using namespace std;
vector<int> euler;
vector<int> previndex;
int indexs[1001];
int table[2000][1001];
void sparseTable(vector<int> &array){
	int maxk, n = array.size();
	maxk =  31-(__builtin_clz(n));
	for(int i=0;i<n;i++) table[0][i] = array[i];
	for(int k=1;k<=maxk;k++){
		for(int j=0;j+(1<<k)<=n;j++){
			table[k][j]=min(table[k-1][j],table[k-1][j+(1<<(k-1))]);
		}
	}
}
int querymin(int a,int b){
	int len = b-a+1;
	int k = 31-(__builtin_clz(len));
	int m = b-(1<<k)+1;	
	return min(table[k][a],table[k][m]);
}
void dfseuler(vector<vector<int>> &adj,int v,int u){
	int newindex = previndex.size();
	previndex.push_back(v);
	indexs[v] = euler.size();
	euler.push_back(newindex);
	for(auto w:adj[v]){
		if(w!=u){
			dfseuler(adj,w,v);
			euler.push_back(newindex);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nt,N,M,a,b,Q;
	cin>>nt;
	for(int i=1;i<=nt;i++){
		cin>>N;
		vector<vector<int>> adj(N);
		for(int x=0;x<N;x++){
			cin>>M;
			while(M--){
				cin >> a;
				adj[x].push_back(a-1);
				adj[a-1].push_back(x);
			}
		}		
		dfseuler(adj,0,-1);
		sparseTable(euler);
		cin>>Q;
		cout <<"Case "<< i << ":\n";
		while(Q--){
			cin>>a>>b;
			a = indexs[a-1];
			b = indexs[b-1];
			if(a>b) swap(a,b);
			cout << previndex[querymin(a,b)]+1 << '\n';
		}
		euler.clear();
		previndex.clear();
	}
	return 0;
}