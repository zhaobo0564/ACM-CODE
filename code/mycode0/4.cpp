#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
char mp[N][N];

int  n;
vector<pair<int, int> >g;
vector<pair<int, int> >v[N][N];
pair<int, int> cn[N][N];

bool judge(int x, int y, int ex, int ey){
    if(x > n || y > n || x < 1 || y < 1)
        return false;
    if(mp[x][y] != 'X' && cn[x][y].first != -1 && cn[x][y].first == ex && cn[x][y].second == ey)
        return true;
    return false;
}

void dfs(int x, int y, int ex, int ey){
    if(judge(x + 1, y, ex, ey) && mp[x + 1][y] == '0'){
        mp[x + 1][y] = 'D';
        dfs(x + 1, y, ex, ey);
    }
    if(judge(x - 1, y, ex, ey) && mp[x - 1][y] == '0'){
        mp[x - 1][y] = 'U';
        dfs(x - 1, y, ex, ey);
    }
    if(judge(x, y + 1, ex , ey) && mp[x][y + 1] == '0'){
        mp[x][y + 1] = 'R';
        dfs(x, y + 1, ex, ey);
    }
    if(judge(x, y - 1, ex ,ey) && mp[x][y - 1] == '0'){
        mp[x][y - 1] = 'L';
        dfs(x, y - 1, ex, ey);
    }
}





int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mp[i][j] = '0';
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x, y;
            scanf("%d%d", &x, &y);
            if(x == -1){
                cn[i][j].first = -1;
                cn[i][j].second = -1;
                mp[i][j] = '1';
            }else{
                if(i ==x && j == y)
                    mp[x][y] = 'X';
                v[x][y].push_back(make_pair(i, j));
                cn[i][j].first = x;
                cn[i][j].second = y;
            }   
        }
    }
    int f = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=n; j++){
            if(mp[i][j] == 'X'){
                dfs(i, j, i, j);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mp[i][j] == '1'){
                if(mp[i][j + 1] == '1'){
                    mp[i][j] = 'L';
                    mp[i][j + 1] = 'R';
                }else if(mp[i][j - 1] == '1'){
                    mp[i][j] = 'R';
                    mp[i][j - 1] = 'L';
                }else if(mp[i - 1][j] == '1'){
                    mp[i][j] = 'D';
                    mp[i - 1][j] = 'U';
                }else if(mp[i + 1][j] == '1'){
                    mp[i][j] = 'U';
                    mp[i + 1][j] = 'D';
                }else{
                   if(cn[i][j - 1].first == -1){
                       mp[i][j] = 'R';
                   }else if(cn[i][j + 1].first == -1){
                       mp[i][j] = 'L';
                   }else if(cn[i + 1][j].first == -1){
                       mp[i][j] = 'U';
                   }else if(cn[i - 1][j].first == -1){
                       mp[i][j] = 'D';
                   }
                   else{
                       printf("INVALID\n");
                       return 0;
                   }
                }
            }else if(mp[i][j] == '0'){
                printf("INVALID\n");
                return 0;
            }
        }
    }
    printf("VALID\n");
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mp[i][j] == 'L'){
                printf("R");
            }else if(mp[i][j] == 'R'){
                printf("L");
            }else if(mp[i][j] == 'D'){
                printf("U");
            }else if(mp[i][j] == 'U'){
                printf("D");
            }else{
                printf("%c",mp[i][j]);
            }
        }
        puts("");
    }


}