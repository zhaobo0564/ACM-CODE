#include<bits/stdc++.h>
using namespace std;
const int N = 100007;

int a[N], n, k;


int main(){
	int t;
	
	scanf("%d", &t);int cnt = t;
	while(t--){
		scanf("%d %d", &n, &k);
		int ok = 0;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			if(a[i] == k) ok = 1;
		}
		if(n == 1 && ok){
			puts("YES");
			continue;
		}
		for(int i = 1; i <= n - 2; i++){
			if(a[i] >= k && a[i + 1] >= k){
				ok++;
				break;
			}
			if(a[i] >= k && a[i + 2] >= k){
				ok++;
				break;
			}
			if(a[i + 1] >= k && a[i + 2] >= k){
				
				ok++;
				break;
			}
		}
		if(n == 2 &&a[n] >= k && a[n - 1] >= k){
			ok += 1;
		}
		if(ok >= 2)puts("YES");
		else puts("NO");
	}

}