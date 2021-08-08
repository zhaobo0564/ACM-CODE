#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 7;
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
        tree[node].maxn1 = LLONG_MIN;
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
        // if(pos == 3){
        //     cout <<endl <<"LLLL " << tree[node].maxn << endl;
        // }
        tree[node].maxn1 = LLONG_MIN;
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
    string na, ad;
    for(int i = 1; i <= n; i++){
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
   // cout << "***********" << endl;
    // for(int i = 1; i < top; i++){
    //     cout<<"address" << cnt[i]<< " i = " << i << endl;
    //     cout <<"name " <<  address[cnt[i]] << endl;
    // }
    int maxn  = 100100;
    build(1, maxn, 1);
    cin >> day >> q;
    string last_ad;
    int d;
    while(q--){


        cin >> d>> na>> ad;
        g[d].push_back({na, ad});
    }

    for(int i = 1; i <= day; i++){
        for(int j = 0; j < g[i].size(); j++){
            na = g[i][j].na;
            ad = g[i][j].ad;
            last_ad = name[na];
         //   cout << " name " << na << " address " << ad << " last "  << last_ad << endl;
            name[na] = ad;
            int pos = address[last_ad];
            ll va = money[na];
          //  cout <<"pos " << pos << " va " << va << endl;
            update(-va, pos, 1, maxn, 1);
            if(address[ad] == 0){
                cnt[top] = ad;
                address[ad] = top++;
            }
            pos = address[ad];
             va = money[na];
           // cout << "Asd " << va <<" " << cnt[pos] << " " << pos << endl;
            update(va, pos, 1, maxn, 1);
        }
     //   cout << "ans " << tree[1].maxn1 << " " << tree[1].maxn << endl;
      //  cout << "pos " << cnt[tree[1].pos] << endl;
        if(tree[1].maxn1 != tree[1].maxn){
            ans[cnt[tree[1].pos]]++;
        }
        // for(int j = 0; j < g[i].size(); j++){
        //     string na = g[i][j].na;
        //     string ad = g[i][j].ad;
        //     if(address[ad] == 0){
        //         cnt[top] = ad;
        //         address[ad] = top++;
        //     }
        //     int pos = address[ad];
        //     ll va = money[na];
        //     cout << "Asd " << va <<" " << cnt[pos] << " " << pos << endl;
        //     update(va, pos, 1, maxn, 1);
        // }

    }
   // cout << "AAA " << endl;
    for(auto it: ans){
        cout <<it.first <<" " << it.second << endl;
    }

}