#include<bits/stdc++.h>
using namespace std;
int a[100], t, n;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int minn = 1e9;
        for(int i = 1; i < n; i++){
            minn = min(minn, a[i + 1] - a[i]);
        }
        printf("%d\n", minn);
       
    }
}