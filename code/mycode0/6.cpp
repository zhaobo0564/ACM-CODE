#include<bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){
    return x > y;
}

int a[107], t, n;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        sort(a + 1, a + n +1, cmp);
        for(int i = 1; i <= n; i++){
            printf("%d ",a[i]);
        }
        puts("");
    }
}