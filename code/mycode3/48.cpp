#include<bits/stdc++.h>
using namespace std;
int t, n, a[1000], b[1000];




int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
    
        }
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(a[i] > a[j]){
                    if(b[i] != b[j]){
                        swap(a[i], a[j]);
                        swap(b[i], b[j]);
                    }
                }
            }
        }
        int f = 0;
        for(int i = 1; i < n; i++){
            if(a[i] > a[i + 1]){
                f = 1;
                break;
            }
        }
        if(f)puts("No");
        else puts("Yes");
    }
}