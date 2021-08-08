    #include<bits/stdc++.h>
    using namespace std;
     
    const int N = 3007;
     
    char a[N];
     
    int n, k;
    vector<int> g[3000007];
     
    map<int, int> vis[3000007];
    vector<int> ans[3000007];
     
    void work(int x){
        for(int i = 1; i < n ; i++){
            if(a[i] == 'R'){
                if(a[i + 1] == 'L'){
                    g[x].push_back(i);
                    swap(a[i], a[i + 1]);
                    i++;
                }
            }
        }
    }
     
     
    int main(){
        scanf("%d %d",&n, &k);
        scanf("%s", a + 1);
        int minn = 0, maxn = 0;
        work(minn);
        while(g[minn].size() && minn <= k){
            maxn += g[minn].size();
            minn++;
            work(minn);
        }
      
        if(minn <= k && k <= maxn){
            int id = 0;
            int t = 0;
            int cnt = -1;
            int ans = 0;
            while(1){
                int f = 0;
                cnt = -1;
                for(int i = 0; i < g[t].size(); i++){
                    if(i == g[t].size() - 1){
                        id++;
                    }
                    if(ans + minn - id < k){
                        printf("1 %d\n", g[t][i]);
                        ans++;
                        if(id != t)cnt = -1;
                        else cnt = i;
                    }else{
                        f = 1;
                        break;
                    }
                }
                t++;
                if(f)break;
            }
            cnt++;
            for(int i = id; i < minn; i++){
                if(i == id){
                    printf("%d ", g[i].size() - cnt);
                    for(int j = cnt; j < g[i].size(); j++){
                        printf("%d ", g[i][j]);
                    }
                    printf("\n");
                    continue;
                }
                printf("%d ", g[i].size());
                for(auto j: g[i]){
                    printf("%d ", j);
                }
                puts("");
            }
     
     
        }else{
            printf("-1\n");
        } 
        
        
     
        
     
    }