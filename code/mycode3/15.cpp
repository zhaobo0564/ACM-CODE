#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int t, n, a[N], b[N];

multiset<int>s;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        s.clear();
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            auto it = s.upper_bound(b[i]);
            if(it == s.end())continue;
            ans++;
            s.erase(it);
        }
        printf("%d\n", ans);

    }
}