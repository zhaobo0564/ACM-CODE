#include<bits/stdc++.h>
using namespace std;
int t, n, m;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        int an = n * m;
        int ans = an / 2;
        if(an % 2){
            ans++;
        }
        printf("%d\n", ans);
    }
}