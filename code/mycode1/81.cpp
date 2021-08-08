#include <bits/stdc++.h>
using namespace std;

char s[100005];
int a[100005], n, _;

long long gcd(long long a, long long b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		long long numw = 0, numb = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d %c", &a[i], &s[i]);
			if(s[i] == 'W') numw += a[i];
			else numb += a[i];
		}
		
		if(numw == 0) printf("%lld\n", numb);
		else if(numb == 0) printf("%lld\n", numw);
		
		else {
			int ans = 0;
			long long t = gcd(numw, numb), totw = 0, totb = 0;
			numw /= t; numb /= t;
			for(int i = 1;i <= n; i++) {
				if(s[i] == 'W') {
					if(totb % numb == 0) {
						if((totw+a[i])/numw >= totb/numb && totw/numw < totb/numb) ans++;
					}
					totw += a[i];
				}
				else {
					if(totw % numw == 0) {
						if((totb + a[i])/numb >= totw/numw && totb/numb < totw/numw) ans++;
					}
					totb += a[i];
				}
			}
			printf("%d\n", ans);
		}
		
	}
}

/*
3
3
1 B
3 W
2 B
4
3 W
3 B
9 W
1 B
2
2 W
3 W
*/
