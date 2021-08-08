#include<bits/stdc++.h>
using namespace std;
const int N = 4e4 + 7;

int n, a[200], b[200];
int dp[N][200], fn[N][200];

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = -1000000000;
		}
	}
	dp[20000][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < N; j++) {
			for (int z = 0; z <= i; z++) {
				fn[j][z] = dp[j][z];
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= i; k++) {
				if (k) {
					if (j - a[i] + b[i] >= 0) {
						dp[j][k] = max(dp[j][k], fn[j - a[i] + b[i]][k - 1] + b[i]);
					}
				}
				if (j + b[i] / 2 < N) {
					dp[j][k] = max(dp[j][k], fn[j + b[i]/ 2][k] + b[i] / 2);
				}
			}
		}
	}

	
}

void work() {
	for (int i = 1; i <= n; i++) {
		int mx = -1000000000;
		for (int j = 0; j < 20000; j++) {
			mx = max(mx, dp[j][i] - (20000 - j));
		}
		for (int j = 20000; j <= 40000; j++) {
			mx = max(mx, dp[j][i]);
		}
		printf("%.9f\n", (double)mx / 2.0);
	}
}

int main() {
	//ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		a[i] += a[i];
		b[i] += b[i];
	}
	solve();
	work();
}