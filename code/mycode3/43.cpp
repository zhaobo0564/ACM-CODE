#include<bits/stdc++.h>
using namespace std;

struct node{
    int id, sum;
};

vector<node>g;
bool cmp(node x, node y){
    if(x.sum == y.sum)return x.id < y.id;
    return x.sum > y.sum;
}

int main(){
    int n;
    int a, b, c, d;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        g.push_back({a, b + c * 2 + d * 3});
    }
    sort(g.begin(), g.end(), cmp);
    printf("%d %d\n", g[0].id, g[0].sum);
}