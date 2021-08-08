#include<bits/stdc++.h>
using namespace std;

int t, n, k;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        if(n % 2 != k % 2){
            puts("No");
        }else{
            int cnt = n - k;
            if(2 * k > cnt){
                puts("No");
            }else{
                puts("Yes");
            }
        }
    }
}