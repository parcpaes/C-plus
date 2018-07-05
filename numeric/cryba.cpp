#include <bits/stdc++.h>

using namespace std;
bitset<10000010> bs;
vector<long> primes;
void eratosthenes(long n){
	n = n + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(long i=3; i<=n;i++){
		if(bs[i]){
			for(long j=i*i;j<=n;j+=i) bs[j] = 0;
			primes.push_back(i);
		}
	}
	/*bool pf;
	for(long i=85;i*i<40000000;i+=6){
		pf=true;
		for(auto& val: primes){
			if(i%val==0){
				pf = false;
				break;
			}
		}
		if(pf)primes.push_back(i);		
	}*/
}

int main(){
	eratosthenes(80);
	cout<< primes.back() <<"\n";
	cout<< primes.size() <<"\n";
	//int count = 0;
	//for(auto& val: primes){
	//	count ++;
	//	if(count%10==0) cout<< "\n";		
	//	cout<< val <<" ";
	//}
	
	return 0;
}