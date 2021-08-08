#include<bits/stdc++.h>
using namespace std;
int mp[20][20];


int main(){
    int n, id, x;

    scanf("%d", &n);
    for(int i = 1; i <= 10; i++){
        mp[11][i] = 1;
    }
    while(n--){
        scanf("%d %d", &id, &x);
        if(id == 1){
            int f = 0;
            for(int i = 1; i <= 11; i++){
                for(int j = x; j <= x + 1; j++){
                    if(mp[i][j]){
                         f = 1;
                         if(i != 1){
                            mp[i - 1][x] = 1;
                            mp[i - 1][x + 1] = 1;
                            mp[i - 2][x] = 1;
                            mp[i - 2][x + 1] = 1;   
                         }
                         break;
                    }
                }
                if(f)break;
            }
        }else if(id == 2){
            int f = 0;
            for(int i = 1; i <= 11; i++){
                for(int j = x; j <= x + 2; j++){
                    if(mp[i][j]){
                        f = 1;
                        if( i != 1){
                            mp[i - 1][x] = 1;
                            mp[i - 1][x + 1] = 1;
                            mp[i - 1][x + 2] = 1;
                            mp[i - 2][x] = 1;
                        }
                        break;
                    }
                }
                if(f)break;
            }
        }else if(id == 3){
            int f = 0;
            for(int i = 1; i <= 11; i++ ){
                for(int j = x; j <= x + 3; j++){
                    if(mp[i][j]){
                        f = 1;
                        if(i != 1){
                            mp[i - 1][x] = 1;
                            mp[i - 1][x + 1] = 1;
                            mp[i - 1][x + 2] = 1;
                            mp[i - 1][x + 3] = 1;
                        }
                        break;
                    }
                }
                if(f)break;
            }
        }else{
            int f = 0;
            for(int i = 1; i<= 11; i++){
                for(int j = x; j <= x + 2; j++){
                    if(mp[i][j]){
                        f = 1;
                        if(i != 1){
                            mp[i - 1][x] = 1;
                            mp[i - 1][x + 1] = 1;
                            mp[i - 1][x + 2] = 1;
                            mp[i - 2][x + 1] = 1;
                        }
                        break;
                    }
                }
                if(f)break;
            }
        }
    }
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            printf("%d ", mp[i][j]);
        }
        puts("");
    }
}