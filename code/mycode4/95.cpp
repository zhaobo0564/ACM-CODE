#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000], n;

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
            if(i % 2){
                printf("%d ", -abs(a[i]));
            }else{
                printf("%d ", abs(a[i]));
            }
        }
        puts("");
    }
}