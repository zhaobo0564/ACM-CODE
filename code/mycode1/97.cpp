#include<bits/stdc++.h>
using namespace std;
int t, n;
vector<int>g;

int main(){
    scanf("%d", &t);
    int ans = 2;
    int l = 1;
    g.push_back(2);
    while(1){
        l++;
        ans += l * 2 + l - 1;
        g.push_back(ans);
      //  cout << ans << endl;
        if(ans > 1000000000)break;
    }
    while(t--){
        scanf("%d", &n);
        int cnt = 0;
        while(n){
            int p = upper_bound(g.begin(), g.end(), n) - g.begin();
            if(p == 0)break;
            n -= g[p - 1];
            cnt++;
        }
        printf("%d\n", cnt);

    }
}