#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>g[1007];
int a[1007], b[1007];

int main(){
    scanf("%d", &n);
    if(n % 2  == 0){
        for(int i = 1; i < n; i++){
            printf("%d ", 1);
        }
        printf("%d\n", n + 1);
    }else{
         for(int i = 1; i < n; i++){
            printf("%d ", 1);
        }
        printf("%d\n", n + 1);
        for(int i = 1; i <= n; i++){
            printf("2 ");
        }
        puts("");
    }



}