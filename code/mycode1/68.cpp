#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int sum[N], n, a[N], k;
vector<int>g[N];

map<int, pair<int, int> >q;


int main(){
    scanf("%d", &k);
    for(int i = 1; i <= k; i++){
        scanf("%d", &n);
        for(int j = 1; j <= n; j++){
            int x; scanf("%d", &x);
            g[i].push_back(x);
            sum[i] += x;
        }
    }

    int f = 0;
    for(int i = 0; i < g[1].size(); i++){
       
        q[sum[1] - g[1][i]] = make_pair(1, i + 1);
    }
    int ii,x, jj, y;
    for(int i = 2; i <= k; i++){
        for(int j = 0; j < g[i].size(); j++){
            if(q[sum[i] - g[i][j]].first){
               // cout << sum[i] - g[i][j] << endl;
                f = 1;
                ii = q[sum[i] - g[i][j]].first;
                x = q[sum[i] - g[i][j]].second;
                jj = i;
                y = j + 1;
                break;
            }
        }
        for(int j = 0; j < g[i].size(); j++){
            q[sum[i] - g[i][j]] = make_pair(i, j + 1);
        }
    }
    if(f){
        printf("YES\n");
        printf("%d %d\n%d %d\n", ii, x, jj, y);
    }else{
        puts("NO");
    }

}