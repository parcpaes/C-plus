#include <cstdio>

int data[101];
int sum(int i){
	if(i<=0) return data[i];	
	return sum(i-1)+data[i];
}

int main(){
	int t,n,value;
	scanf("%d",&t);
	for(int j = 0; j<t; j++){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",data+i);	
		}
		printf("Case %d: %d\n",j+1,sum(n-1));
	}
	return 0;
}