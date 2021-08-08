#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], n, k;

int main(){
    scanf("%d %d", &n, &k);
    int pos = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] == 1){
            pos = i;
        }
    }
    int ans = 0, minn = INT_MAX;
    for(int i = max(1, pos - k + 1); i <= pos; i++){
        int l = i - 1;
        int r = n -(i + k - 1);
        if(r < 0) r = 0;
        ans = l / (k - 1) + r / (k - 1) + 1;
        if(l % (k - 1))ans++;
        if(r % (k - 1))ans++;
        minn = min(ans, minn);
    }
    printf("%d\n", minn);
}