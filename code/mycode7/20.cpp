#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;

int a[200];
char b[100];

int up[20], top = 1;

void work(string s) {
	int i = 0;
	top = 1;
	for (int j = i; j < s.length(); j++) {
		up[top++] = a[s[j]];

	}

}


ll dp[10][10][16];

ll dfs(int p, int f, int sum, int ok) {
	if (p >= top) {
		return sum;
	}
	if (!f && dp[p][sum][ok] != -1) return dp[p][sum][ok];
	int maxn;
	if (f) {
		maxn = up[p];
	} else {
		maxn = 15;
	}


	ll ans = 0;
	for (int i = 0; i <= maxn; i++) {
		int cnt = 0;
		if (i == ok) cnt++;
		ans = ans + 1ll*dfs(p + 1, i == maxn && f, sum + cnt, ok);

	}
    if (!f) dp[p][sum][ok] = ans;
	return  ans;

}


long long trans(string s,int radix) {
	long long res = 0;
	for(int i = 0;i < s.length(); i++) {
		char t = s[i];
		if(t >= '0' && t <= '9') {
			if(t - '0' >= radix) return -1;
			res = res * radix + 1ll * (t-'0');
		}
		else {
			if(1ll * (t - 'A' + 10) >= radix) return -1;
			res = res * radix + 1ll * (t - 'A' + 10);
		}
	}
	return res;
}

string change(ll x) {
	string ans = "";
	while (x) {
		ans += b[x % 16];
		x = x / 16;
	}

	while(ans.length() < 8) ans += '0';


	reverse(ans.begin(), ans.end());
	return ans;
}

ll gao(int ok) {
	ll ans = 0;
	//memset(dp, -1, sizeof(dp));
	ans = dfs(1, 1, 0, ok);

	//cout <<"ans = " << ans << endl;
	return ans;
}

ll c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6, 5, 4, 5, 5, 4};

int main() {
	string s;
    memset(dp, -1, sizeof(dp));
	cin >> t;
	for (int i = '0'; i <= '9'; i++) {
		a[i] = i - '0';
		b[i - '0'] = (char)i;
	}
	a['A'] = 10, a['B'] = 11, a['C'] = 12;
	a['D'] = 13, a['E'] = 14, a['F'] = 15;
	b[10] = 'A', b[11] = 'B', b[12] = 'C';
	b[13] = 'D', b[14]= 'E', b[15] = 'F';
	while (t--) {
		ll n;
		cin >> n >> s;
        n--;
		ll cat = trans(s, 16);
        ll base = trans("FFFFFFFF", 16);
		ll r = cat + n;
		ll l = cat - 1;
        ll ca = 0;
		//cout << change(r) << endl;
        if (r >= base + 1) {
            ll r1 = r % (base + 1);
            r = base;
            work(change(r1));
           // cout << change(r1) << endl;
            for (int i = 0; i <= 15; i++) {
                ca += (gao(i) * c[i]);
            }
            //cout << "ca " << ca << endl;
        }


		work(change(r));
		ll ans = 0;

		for (int i = 0; i <= 15; i++) {
			ans += gao(i) * c[i];

		}

		ll ans1 = 0;
		if (l >= 0) {
			
			//cout << change(l) << endl;
			work(change(l));
          
			for (int i = 0; i <= 15; i++) {
				ans1 += (gao(i) * c[i]);

			}
		}

		cout << ans- ans1 + ca << endl;










	}

}