#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

int t, n, a[N];
vector<int>v;

int main(){
    scanf("%d", &t);
    while(t--){
        v.clear();
        a[0] = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        // int pos = -1;
        // for(int i = 2; i <= n; i++){
        //     if(a[1] < a[i]){

        //     }else{
        //         pos = i;
        //         break;
        //     }
        // }
        // v.push_back(a[1]);
        // if(pos == -1){
        //     pos = n + 1;
        // }
        // for(int i = pos; i < n; i++){
        //     if(a[i] < a[i + 1]){

        //     }else{
        //         v.push_back(a[i]);
        //     }
        // }
        // v.push_back(a[n]);
        // int f = 0;
        // for(int i = 1; i < v.size(); i++){
        //     if(v[0] > v[i]){
        //         f++;
        //         break;
        //     }
        // }
        // for(int i = 0; i < v.size() - 1; i++){
        //     if(v[v.size() - 1] < v[i]){
        //         f++;
        //         break;
        //     }
        // }
        int f = 0;
        if(a[n] > a[1]) f = 0;
        else f = 2;
        if(f == 2)puts("NO");
        else puts("YES");

    }
}