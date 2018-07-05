#include <bits/stdc++.h>

using namespace std;
#define INF 2123123123
struct node{
	int val;
	int l,r;
};
node tree[1001<<2];
int pnode=0;

int data[1001];
int root[1001];

int getLeft(int node){ (node<<1);}
int getRight(int node){ (node<<1)|1;}

void merge(int u, int x, int y){
	tree[u].val = tree[x].val + tree[y].val;
}

void build(int node,int left, int right){
	if(left == right){
		tree[node].val = data[left];
	}else{
		int mid = (left + right)>>1;

		tree[node].l = pnode++;
		build(tree[node].l, left, mid);

		tree[node].r = pnode++;
		build(tree[node].r, mid+1, right);

		merge(node,tree[node].l , tree[node].r);
	}
}

void update(int node,int left, int right,int pnod,int index,int value){

	if(left == right){
		tree[node].val = value;
	}else{
		int mid= (left + right)>>1;
		if(index <= mid){
			tree[node].l = pnode++;
			tree[node].r = tree[pnod].r;			
			update(tree[node].l,left, mid, tree[pnod].l,index, value);
		}else{			
			tree[node].l = tree[pnod].l;			
			tree[node].r = pnode++;
			update(tree[node].r, mid+1, right, tree[pnod].r , index, value);	
		} 
		merge(node, tree[node].l, tree[node].r);
	}
}

int query(int node, int left, int right, int i, int j){
	if(i>right || j<left) return 0;
	if(i<=left && right<=j){
		return tree[node].val;
	}else{	
		int mid = (left + right)>>1;
		int ret;
		if(i <= mid) ret += query(tree[node].l,left, mid, i, j);
		if(j > mid) ret += query(tree[node].r, mid+1, right,i,j);
		return ret;
	}
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int N,Q;
	scanf("%d%d", &N,&Q);
	for(int i=0; i< N; i++){
		scanf("%d",data+i);
	}
	root[0] = pnode++;
	build(root[0],0,N-1);
	int proot = 1;
	for(int i=0; i< Q ; i++){
		char sc[2];
		scanf("%s",sc);
		if(sc[0] == 'U'){
			//update
			int x, y;
			scanf("%d%d",&x,&y);
			root[proot] = pnode++;			
			update(root[proot], 0, N-1, root[proot-1], x-1, y);
			proot++;
			for(int i=0; i< N<<2;i++){
				cout << tree[i].val << " ";
			}
			cout << "\n";
			for(int i=0; i< N;i++){
				cout << root[i] << " ";
			}
			cout << "\n";
		}else{
			int x,y,z;
			scanf("%d%d%d",&x, &y,&z);
			printf("%d\n", query(root[z-1],0,N-1,x-1,y-1));
		}
	}
	return 0;
}