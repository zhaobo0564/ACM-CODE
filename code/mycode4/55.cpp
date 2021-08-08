#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
struct segement{
    ll maxn, maxn1;
    int pos;
}tree[4 * N];
ll a[N];

#define lson 2 * node
#define rson 2 * node + 1
#define m (l + r) / 2

struct data{
    string na, ad;

};

void build(int l, int r, int node){
    if(l ==  r){
        tree[node].maxn = a[l];
        tree[node].maxn1 = 0;
        tree[node].pos = l;
        return;
    }
    build(l, m, lson);
    build(m + 1, r, rson);
    if(tree[rson].maxn > tree[lson].maxn){
        tree[node].maxn = tree[rson].maxn;
        tree[node].pos = tree[rson].pos;
        if(tree[rson].maxn1 > tree[lson].maxn){
            tree[node].maxn1 = tree[rson].maxn1;

        }else{
            tree[node].maxn1 = tree[lson].maxn;
        }
    }else{
        tree[node].maxn = tree[lson].maxn;
        tree[node].pos = tree[lson].pos;
        if(tree[lson].maxn1 > tree[rson].maxn){
            tree[node].maxn1 = tree[lson].maxn1;
        }else{
            tree[node].maxn1 = tree[rson].maxn;
        }
    }
}

void update(ll v, int pos, int l, int r, int node){
    if(l == r){
        tree[node].maxn += v;
        //tree[node].maxn1 = 0;
        return;
    }
    if(pos <= m) update(v, pos, l, m, lson);
    else update(v, pos, m + 1, r, rson);
    if(tree[rson].maxn > tree[lson].maxn){
        tree[node].pos = tree[rson].pos;
        tree[node].maxn = tree[rson].maxn;
        if(tree[rson].maxn1 > tree[lson].maxn){
            tree[node].maxn1 = tree[rson].maxn1;
        }else{
            tree[node].maxn1 = tree[lson].maxn;
        }
    }else{
        tree[node].maxn = tree[lson].maxn;
        tree[node].pos = tree[lson].pos;
        if(tree[lson].maxn1 > tree[rson].maxn){
            tree[node].maxn1 = tree[lson].maxn1;
        }else{
            tree[node].maxn1 = tree[rson].maxn;
        }
    }
}


vector<data> g[N];

map<string , string> name;
map<string, int> address;
map<string, ll>money;
map<string, int>ans;
string cnt[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, day, q;
    cin >> n;
    int top = 1;
    for(int i = 1; i <= n; i++){
        string na, ad;
        ll w;
        cin >> na >> ad >> w;
        money[na] = w;
        name[na] = ad;
        if(address[ad]){
            a[address[ad]] += w;
        }else{
            a[top] = w;
            cnt[top] = ad;
            address[ad] = top++;
        }
    }
    int maxn  = 100000;
    build(1, maxn, 1);
    cin >> day >>q;
    while(q--){
        int d;
        string ad, na;
        cin >> d>> na>> ad;
        g[d].push_back({na, ad});
    }

    for(int i = 1; i <= day; i++){
        if(tree[1].maxn1 != tree[1].maxn){
          //  cout <<" i " << i << " " << cnt[tree[1].pos] << " " << tree[1].maxn1 << " " << tree[1].maxn << endl;
            ans[cnt[tree[1].pos]]++;
        }
        for(int j = 0; j < g[i].size(); j++){
            string na = g[i][j].na;
            string ad = g[i][j].ad;
            string last_ad = name[na];
            name[na] = ad;
            int pos = address[last_ad];
            ll va = money[na];
            update(-va, pos, 1, maxn, 1);
            if(address[ad] == 0){
                cnt[top] = ad;
                address[ad] = top++;
            }
            pos = address[ad];
             va = money[na];

            update(va, pos, 1, maxn, 1);
        }

        
       

    }

    for(auto it: ans){
        cout <<it.first <<" " << it.second << endl;
    }

}

/*
5
Abramovich London 10000000000
Deripaska Moscow 10000000000
Potanin Moscow 5000000000
Berezovsky London 2500000000
Khodorkovsky Chita 1000000000
25 9
1 Abramovich Anadyr
5 Potanin Courchevel
10 Abramovich Moscow
11 Abramovich London
11 Deripaska StPetersburg
15 Potanin Norilsk
20 Berezovsky Tbilisi
21 Potanin StPetersburg
22 Berezovsky London
*/