#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

int n, sum;


int tree[10 * N];

vector<int> g;

#define m (l + r) / 2
#define lson 2 * node
#define rson 2 * node + 1

int add[4 * N];



struct line {
    int x, y;
} lin[N];

bool cmp(line x, line y) {
    return (x.y - x.x)  < (y.y - y.x); 
}

int get_id(int x) {
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1;
}

void push_down(int node) {
    if (add[node]) {
        tree[lson] += add[node];
        tree[rson] += add[node];
        add[lson] += add[node];
        add[rson] += add[node];
        add[node] = 0;
    }

}

void update(int v, int ql, int qr, int l, int r, int node) {
    if (ql <= l && qr >= r) {
        tree[node] += v;
        add[node] += v;
     
        return;
    }
    push_down(node);
    if (ql <= m) update(v, ql, qr, l, m, lson);
    if (qr > m) update(v, ql, qr, m + 1, r, rson);
    tree[node] = max(tree[lson], tree[rson]);
}

class hash_str {
private:
    string str;
    const long long d = 238;
    const long long MOD = 1610612741;
    vector<long long>h, p;
    int n;
public:
    hash_str(string s) {
        this->str = s;
        this->n = str.length();
        h.resize(n + 1);
        p.resize(n + 1);
    }
    hash_str() {}
    void make_hash() {
        h[0] = str[0];
        p[0] = 1;
        for(int i = 1; i < n; i++) {
            h[i] = ((h[i - 1] * d ) % MOD + str[i] ) % MOD;
            p[i] = (p[i - 1] * d ) % MOD;
        }
    }
    long long  get_hash(int l, int r) {
        if(!l) return h[r];
        return (h[r] - (h[l - 1] % MOD * p[r - l + 1] % MOD) % MOD + MOD) % MOD;
    }
};



int main() {
  
    scanf("%d %d", &n, &sum);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g.push_back(x);
        g.push_back(y);
        lin[i].x = x, lin[i].y = y;
    } 
    sort(g.begin(), g.end());
    g.erase(unique(g.begin(), g.end()), g.end());
    sort(lin + 1, lin + n + 1, cmp);

    int last = 1;
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int l = get_id(lin[i].x);
        int r = get_id(lin[i].y);

        update(1, l, r, 1, g.size(), 1);

        if (tree[1] == sum) {

            while (tree[1]>= sum) {
                l = get_id(lin[last].x);
                r = get_id(lin[last].y);
                update(-1, l, r, 1, g.size(), 1);
       
                last++;
            }
            ans = min(ans, (lin[i].y - lin[i].x) - (lin[last - 1].y - lin[last - 1].x));
        }  

    }
    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
        

    
    
}



