#include<bits/stdc++.h>
using namespace std;

int r, c, mp[200][200];

int work(int x, int y){
    int ans = 0;
    int f = 0;
    for(int i = 1; i < y; i++){
        if(mp[x][i] >= mp[x][y]){
            f = 1;
            break;
        }
    } 
    if(f == 0)ans++;
    f = 0;
    for(int i = y + 1; i <= c; i++){
        if(mp[x][y] <= mp[x][i] ){
            f = 1;
            break;
        }
    }
    if(f == 0)ans++;
    f = 0;
     for(int i = 1; i < x; i++){
        if(mp[i][y] >= mp[x][y]){
            f = 1;
            break;
        }
    } 
    if(f == 0)ans++;
    f = 0;
    for(int i = x + 1; i <= r; i++){
        if(mp[x][y] <= mp[i][y] ){
            f = 1;
            break;
        }
    }
    if(f == 0)ans++;
    return ans;

}

int main(){
    while(~scanf("%d %d", &r, &c)){
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                scanf("%d", &mp[i][j]);
            }
        }
        int ans = 0;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                ans += work(i, j);
            }
        }
        printf("%d\n", ans);
    }
}