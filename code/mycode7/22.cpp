#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll dist[N], vis[N];
int n, m;
struct node {
	ll u, d, id, line;
	bool operator < (const node x) const {
		return d > x.d;
	}
		
};

struct edge {
	ll v, d, id, line;	
};

vector<edge> g[N];
priority_queue<node> q;

void dj() {
	for (int i = 0; i <= max(m, n); i++) {
		dist[i] = LLONG_MAX;
		vis[i] = 0;
	}
	for (int i = 0; i < g[1].size(); i++) {
        int line = g[1][i].line;
        q.push({g[1][i].v, g[1][i].d, g[1][i].id, line});
        dist[line] = g[1][i].d;
	//	cout << "****\n";
    }
	while (q.size()) {
		node cd= q.top();
		q.pop();
		if (vis[cd.line]) continue;
		vis[cd.line] = 1;
		for (int i = 0; i < g[cd.u].size(); i++) {
			ll to = g[cd.u][i].v;
			ll id = g[cd.u][i].id;
			ll cost = g[cd.u][i].d;
            ll line = g[cd.u][i].line;
			if (cd.id == -1) {
				
			} else {
				cost += abs(id - cd.id);
			}
			//cout << "line " << line << endl;
			if (dist[line] >= dist[cd.line] + cost) {
				dist[line] = dist[cd.line] + cost;
				q.push({to, dist[line], id, line});
			}
		}
	}
}



int main() {
	
	while (~scanf("%d %d", &n, &m)) {
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			ll a, b, c, d;
			scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
			g[a].push_back({b, d, c, i});
			g[b].push_back({a, d, c, i});
		}
		
		dj();
        ll ans = LLONG_MAX;
        for (int i = 0; i < g[n].size(); i++) {
            int line = g[n][i].line;
		//	cout << dist[line] << endl;
            ans = min(ans, dist[line]);
        }
		printf("%lld\n", ans);
	}	
}