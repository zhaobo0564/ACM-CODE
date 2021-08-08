#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x;
    scanf("%lld", &x);
    long long cnt = sqrt(x);
    vector<long long>v;
    v.push_back(cnt * cnt);
    v.push_back((cnt + 1) * (cnt + 1));
    v.push_back((cnt - 1) * (cnt - 1));
    long long ans , minn = LLONG_MAX;
    for(long long i: v){
        if(abs(i - x) < minn){
            minn = abs(i - x);
            ans = i;
        }
    }
    printf("%lld\n", ans);
}