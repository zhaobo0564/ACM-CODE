#include <bits/stdc++.h>
using namespace std;

int n, m, k;
long long a[150][150];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	
	scanf("%d", &k);
	char t;
	int l, r;
	while(k--) {
		scanf(" %c %d %d", &t, &l, &r);
        if(l == r)continue;
		if(t == 'r') {
			for(int i = 1;i <= m; i++) {
				swap(a[l][i], a[r][i]);
			}
		}
		else if(t == 'c'){
			for(int i = 1;i <= n; i++) {
				swap(a[i][l], a[i][r]);
			}
		}
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
          printf("%lld", a[i][j]);
        
            
		}
		printf("\n");
	}
}
