#include <bits\stdc++.h>

using namespace std;

template<class T> bool uin(T &a, T b){return a > b ? (a = b, true): false;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout<< fixed;
#ifdef LOCAL_DEFINE
	freopen("input.txt", "rt", stdin);
#endif

	int n,m;
	cin>> n >> m;
	uin(n,30);
	//cout << n << '\n';
	cout << m %( 1<< n) << '\n';
#ifdef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * clock()/ CLOCK_PER_SEC << " s.\n";
#endif
	return 0;
}
