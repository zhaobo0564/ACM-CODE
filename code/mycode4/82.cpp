#include<bits/stdc++.h>
using namespace std;

int k, n;

int mp[1000][1000];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                mp[i][j] = 0;
            }
        }
        if(k % n == 0){
            int cnt = k / n;
            int sum = n, cn = 0;
            for(int i = 1; i <= cnt; i++){
                for(int j = 1; j <= sum; j++){
                    mp[j + cn][j] = 1;
                }
                for(int j = 1; j <= cn; j++ ){
                    mp[j][n - cn + j] = 1;
                }
                sum--;
                cn++;
            }
            puts("0");
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    printf("%d", mp[i][j]);
                }
                puts("");
            }
        }else{
            int cn1 = k % n;
            int cnt = k / n;
            int sum = n, cn = 0;
            for(int i = 1; i <= cnt; i++){
                for(int j = 1; j <= sum; j++){
                    mp[j + cn][j] = 1;
                }
                for(int j = 1; j <= cn; j++ ){
                    mp[j][n - cn + j] = 1;
                }
                sum--;
                cn++;
            }
            for(int j = 1; j <= sum; j++){
                    if(cn1 == 0)break;
                    cn1--;
                    mp[j + cn][j] = 1;
            }
            for(int j = 1; j <= cn; j++ ){
                if(cn1 == 0)break;
                cn1--;
                mp[j][n - cn + j] = 1;
            }
            puts("2");
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    printf("%d", mp[i][j]);
                }
                puts("");
            }
        }
    }
}