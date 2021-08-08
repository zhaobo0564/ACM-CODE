#include<bits/stdc++.h>
using namespace std;

int dp[1000][10000];

int s1, s2;

int main(){

    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 10000; j++){
            dp[i][j] = 1000;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j < 1000; j++){
            for(int k = 1; k < 10000; k++){
                if(j - i >= 0 && k - i * i >= 0)
                    dp[j][k] = min(dp[j][k], dp[j - i][k - i * i] + 1);
            }
        }
    }
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d", &s1, &s2);

        if(s1 >= 1000 || s2 >= 10000){
            printf("No solution\n");
        }else if(dp[s1][s2] > 100){
            printf("No solution\n");
        }else{
            vector<int>v;
            int ans = dp[s1][s2];
            while(1){
                for(int i = 1; i <= 9; i++){
                    if(dp[s1 - i][s2 - i * i] + 1 == dp[s1][s2]){
                        v.push_back(i);
                        s1 = s1 - i;
                        s2 = s2 - i * i;
                        break;
                    }
                }
                if(v.size() == ans){
                    break;
                }
            }
            for(int i: v){
                printf("%d", i);
            }
            puts("");
        }
    }    
    
}