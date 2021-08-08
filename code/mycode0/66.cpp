#include<bits/stdc++.h>
using namespace std;

char mp[107][107];
int drx[] = {0, 1, -1, 0};
int dry[] = {1, 0, 0, -1};

int n, m, k, v[5], vis[107][107];
int sx, sy;
vector<pair<int, int> >g;
vector<int>q;
int ans = INT_MAX;
struct node{
    int x, y, step;
};

bool judge(int x, int y){
    if(x < 1 || y < 1 || x > n || y > m)
        return false;
    return true;
}

int bfs(int x, int y, int ex, int ey){
    queue<node>q;
    q.push({x, y, 0});
    while(q.size()){
        node cd =q.front();
        q.pop();
        if(cd.x == ex && cd.y == ey){
            return cd.step;
        }
        for(int i = 0; i < 4; i++){
            int nx = cd.x + drx[i];
            int ny = cd.y + dry[i];
            if(!vis[nx][ny] && mp[nx][ny] == '.' && judge(nx, ny)){
                vis[nx][ny] = 1;
                q.push({nx, ny, cd.step + 1});
            }
        }
    }
    return -1;
}

void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            vis[i][j] = 0;
        }
    }
}

void dfs(int p){
    if(p == k){
        int ssx = sx, ssy = sy;
        int sum = 0, f = 0;
       
        for(int i = 0; i < k; i++){ 
            //cout << q[i] << " ";
            init();
            int cnt = bfs(ssx, ssy, g[q[i]].first, g[q[i]].second);
            ssx = g[q[i]].first, ssy = g[q[i]].second;
            if(cnt != -1){
                sum += cnt;
            }else{
                f = 1;
                break;
            }
        }
        //cout << endl;
       // cout << "sum = " << sum << endl;
        if(!f){
            ans = min(ans, sum);
        }
    }
    for(int i = 0; i < k; i++){
        if(v[i] == 0){
            v[i] = 1;
            q.push_back(i);
            dfs(p + 1);
            v[i] = 0;
            q.pop_back();
        }
    }
}


int main(){
    while(~scanf("%d %d", &n, &m) && n){  
        ans = INT_MAX;
        for(int i = 1; i <= 4; i++)v[i] = 0;
        q.clear(), g.clear();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m ; j++){
                scanf(" %c", &mp[i][j]);
                if(mp[i][j] == '@'){
                    sx = i, sy = j;
                }
            }
        }
        scanf("%d", &k);
        int f = 0;
        for(int i = 1; i <= k; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            if(mp[x][y] == '#') f = 1;
            g.push_back(make_pair(x, y));
        }
        if(f){
            printf("-1\n");
        }else{
            dfs(0);
            if(ans == INT_MAX){
                printf("-1\n");
            }else{
                printf("%d\n", ans);
            }
        }


    }
}
