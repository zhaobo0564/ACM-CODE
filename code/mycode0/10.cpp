#include<bits/stdc++.h>
using namespace std;

int t;
char s[10][10];

int main(){
    scanf("%d", &t);
    while(t--){
        for(int i = 1; i <= 3; i++){
            scanf("%s", s[i]);
        }
        int f = 0, f1 = 0;
        for(int i = 1; i <= 3; i++){
            for(int j = 0; j < 3; j++){
                if(s[i][j] == 'A'){
                    if(s[i][j + 1] == 'A' && s[i][j + 2] == 'A'){
                        f++;
                        break;
                    }
                    if( s[i + 1][j] == 'A' && s[i + 2][j] == 'A'){
                        f++;
                        break;
                    }
                    if(s[i + 1][j + 1] == 'A' && s[i + 2][j + 2] == 'A'){
                        f++;
                        break;
                    }
                    if( i == 2 && j == 1){
                        if(s[i - 1][j + 1] == 'A' && s[i + 1][j - 1] == 'A'){
                            f++;
                            break;
                        }
                    }
                }
            }
            if(f)break;
        }

         for(int i = 1; i <= 3; i++){
            for(int j = 0; j < 3; j++){
                if(s[i][j] == 'B'){
                    if(s[i][j + 1] == 'B' && s[i][j + 2] == 'B'){
                        f1++;
                        break;
                    }
                    if(s[i][j] == 'B' && s[i + 1][j] == 'B' && s[i + 2][j] == 'B'){
                        f1++;
                        break;
                    }
                    if(s[i][j] == 'B' && s[i + 1][j + 1] == 'B' && s[i + 2][j + 2] == 'B'){
                        f1++;
                        break;
                    }
                    if( i == 2 && j == 1){
                        if(s[i - 1][j + 1] == 'B' && s[i + 1][j - 1] == 'B'){
                            f1++;
                            break;
                        }
                    }
                }
            }
            if(f1)break;
        }
        if(f1 && f){
            printf("invalid\n");
        }else if(f){
            printf("Yes\n");
        }else if(f1){
            printf("No\n");
        }else{
            printf("draw\n");
        }
    }
}