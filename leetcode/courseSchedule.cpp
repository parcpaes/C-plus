//207
#include <bits/stdc++.h>

using namespace std;

map<int,bool> visited;        
map<int,bool> previsit;
bool cycle;
bool dfs(int v,vector<unordered_set<int>> &adj){    
    visited[v] = true;
    previsit[v] = true;
    for(auto& p:adj[v]){
        if(previsit[p]){
            return false;   
        }else if(!visited[p]){
        	cycle = dfs(p,adj);
        }
    }
    previsit[v]=false;
    return cycle;
}


bool canFinish(int numCourses, vector<pair<int,int>>& prerequisites){
    vector<unordered_set<int>> adj(numCourses);
    for(auto& val: prerequisites){
	    adj[val.second].insert(val.first);
    }
    cycle = true;
    for(int i=0;i<numCourses;i++){
        if(!visited[i]){
            cycle =  dfs(i,adj);
        }
        if(!cycle) break;
    }	    
    return cycle;
}

int main(){
	vector<pair<int,int>> requisites;
	requisites.push_back(make_pair(1,0));
	requisites.push_back(make_pair(2,0));
	requisites.push_back(make_pair(3,1));
	requisites.push_back(make_pair(3,2));
	cout<< " ff " << canFinish(4,requisites) << "\n";
	//adj[0].push_back(1);
	//adj[1].push_back(0);	
	//cycle = true;	

	
	return 0;
}