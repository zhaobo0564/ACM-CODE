#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000007;

ll a[N];

void init(){
	for(int i = 1; i <= 1000000; i++){
        for(int j = sqrt(i); j; j--){
            if(i %j == 0){
                a[i] = j;
                break;
            }
        }
    }
}

ll mod = 1e9 + 7;
ll fn[N];

ll work(int x){
	for(int i = 1; i <= x; i++){
		fn[i] = (fn[i - 1] + (a[i] + i / a[i]) / 2) % mod;
	}
	return fn[x] % mod;
}

int main(){

	int t; scanf("%d", &t);
	init();
	while(t--){
		int x; scanf("%d", &x);
		printf("%lld\n", work(x));
	}
}