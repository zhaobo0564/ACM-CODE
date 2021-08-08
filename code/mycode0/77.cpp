#include<bits/stdc++.h>
using namespace std;

int n, m;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        n--;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            int x; scanf("%d", &x);
            sum += x;
        }
        int ans;
        if(sum % n == 0){
            ans = sum / n - 1;
        }else {
            ans = sum / n ;
        }
        sum = 0;
        for(int i = 1; i <= m; i++){
            int x; scanf("%d", &x);
            sum += x;
        }
        if(sum % m == 0){
            sum = sum / m + 1;
        }else{
            sum = sum / m + 1;
        }
        printf("%d %d\n", sum, ans);

    }
  


}