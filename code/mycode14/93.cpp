#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
#define url unsigned long long
#define ll long long
int a[N][N], b[N][N], n, m;
url ha_a[N][N], p_a[N][N], base = 21, ha_b[N][N], p_b[N][N];

ll ha_a1[N][N], p_a1[N][N], base1 = 147, ha_b1[N][N], p_b1[N][N];
const ll mod = 998244353;


pair<int, int> id[N * N];

void init(int x) {
    p_a[x][0] = 1;
    for (int i = 1; i <= m; i++) {
        ha_a[x][i] = ha_a[x][i - 1] * base + a[x][i];
        p_a[x][i] = p_a[x][i - 1] * base;
    }
    p_b[x][0] = 1;
    for (int i = 1; i <= m; i++) {
        ha_b[x][i] = ha_b[x][i - 1] * base + b[x][i];
        p_b[x][i] = p_b[x][i - 1] * base;
    }
    p_a1[x][0] = 1;
    for (int i = 1; i <= m; i++) {
        ha_a1[x][i] = (ha_a1[x][i - 1] * base1 % mod + (url)a[x][i]) % mod;
        p_a1[x][i] = p_a1[x][i - 1] * base1 % mod;
    }
    p_b1[x][0] = 1;
    for (int i = 1; i <= m; i++) {
        ha_b1[x][i] = (ha_b1[x][i - 1] * base1 % mod + (url)b[x][i]) % mod;
        p_b1[x][i] = p_b1[x][i - 1] * base1 % mod;
    }

}

url get_ha_a(int x, int l, int r) {
    return ha_a[x][r] - ha_a[x][l - 1] * p_a[x][r - l + 1]; 
}

url get_ha_b(int x, int l, int r) {
    return ha_b[x][r] - ha_b[x][l - 1] * p_b[x][r - l + 1]; 
}

ll get_ha_a1(int x, int l, int r) {
    return (ha_a1[x][r] - (ha_a1[x][l - 1] % mod * p_a1[x][r - l + 1] % mod) % mod + mod) % mod; 
}

ll get_ha_b1(int x, int l, int r) {
    return (ha_b1[x][r] - (ha_b1[x][l - 1] % mod * p_b1[x][r - l + 1] % mod) % mod + mod) % mod; 
}

int h[N][N];

vector<pair<int, int> > cat;

void work(int x, int y, int va) {
    int l = 1, r = m - y + 1, ans = 1;
    r = min(r, m - id[va].second + 1);
    while (l <= r) {
        int mid = (l + r >> 1);
        url res_a = get_ha_a(x, y, y + mid - 1);
        url res_b = get_ha_b(id[va].first, id[va].second, id[va].second + mid - 1);
        ll res_a1 = get_ha_a1(x, y, y + mid - 1);
        ll res_b1 = get_ha_b1(id[va].first, id[va].second, id[va].second + mid - 1);
        if (res_a == res_b && res_a1 == res_b1) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << "x " << x << " y " << y << endl;
    cout << "va.first = " <<id[va].first << " ans = " << ans << endl;
    h[id[va].first][id[va].second] = ans;
    cat.push_back(id[va]);
}

stack<int> q;

int L[N], R[N], ANS;

void cal(int s, int t) {
    cout << "s = " << s << " t = " << t << endl;
    while (q.size()) q.pop();
    for (int i = s; i <= t; i++) {
        while (q.size() && h[q.top()] > h[cat[i].first]) {
            L[q.top()] = cat[i].first;
            q.pop();
        }
        q.push(cat[i].first);
    }
    while (q.size()) L[q.top()] = cat[t].first + 1, q.pop();
    for (int i = t; i >= s; i--) {
        cout << h[cat[i].first] << " ";
        while (q.size() && h[q.top()] > h[cat[i].first]) {
            
            R[q.top()] = cat[i].first;
            q.pop();
        }
        q.push(cat[i].first);
    }

    cout << "AA " << cat[s].first << endl;
    while (q.size()) R[q.top()] = cat[s].first - 1, q.pop();
    for (int i = s; i <= t; i++) {
        int left = R[cat[i].first];
        int right = L[cat[i].first];
        int cn = (right - left - 1) * h[cat[i].first];
        cout << "L = " << right << " R = " << left << endl;
        cout << "h " << h[cat[i].first] << endl;
        cout << "area = " << cn << endl;
        ANS = max(ANS, cn);
        //L[cat[i].first] = R[cat[i].first] = 0;
    }
  
}

void gao() {
    int st = 0, end = 0;
    for (int i = 0; i < cat.size(); i++) {
        cout << h[cat[i].first] << " ";
    }
    cout << endl;
    for (int i = 1; i < cat.size(); i++) {
        
        if (cat[i].second == cat[i - 1].second && cat[i].first - 1 == cat[i - 1].first) {
            end = i;
        } else {
            cal(st, end);
            st = i;
            end = i;
        }
    }
    cal(st, end);  
}

void del() {
    for (int i = 0; i < cat.size(); i++){
        h[cat[i].first] = 0;
    }
    cat.clear();
}


int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &b[i][j]);
            id[b[i][j]].first = i;
            id[b[i][j]].second = j;
        }
        init(i);
    }
    for (int j = 1; j <= 1; j++) {
        for (int i = 2; i <= n; i++) {
            work(i, j, a[i][j]);
        }
        gao();
        del();
    }
    printf("%d\n", ANS);
}
/*
4 4
3 4 1 2
5 6 7 9
16 13 10 11
8 14 12 15
1 2 3 4
8 5 6 7
11 16 13 10
12 15 9 14
*/