#include<bits/stdc++.h>
using namespace std;
int t, n;
const int N = 10007;
int fa[N];

int find(int x){
    if(x != fa[x]){
        return fa[x] = find(fa[x]);
    }
    return x;
}

int main(){
    int t; scanf("%")
}