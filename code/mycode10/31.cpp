#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int a[N], n, all[N];

vector<int> g[N], v;

map<int, int> mp[N];

int get_id(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int id[N], sum[N], vis[N], sz[N], top = 1;

int cat[N];

int merge(int x, int y) {
	if (mp[x].size() > mp[y].size()) {
		for (auto it: mp[y]) {
			mp[x][it.first] += it.second;
		}
		mp[y].clear();
		return x;
	} else {
		for (auto it: mp[x]) {
			//cout << "y = " << y << " " << it.first << " " << it.second << endl;
			mp[y][it.first] += it.second;
		}
		mp[x].clear();
		return y;
	}

}

void dfs(int u, int fa) {
	id[u] = top++;
	sz[u] = 1;
	mp[cat[u]][a[u]] = 1;
	for (int to: g[u]) {
		if (to == fa) continue;
		dfs(to, u);
		
		sz[u] += sz[to];
		if (mp[cat[to]][a[u]]) {
			//cout << "uu  " << u << endl; 
			sum[1]++;
			sum[id[to]]--;
			sum[id[to] + sz[to]]++;
		}
		cat[u] = merge(cat[u], cat[to]);
	}
	if (all[a[u]] > mp[cat[u]][a[u]]) {
		//cout << "u = " << u << endl;
		sum[id[u]]++;
		sum[id[u] + sz[u]]--;
	}

}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v.push_back(a[i]);		
		cat[i] = i;
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 1; i <= n; i++) {
		a[i] = get_id(a[i]);
		all[a[i]]++;
	}


	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + sum[i];
	//	cout << sum[i] << " ";
		if (sum[i] == 0) {
			ans++;
		}
	}
	//cout << endl;
	cout << ans << endl;


}