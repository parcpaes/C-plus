#include <bits/stdc++.h>

using namespace std;

vector<int> euler;
vector<int> previndex;
int indexs[1000002];
int table[50][1000002];
int mini[50][1000002];
int maxi[50][1000002];
int par[50][1000002];
int depth[1000002];
void sparseTable(vector<int> &array,int nx, int D){
	int maxk, n = array.size();
	maxk = maxk =  31-(__builtin_clz(n));
	for(int i=0;i<n;i++)table[0][i]=array[i];
	for(int k=1;k<=maxk;k++){
		for(int j=0;j+(1<<k)<=n;j++){
			if(k<=D && j<nx){
				int mid = par[k-1][j];
				if(mid!=-1){
					par[k][j] = par[k-1][mid];
                    mini[k][j]=min(mini[k-1][j],mini[k-1][mid]);
                    maxi[k][j]=max(maxi[k-1][j],maxi[k-1][mid]);
				}
			}					
			table[k][j] = min(table[k-1][j], table[k-1][j+(1<<(k-1))]);
		}
	}
}

int querymin(int a, int b){
	int len = b-a+1;
	int k = 31-(__builtin_clz(len));
	int m = b-(1<<k)+1;
	return min(table[k][a],table[k][m]);
}

void dfseuler(vector<vector<pair<int,int>>> &adj,int v,int u,int h){
	depth[v] = h;
	int newindex = previndex.size();
	previndex.push_back(v);
	indexs[v]=euler.size();
	euler.push_back(newindex);
	for(auto &w:adj[v]){
		if(w.first!=u){
			maxi[0][w.first] = mini[0][w.first]= w.second;
			par[0][w.first] = v;
			dfseuler(adj,w.first,v,h+1);
			euler.push_back(newindex);
		}
	}
}
pair<int,int> walk(int j,int k,int D){
	int maxn=-1;
	int minx=1000005;	
	for(int d=0;d<=D && j!=-1;d++){
		if(((1<<d)&k)>0){
			minx = min(minx,mini[d][j]);
			maxn = max(maxn,maxi[d][j]);
			j = par[d][j];
		}
	}
	return {minx,maxn};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,K,a,b,weigth,lca,left,right,D,nx;	
	while(cin>>N){
		vector<vector<pair<int,int>>> adj(N);
		D = 31-(__builtin_clz(N));
		nx = N;
		N = N-1;		
		while(N--){
			cin>>a>>b>>weigth;
			adj[a-1].push_back({b-1,weigth});
			adj[b-1].push_back({a-1,weigth});
		}
		for(int d=0;d<=D;d++){
            for(int j=0;j<nx;j++){
                par[d][j]=-1;
                mini[d][j]=1000005;
                maxi[d][j]=-1;
            }
        }
        dfseuler(adj,0,-1,0);
		sparseTable(euler,nx,D);
		cin>>K;		
		while(K--){
			cin>>a>>b;
			a--;b--;
			left = indexs[a];
			right = indexs[b];
			if(left>right) swap(left,right);
			lca = previndex[querymin(left,right)];					
			pair<int,int> minmaxA = walk(a,depth[a]-depth[lca],D);
			pair<int,int> minmaxB = walk(b,depth[b]-depth[lca],D);
			cout << min(minmaxA.first,minmaxB.first) <<" "<< max(minmaxA.second,minmaxB.second) << '\n';
		}
		euler.clear();
		previndex.clear();		
	}
	return 0;
}
