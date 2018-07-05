#include <bits/stdc++.h>

using namespace std;

int stree[6<<2];
int data[6];

int getLeft(int node){return (node<<1)+1;}
int getRight(int node){return (node<<1)+2;}

void build(int node, int left, int right){
	if(left == right){		
		stree[node] = data[left];
		return;		
	}else{
		int mid = (left+right)>>1;		
		build(getLeft(node), left, mid);		
		cout << node << " right " << right << " "<< mid<<  "\n";
		build(getRight(node), mid+1, right);
		stree[node] = stree[getLeft(node)] + stree[getRight(node)];
	}
}

int queryfind(int node,int left, int right, int i, int j){
	return 0;
}

int main(){
	int x = 6;
	for(int i=0;i<x;i++){
		scanf("%d",data+i);
	}	
	build(0,0,x-1);
	for(int i=0;i<36;i++){
		cout<< stree[i] <<" ";
	}
	cout<<"\n";
	return 0;
}

