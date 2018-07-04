//1137
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	freopen("input.txt","rt",stdin);
	int node1,node2,parent,count=0;
	map<int,int> nodes;
	vector<int> values;
	while(true){
		cin>>node1>>node2;		
		if(node1==-1 && node2==-1) break;		
		if(node1>0 && node2>0){
			values.push_back(node1);
			values.push_back(node2);
			nodes[node2]++;			
		}else{
			count++;
			bool istree=true;
			parent = 0;
			for(auto& val: values){				
				if(nodes[val]>1)istree=false;
				if(nodes[val] == 0) parent++;							
			}
			if(values.size() == 0 && node1==0 && node2==0){
				cout<<"Case "<< count<< " is a tree.\n";
			}else if(istree && parent == 1){
				cout<<"Case "<< count<< " is a tree.\n";
			}else{
				cout<<"Case "<< count<< " is not a tree.\n";
			}
			nodes.clear();
			values.clear();
		}
	}
	return 0;
}