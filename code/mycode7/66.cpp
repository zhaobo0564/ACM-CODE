    #include<iostream>
    #include<vector>
    #include<queue>
    #include<algorithm>
    using namespace std;
    #define ll long long
    ll t,n;
    ll ans=0;
    ll f[1000007];
    vector<ll>ho[1000007];
    ll dfs(ll p,ll d){
        priority_queue<ll,vector<ll>,greater<ll> >sa;
        ll now=0;
        if(ho[p].size()!=0){
            for(int i=0;i<ho[p].size();i++){
                now=dfs(ho[p][i],d+1);
                sa.push(now);
            }
            ll lin;
            while(!sa.empty()){
                if(sa.size()==1){
                    break;
                }
                lin=sa.top();
                sa.pop();
                if(lin-d<=d){
                    ans+=(lin-d)*2;
                }
                else{
                    ans+=lin;
                }
            }
            return sa.top();
        }
        else{
            return d;
        }
    }
    int main(){
        scanf("%lld",&t);
        int o=0;
        while(t--){
            o++;
            ans=0;
            scanf("%lld",&n);
            for(int i=1;i<=n;i++){
                ho[i].clear();
            }
            for(int i=2;i<=n;i++){
                scanf("%lld",&f[i]);
                ho[f[i]].push_back(i);
            }
            ans+=dfs(1,0);
            printf("Case #%d: %lld\n",o,ans);
        }
    }