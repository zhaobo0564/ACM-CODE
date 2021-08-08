#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

typedef long long ll;
ll a[N];

map<ll, int>v;

int n;

int main(){
    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            v[a[i]]++;
        }

        for(int i = 1; i <= n; i++){
            if(v[a[i]] >= (n + 1) / 2){
                printf("%d\n", a[i]);
                break;
            }
        }
        v.clear();
    }
}