#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
const int N =207;

vector<pair<int, double> >g[N];
double dist[N];
int vis[N];

struct node{ 
    int u;
    double w;
    node();
    node(int u, double w){
        this->u = u;
        this->w = w;
    }
    bool operator < (const node a)const{
        return w > a.w;
    }
};

void dijstra(){
    priority_queue<node>q;
    q.push(node(1, 0));
    dist[1] = 0.0;
    while(!q.empty()){
        node cd = q.top();
        q.pop();
        if(vis[cd.u])continue;
        vis[cd.u] = 1;
        for(int i = 0; i < g[cd.u].size(); i++){
            int to = g[cd.u][i].first;
            double cost = g[cd.u][i].second;
            if(dist[to] >max( dist[cd.u] , cost)){
                dist[to] =max( dist[cd.u], cost);
                q.push(node(to, dist[to]));
            } 
        }
    }
}

struct power{
    int x, y;
}p[N];

double get(power a, power b){
    return sqrt(1.0*(a.x - b.x) * 1.0* (a.x - b.x) +1.0*(a.y - b.y) * 1.0*(a.y - b.y));
}

void init(int n){
    for(int i = 1; i <= n; i++){
        dist[i] = 1e9;
        vis[i] = 0;
        g[i].clear();
    }
}

int main(){
    int n, top = 1;
    while(~scanf("%d", &n) && n){
        init(n);
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)continue;
                g[i].push_back(make_pair(j, get(p[i], p[j])));
                g[j].push_back(make_pair(i, get(p[i], p[j])));
            }
        }
        dijstra();
        printf("Scenario #%d\n", top++);
        printf("Frog Distance = %.3f\n\n", dist[2]);
    }
    return 0;
}