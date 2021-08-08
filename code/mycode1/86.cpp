#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], n;
map<int, int>v;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        v[i - a[i]]++;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        v[i - a[i]]--;
        ans += v[a[i]+i];
    }
    cout << ans << endl;
}