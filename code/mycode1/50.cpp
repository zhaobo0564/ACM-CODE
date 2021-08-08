#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
typedef long long ll;
int n, m;
ll a[N], cns[N], cnb[N];
long long  ans = 0;

int main(){
    scanf("%d %d", &n, &m);
    int pos;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(a[i] == m){
            pos = i;
        }
    }
    int b = 0, s = 0;
    int odd = 0, even = 0;
    for(int i = pos + 1; i <= n; i++){
        if(a[i] >= m) b++;
        else s++;
        if(b % 2 == 0 && s % 2 == 0 && b == s){
            ans++;
            even++;
        }else if(b % 2 == 0 && s % 2 == 1 && b - s == 1){
            ans++;
            odd++;
        }else if(b % 2 == 1 && s % 2 == 1 && b == s){
            ans++;
            even++;
        }else if(b % 2 == 1 && s % 2 == 0 && b - s == 1){
            ans++;
            odd++;
        }
        if(s > b){
            cns[ s - b]++;
        }else{
            cnb[b - s]++;
        }
        
    }


    b = 0, s = 0;
    for(int i = pos - 1; i > 0; i--){
        if(a[i] > m) b++;
        else s++;
        if(b % 2 == 0 && s % 2 == 0 && b == s){
            ans++;
            ans += cnb[0];
            ans += cnb[1];
        }else if(b % 2 == 0 && s % 2 == 1 && b - s == 1){
            ans++;
            ans += cnb[0];
            ans += cns[1];
        }else if(b % 2 == 1 && s % 2 == 1 && b == s){
            ans++;
            ans += cnb[0];
            ans += cnb[1];
        }else if(b % 2 == 1 && s % 2 == 0 && b - s == 1){
            ans++;
             ans += cnb[0];
            ans += cns[1];
        }
        
        
        else{
            if(s > b){
                ans += cnb[s - b];
                ans += cnb[s - b + 1];
            }else{
                ans += cns[b -s];
                ans += cns[b -s - 1];
            }
        }

    }

    printf("%lld\n", ans + 1);


}