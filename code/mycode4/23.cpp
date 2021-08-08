#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

struct node{
    int x, y, pos;
};

vector<node>g;

bool cmp(node a, node b){
    if(a.x == b.x && a.y == b.y)
        return a.pos < b.pos;
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

int ans[100007];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        g.push_back({x, y, 0});
    }
    for(int i = 1; i <= m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        g.push_back({x, y, i});
    }
    sort(g.begin(), g.end(), cmp);
    int cnt = 0;
    for(int i = 0; i < g.size(); i++){
        if(g[i].pos){
            ans[g[i].pos] = cnt;
        }else{
            cnt++;
        }
    }
    for(int i = 1; i <= m; i++){
        printf("%d\n", ans[i]);
    }

}
/*
5 5
1 1
2 2 
3 3
2 1
1 2
3 3
4 4
2 2
10 2
10 10*/