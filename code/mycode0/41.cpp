#include<bits/stdc++.h>
using namespace std;

const int N = 1007;

int mp[N][N], n, vis[40], fn[40];

int main(){
    fn[0] = 1;
    for(int i = 1; i<32 ; i++){
        fn[i] = fn[i - 1] * 2;
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &mp[i][j]);
        }
    }
    vector<int>v;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 33; j++) vis[j] = 0;
        for(int j = 1; j <= n; j++){
            int cnt = 0;
            int x = mp[i][j];
            while(x){
                if(x & 1){
                    vis[cnt]++;
                }
                x = x / 2;
                cnt++;
            }
        }
        int ans = 0;
        for(int j = 0; j < 33; j++){
            if(vis[j]){
                ans += fn[j];
            }
        }
        v.push_back(ans);

    }
    for(int i: v){
        printf("%d ", i);
    }
    puts("");
}