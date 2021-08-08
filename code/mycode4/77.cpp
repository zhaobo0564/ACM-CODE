#include<bits/stdc++.h>
using namespace std;

int mp[1000][1000];
int t, n, k;

void pr(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%d", mp[i][j]);
        }
        puts("");
    }
}



int main(){
    scanf("%d", &t);
    while (t--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i <= n + 1; i++){
            for(int j = 0; j <= n + 1; j++){
                mp[i][j] = 0;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                mp[i][j] = 1;
                k--;
                if(k == 0)break;
            }
        }
        int maxn = 0, minn = 1000000;
        for(int i = 1; i <= n; i++){
            int ans = 0;
            for(int j = 1; j <= n; j++){
                ans += mp[i][j];
            }
            maxn = max(ans, maxn);
            minn = min(ans, minn);
        }
        int maxn1 = 0, minn1= 1000000;
        for(int i = 1; i <= n; i++){
            int ans = 0;
            for(int j = 1; j <= n; j++){
                ans += mp[j][i];
            }
            maxn1 = max(ans, maxn1);
            minn1 = min(ans, minn1);
        }
        int cnt = maxn - minn;
        int cnt1 = maxn1 - minn1;
        cout << cnt * cnt + cnt1 * cnt1 << endl;
        pr();
    }
    
}