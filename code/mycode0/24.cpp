#include<bits/stdc++.h>
using namespace std;

int t, n;
const int N = 1e5 + 7;
int a[N];
set<int>q;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            q.insert(a[i]);
        }
        printf("%d\n",q.size());
        q.clear();
    }
}