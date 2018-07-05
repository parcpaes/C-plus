#include <cstdio>
int data[1001];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",data+i);
    }
    for(int i=n-1;i>=0; i--){        
        printf("%d%s",data[i],(i)?" ":"");
    }
    printf("\n");
    return 0;
}