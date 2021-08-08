#include<bits/stdc++.h>
using namespace std;

char mp[200][200];
vector<char>b, d;

int main(){
    int n;
    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf(" %c", &mp[i][j]);
            }
        }
        int x = 1, y = 1;
        int left = 0, down = 0;
        b.push_back(mp[1][1]);
        while(1){
            if(x == n && y == 1)break;
            else if(y == n && x == 1)break;
            if(x == 1) left = 1;
            else if(y == 1)down = 1;
            if(left){
                y++;
                b.push_back(mp[x][y]);
                while(y != 1){
                    x++;
                    y--;
                    b.push_back(mp[x][y]);
                }
                left = 0;
            }else if(down){
                x++;
                b.push_back(mp[x][y]);
                while(x != 1){
                    y++;
                    x--;
                    b.push_back(mp[x][y]);
                }
                down = 0;
            }
        }

        x = n, y = n;
        int right = 0, up = 0;
        d.push_back(mp[x][y]);
        while(1){
            if(x == 1 && y == n)break;
            else if(y == n && x == 1) break;
            if(x == n){
                right = 1;
            }else if(y == n){
                up = 1;
            }
            if(right){
                y--;
                d.push_back(mp[x][y]);
                while(y != n){
                    x--;
                    y++;
                    d.push_back(mp[x][y]);
                }
                right = 0;
            }else if(up){
                x--;
                while(x != n){
                    x++;
                    y--;
                    d.push_back(mp[x][y]);
                }
            }
        }
        reverse(d.begin(), d.end());
        for(int i = 0; i < b.size(); i++){
            printf("%c", b[i]);
        }
        for(int i = 0; i < d.size(); i++){
            printf("%c", d[i]);
        }
    }
}