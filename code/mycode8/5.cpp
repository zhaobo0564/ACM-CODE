#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7;
typedef long long ll;

int n, a[N];

int prime[N],vis[N],top=1;

void Prime(){
    for(int i=2;i<N;i++){
        if(!vis[i])prime[top++]=i;
        for(int j=1;j<top&&prime[j]*i<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;

        }
    }
}

map<int, int> cnt;



int main() {
    Prime();
    top = 553;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int gcd = a[1];

    for (int i = 2; i <= n; i++) {
        gcd = __gcd(a[i], gcd);
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i] / gcd;
    }

    for (int i = 1; i<= n; i++) {
        for (int j = 1; j < top; j++) {
            if (a[i] < prime[j]) {
                break;
            }
            if (a[i] % prime[j] == 0) {
                cnt[prime[j]]++;
                while (a[i] % prime[j] == 0) {
                    a[i] /= prime[j];
                }
            } 
            
        }
        if (a[i] > 1) {
            cnt[a[i]]++;
        } 
    }
    int ans = 0;
    for (auto it: cnt) {
        ans = max(ans, it.second);
    }

    ans = n - ans;
    if (ans == n) {
        puts("-1");
    } else {
        printf("%d\n", ans);
    }

    
}