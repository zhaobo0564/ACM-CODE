#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n, k;

vector<int>all;
vector<int>alice;
vector<int>bob;

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);
        if(a && b){
            all.push_back(t);
        }else if(a){
            alice.push_back(t);
        }else if(b){
            bob.push_back(t);
        }
    }
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    int al = alice.size();
    int bo = bob.size();
    int cnt = all.size() + min(al, bo);
    if(cnt < k){
        puts("-1");
    }else{
        for(int i = 0; i < min(al, bo); i++){
            all.push_back(alice[i] + bob[i]);
        }
        sort(all.begin(), all.end());
        long long ans = 0;
        for(int i = 0; i < k; i++){
            ans = ans + 1ll * all[i];
        }
        printf("%lld\n", ans);
    }
}