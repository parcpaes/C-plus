//207
#include <bits/stdc++.h>

using namespace std;

map<int,bool> visited;        
map<int,bool> previsit;

int dfs(int v,vector<unordered_set<int>> &adj, vector<int>& courses, int j){    
    visited[v] = true;
    previsit[v] = true;
    for(auto& p:adj[v]){
        if(previsit[p]) return -10;
        if(!visited[p]) j = dfs(p,adj,courses,j);        
    }
    if(j == -10) return -10;
    previsit[v]=false;
    courses[j]=v;    
    return j-1;
}


vector<int> canFinish(int numCourses, vector<pair<int,int>>& prerequisites){
    vector<unordered_set<int>> adj(numCourses);
    for(auto& val: prerequisites){
	    adj[val.second].insert(val.first);
    }    
    vector<int> courses(numCourses);    
    int j=numCourses-1;
    for(int i=0;i<numCourses;i++){
        if(!visited[i]) j =  dfs(i,adj,courses,j);
        if(j==-10) return {};                    
    }
    return courses;
}

int main(){
	vector<pair<int,int>> requisites;
	requisites.push_back(make_pair(1,0));
	requisites.push_back(make_pair(2,1));
    requisites.push_back(make_pair(0,2));    

	vector<int> courses = canFinish(3,requisites);
    cout << "empty\n";
    for(auto& val: courses){
        cout<< val << " ";
    }
	return 0;
}