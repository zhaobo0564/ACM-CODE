#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;
vector<pair<ll, ll> >g[N];

struct node {
	ll u, d;
	
	bool operator < (const node& x) const {
		return d > x.d;
	}
};
int  n, m, p;
priority_queue<node> q;

ll dist[N], vis[N];

void dj(int s) {
	for (int i = 0; i <= n; i++) {
		dist[i] = 1e11;
		vis[i] = 0;
	}
	
	q.push({s, 0});
	dist[s] = 0;
	while (q.size()) {
		node cd = q.top();
		q.pop();
		if (vis[cd.u]) continue;
		vis[cd.u] = 1;
		for (int i = 0; i < g[cd.u].size(); i++) {
			ll to = g[cd.u][i].first;
			ll cost = g[cd.u][i].second;
			if (dist[to] > dist[cd.u] + cost) {
				dist[to] = dist[cd.u] + cost;
				q.push({to, dist[to]});
			}
		}
	}
}

int main() {

	scanf("%d %d %d", &n, &m, &p);
	while(m--) {
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dj(p);
	ll ans = dist[1];
	dj(1);
	ans += dist[n];
	printf("%lld\n", ans);
	 
	
}