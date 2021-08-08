    #include<bits/stdc++.h>
    using namespace std;
     
    const int N = 1e5 + 7;
     
    int n, m;
    vector<int> g[N];
     
    bool cmp(int a, int b){
        return a > b;
    }
     
    int main(){
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            g[max(u, v)].push_back(min(u, v));
        }
        for(int i = 1; i <= n; i++){
            if(g[i].size()){
                sort(g[i].begin(), g[i].end(), cmp);
            }
        }
        for(int i = 2; i <= n; i++){
            if(g[i].size() == 0){
                g[i].push_back(0);
            }
        }
        for(int i = 2; i <= n; i++){
            if(g[i][0] + 1 < i){
                puts("YES");
                for(int j = 1; j <= n; j++){
                    printf("%d ", j);
                }
                puts("");
                for(int j = 1; j < i; j++){
                    printf("%d ", j);
                }
                printf("%d ", g[i][0] + 1);
                for(int j = i + 1; j <= n; j++){
                    printf("%d ", j);
                }
                puts("");
                return 0;
            }
        }

        if(g[n - 1][0] < n - 2){
            puts("YES");
            for(int i = 1; i <= n - 2; i++){
                printf("%d ", i);
            }
        }






        puts("NO");
        return 0;
    }