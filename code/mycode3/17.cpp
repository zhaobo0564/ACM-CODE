#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[1005], b[1005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n; i++) scanf("%d", &b[i]);
		sort(a+1, a+1+n); sort(b+1, b+1+n);
		
		int ans = 0, sta = 1;
		for(int i = 1;i <= n; i++) {
			for(int j = sta;j <= n; j++) {
				if(b[i] < a[j]) {
					ans++;
					sta = j+1;
					break;
				}
				sta = j+1;
			}
		}
		printf("%d\n", ans);
	}
}
