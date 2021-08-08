#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

char mp[10][N], vis[10][N];

int n, m, t, a, b;
int ok = 0;

void dfs(int p, int pos, int value){
    if(pos > n)return;
    if(p == a){
        int x = value;
        int cnt  = 0;
        for(int i = 1; i <= m ; i++){
            for(int j = 1; j <= n; j++){
                vis[j][i] = mp[j][i];
            }
        }
        while(x){
            if(x & 1){
               // cout << cnt << " ";
                for(int i = 1; i <= m; i++){
                    vis[cnt][i] = '.';
                }
            }
            cnt++;
            x = x / 2;
        }
      //  cout << endl;
        int f = 0;
        for(int i = 1; i <= m ; i++){
            for(int j = 1; j <= n; j++){
                if(vis[j][i] == '*'){
                    f++;
                    break;
                }
            }
        }
        if(f <= b){
            ok = 1;
        }


        return;
    }
    dfs(p + 1, pos + 1, value + (1 << (pos + 1)));
    dfs(p, pos + 1, value);
}

int main(){
    scanf("%d", &t);
    while(t--){
        ok = 0;
        scanf("%d %d %d %d", &n, &m, &a, &b);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf(" %c", &mp[i][j]);
                vis[i][j] = mp[i][j];
            }
        }
        dfs(1, 1, 2);
        dfs(0, 1, 0);
        if(ok){
            printf("yes\n");
        }else{
            printf("no\n");
        }




    }
}