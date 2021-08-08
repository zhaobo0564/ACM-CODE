#include<bits/stdc++.h>
using namespace std;

const int N = 100;
struct node {
    int u, d;

    bool  operator < (const node x) const {
        return d > x.d;
    }
};

int dist[N], vis[N];
vector<int> Map[N];

int dijstra(int start, int end) {
    for (int i = 1; i < N; i++) {
        dist[i] = 1e5;
        vis[i] = 0;
    }
    priority_queue<node> q;
    q.push({start, 0});
    dist[start] = 0;
    while(!q.empty()) {
        node cd = q.top();
        q.pop();
        if (vis[cd.u]) continue;
        vis[cd.u] = 1;
        for (int to: Map[cd.u]) {
            if (dist[to] > dist[cd.u] + 1) {
                dist[to] = dist[cd.u] + 1;
                q.push({to, dist[to]});
            }
        }
    }
    return dist[end];
}

int main() {
    Map[1].push_back(2), Map[2].push_back(1);
    Map[1].push_back(5), Map[5].push_back(1);
    Map[1].push_back(4), Map[4].push_back(1);
    Map[5].push_back(4), Map[4].push_back(5);
    Map[5].push_back(6), Map[6].push_back(5);
    Map[2].push_back(3), Map[3].push_back(2);
    Map[4].push_back(3), Map[3].push_back(4);
    Map[4].push_back(7), Map[7].push_back(4);
    Map[3].push_back(8), Map[8].push_back(3);
    Map[3].push_back(9), Map[9].push_back(3);
    Map[6].push_back(7), Map[7].push_back(6);
    Map[6].push_back(12), Map[12].push_back(6);
    Map[6].push_back(13), Map[13].push_back(6);
    Map[7].push_back(12), Map[12].push_back(7);
    Map[7].push_back(11), Map[11].push_back(7);
    Map[8].push_back(9), Map[9].push_back(8);
    Map[9].push_back(11), Map[11].push_back(9);
    Map[9].push_back(10), Map[10].push_back(9);
    Map[12].push_back(11), Map[11].push_back(12);
    Map[12].push_back(13), Map[13].push_back(12);
    Map[11].push_back(13), Map[13].push_back(11);
    Map[10].push_back(13), Map[13].push_back(10);

    cout << "不经过矿山的起点到终点最短路：" << dijstra(1, 13) << endl;
    cout << "经过矿山的起点到终点的最短路：" << dijstra(1, 9) + dijstra(9, 13)  << endl;


}