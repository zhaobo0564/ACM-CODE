#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
char s[N];
int t, n;
int sum[N];

int main(){
    scanf("%d", &t);
    while(t--){
        int k;
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        int ans = 0;
        int cnt = 0;
        int f = 0;
        for(int i = 0; i <= k; i++){
            if(s[i] == '1'){
                f = 1;
                break;
            }
        }
        if(f == 0)s[0] = '1', ans++;
        int pos;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                pos = i;
                break;
            }
        }
        for(int i = pos + 1; i < n; i++){
         //   cout << i << " " << cnt << endl;
           if(s[i] == '0'){
               cnt++;
               if(cnt > k){
                   s[i] = '1';
                   cnt = 0;
                   ans++;
               }
           }else{
               if(cnt < k){
                   ans--;
               }
               cnt = 0;
           }
        }
       // cout << s << endl;
        printf("%d\n",ans);
    }

}