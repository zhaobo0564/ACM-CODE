#include<bits/stdc++.h>
using namespace std;

long long t, n;

int main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", (n - (n / 2 + 1)));
    }
}