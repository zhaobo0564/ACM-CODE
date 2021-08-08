#include<bits/stdc++.h>
using namespace std;

const int N = 3e5  + 7;

int c[N];
vector<int>v;
int t, n;

vector<pair<int, int> >p;

int get_id(int x){
    return lower_bound(v.begin(), v.end(), x) - v.begin()  + 1;
}

int main(){
    scanf("%d", &t);
    while(t--){
        memset(c, 0, sizeof(c));
        v.clear();
        p.clear();
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            int l, r;
            scanf("%d %d", &l, &r);
            p.push_back({l, r});
            v.push_back(l);
            v.push_back(r);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for(auto it: p){
            int l = get_id(it.first);
            int r = get_id(it.second);
            c[l]++;
            c[r + 1]--;
        }
        for(int i = 1; i < N; i++){
            c[i] += c[i - 1];
        }
        int maxn = 0;
        for(int i = 1; i < N; i++){
            maxn = max(maxn, c[i]);
        }
        printf("%d\n", maxn);



    }
}