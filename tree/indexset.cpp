#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int,null_type, less<int>, rb_tree_tag,
			tree_order_statistics_node_update> index_set;

int main(){

	index_set set[100];
	set[0].insert(1);
	set[0].insert(1);
	set[0].insert(4);
	set[0].insert(3);
	set[0].insert(2);

	set[1].insert(20);
	set[1].insert(12);
	set[1].insert(15);
	set[1].insert(10);

	for(int i=0;i<2;i++){
		for(auto val: set[i]){
			cout << val << "\n";
		}
	}
	return 0;
}