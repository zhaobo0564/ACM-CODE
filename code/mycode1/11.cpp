#include<bits/stdc++.h>
using namespace std;

int mp[20][20];


int main(){
    int t; scanf("%d", &t);
    while(t--){
        for(int i = 1; i <= 9; i++){
           for(int j = 1; j <= 9; j++){
               scanf("%1d", &mp[i][j]);
           }
        }
        mp[1][1] += 1;
        mp[2][4] += 1;
        mp[3][7] += 1;
        mp[4][2] += 1;
        mp[5][5] += 1;
        mp[6][8] += 1;
        mp[7][3] += 1;
        mp[8][6] += 1;
        mp[9][9] += 1;
        for(int i = 1; i <= 9; i++){
            for(int j =  1; j <= 9; j++){
                if(mp[i][j] == 10){
                    printf("1");
                }else{
                    printf("%d",mp[i][j]);
                }
            }
            puts("");
        }



    }

}