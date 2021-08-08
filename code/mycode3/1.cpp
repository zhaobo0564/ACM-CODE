#include<bits/stdc++.h>
using namespace std;
int t, n, m, k;

int main(){
    printf("%5d\n", 1234);
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &m, &k);
        int cnt = n / k;
        if(cnt < m){
            int cn = (m - cnt)/ (k - 1);
            if((m -cnt) % (k - 1)) cn++;
            printf("%d\n", cnt - cn);
        }else{
            printf("%d\n", m);
        }
    }
}