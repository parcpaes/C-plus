#include <bits/stdc++.h>

using namespace std;

int visited[100002<<1];
int id[100002<<1];
map<int,int> size;
vector<int> adj[100002<<1];

void dfs(int s,int comp){		
	visited[s] = 1;
	id[s] = comp;	
	for(int i=0;i<adj[s].size();i++){
		if(!visited[adj[s][i]]) dfs(adj[s][i],comp);	
	}
}

void inicialize(int nodes){
	memset(visited,0,sizeof(visited));
	memset(id,0,sizeof(id));
	size.clear();
	for(int i=0;i<nodes;i++){
		adj[i].clear();
	}
}

int main(){
	int n,form,cont=0,aux,countcomp;
	string friend1, friend2;
	map<string,int> mapfriend;
	cin>>n;
	while(n--){
		cin>>form;
		cont = 0;
		countcomp=0;
		aux=0;
		inicialize(form<<1);		
		while(form--){
			cin>>friend1>>friend2;
			int valueA = mapfriend[friend1];
			int valueB = mapfriend[friend2];			
			if(!mapfriend[friend1]){
				valueA = cont;
				mapfriend[friend1]= cont++;
			}
			if(!mapfriend[friend2]){
				valueB = cont;
				mapfriend[friend2]= cont++;				
			}
			adj[valueA].push_back(valueB);
			adj[valueB].push_back(valueA);
			
			if((!visited[valueA]) && (!visited[valueB])){								
			 	countcomp++;
			}
			if(!visited[valueA]){
				dfs(valueA,aux);
			}else if(!visited[valueB]){
				dfs(valueB,aux);
			}
			cout << size[id[valueA]] <<"\n";
		}
	}
	return 0;
}
