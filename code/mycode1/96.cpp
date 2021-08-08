#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, m;
    cin >> t ;
    while(t--){
        cin >> n >> m;
        if(n == 1 || m == 1){
            printf("YES\n");
        }else if(n == 2 && m == 2){
            printf("YES\n");
        }else{
            puts("NO");
        }

    }

}