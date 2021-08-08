#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 7;

int block[N], a[N], n;
long long res[4 * N];

struct node{
    int l, r, pos;
};

vector<node>g;

long long cnt2[N], cnt1[N];

bool cmp(node x, node y){
    if(block[x.l] == block[y.l]){
        return x.r < y.r;
    }
    return block[x.l] < block[y.l];
}

int main(){
    scanf("%d", &n);
    int b = sqrt(n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        block[i] = i / b;
    }

    int q; scanf("%d", &q);
    for(int i = 1; i <= q; i++){
        int l, r, l1, r1;
        scanf("%d %d %d %d", &l, &r, &l1, &r1);
        g.push_back({r, r1, i});
        g.push_back({l - 1, r1, q + i});
        g.push_back({l1 - 1, r, 2 * q + i});
        g.push_back({l - 1, l1 - 1, 3 * q + i});
    }
    sort(g.begin(), g.end(), cmp);
    int l = 0, r = 0;
    long long ans = 0;
    for(node it: g){
        while(l < it.l){
            l++, ans += cnt2[a[l]], cnt1[a[l]]++;
        }
        while(l > it.l){
            ans -= cnt2[a[l]], cnt1[a[l]]--, l--;
        }
        while(r < it.r){
            r++,  ans += cnt1[a[r]], cnt2[a[r]]++;
        }
        while(r > it.r){
            ans -= cnt1[a[r]], cnt2[a[r]]--, r--;
        }
    
        res[it.pos] = ans;
    }
    for(int i = 1; i <= q; i++){
        printf("%lld\n", res[i] - res[q + i] - res[2 * q + i] + res[3 * q + i]);
    }


}