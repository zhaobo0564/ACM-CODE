#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int  N = 1e5 + 7;

vector<ll>g;
int n; 
int main(){
    int t; scanf("%d", &t);
    for(int i = 1; i < 1e5; i++){
        g.push_back(i + i + 1);
    }

    while(t--){
        scanf("%d", &n);
        if( n > 1&& n % 2){
            printf("%d = %d + %d\n", n, n / 2, n / 2 + 1);
        }else{
            if(n % 3 == 0){
                printf("%d = %d + %d + %d\n", n, n / 3  - 1, n / 3, n / 3 + 1);
            }else{
                int cnt = n / 2;
                int p = lower_bound(g.begin(), g.end(), cnt) - g.begin();
                if(p && g[p] == cnt){
                    printf("%d = %d + %d + %d + %d\n",n, p, p + 1 , p + 2, p + 3);
                }else{
                    printf("IMPOSSIBLE\n");
                }
            }
        }


    }


   
    

}