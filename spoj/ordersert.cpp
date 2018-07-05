#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using order_set= tree<T, null_type, less<int>,rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	order_set<int> rtree;
	int q,x;
	scanf("%d",&q);
	char str[2];
	while(q--){
		scanf("%s", str);
		scanf("%d", &x);
		if(str[0]=='I'){
			rtree.insert(x);
		}else if(str[0]== 'D'){
			rtree.erase(rtree.find(x)); //erase and find long(long())
		}else if(str[0]=='C'){
			/*return position of given element, If the element does not appear in the set, so we get the position that the element
			would have in the set:, return the number of elements of S smaller than x*/
			cout << rtree.order_of_key(x) << "\n";
												  
		}else{
			int p = *rtree.find_by_order(x-1);	//return a iterator the element at a given position:
												//return the k-th smallest element of S
			if(p==0){
				printf("invalid\n");
			}else{
				printf("%d\n",p);
			}
		}
	}
	return 0;
}