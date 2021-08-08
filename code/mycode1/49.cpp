#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int a[N], sum[N], vis[10];
string s;

int main(){
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++){
        a[i + 1] = s[i] - '0';
    }
    int ans = 0;
    int cnt =0;

    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
        sum[i] = sum[i] % 3;
        cnt += a[i];
        if(a[i] % 3 ==0){
            ans++;
            for(int j = 0; j < 3; j++)vis[j] = 0;
            cnt = 0;

        }else{
            if(vis[sum[i]] || cnt % 3 == 0){
                ans++;
                for(int j = 0; j < 3; j++)vis[j] = 0;
                cnt  = 0;
            }else{
                vis[sum[i]]++;
            }

        }

    }
    printf("%d\n",ans);

}