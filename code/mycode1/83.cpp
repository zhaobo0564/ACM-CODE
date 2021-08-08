#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

int c[N];

int main(){
    int n;
    while(~scanf("%d", &n) && n){
        for(int i = 1; i <= n; i++){
            int l, r;
            scanf("%d %d", &l, &r);
            c[l]++;
            c[r + 1]--;
        }
        for(int  i = 1; i <= n; i++){
            c[i] += c[i - 1];
        }
        for(int  i = 1; i < n; i++){
            printf("%d ", c[i]);
        }
        printf("%d", c[n]);
        for(int i = 1; i <= n + 1; i++){
            c[i] = 0;
        }
        puts("");
    }
    
}