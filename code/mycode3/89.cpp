    #pragma GCC optimize(2)
    #include<bits/stdc++.h>
    #define ll long long
    #define maxn 1005
    #define inf 1e9
    #define pb push_back
    #define rep(i,a,b) for(int i=a;i<=b;i++)
    #define per(i,a,b) for(int i=a;i>=b;i--)
    using namespace std;
    const ll mod=1e9+7;
    inline ll read()
    {
        ll x=0,w=1; char c=getchar();
        while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
        while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
        return w==1?x:-x;
    }
    const int N=2e2+10;
    vector<int>G[N];
    int sz[N],u[N*N],v[N*N];
    int n,m;
    ll C[N][N],ans;
    ll get(int n,int m)
    {
        if(m>n) return 0;
        return C[n][m];
    }
    void add(ll &x,ll y)
    {
        x=(x+y)%mod;
    }
    void init()
    {
        C[0][0]=1;
        for(int i=1;i<N;++i) C[i][0]=C[i][i]=1;
        for(int i=2;i<N;++i){
            for(int j=1;j<i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    void solve()
    {
        for(int i=1;i<=m;++i){
            set<int>st;
            for(int va:G[u[i]]) st.insert(va);
            for(int va:G[v[i]]) st.insert(va);
     
     
            int s2=sz[u[i]]+sz[v[i]]-st.size();//重复的点
     
     
            int s1=sz[u[i]]-s2-1;
            int s3=sz[v[i]]-s2-1;
            //printf("u:%d v:%d\n",u[i],v[i]);
            //printf("s1:%d s2:%d s3:%d\n",s1,s2,s3);
     
            for(int j=0;j<=min(s2,3);++j){
                //if(s1+j>=3&&s3+s2-j>=2)
                add(ans,get(s1,3-j)*get(s2,j)%mod*get(s3+s2-j,2)%mod);
            }
            for(int j=0;j<=min(s2,2);++j){
                //if(s1+j>=2&&s3+s2-j>=3)
                add(ans,get(s1,2-j)*get(s2,j)%mod*get(s3+s2-j,3)%mod);
            }
     
     
     
        }
    }
    int main()
    {
        //puts("***");
     
        init();
        n=read(),m=read();
        for(int i=1;i<=m;++i){
            u[i]=read(),v[i]=read();
            sz[u[i]]++,sz[v[i]]++;
            G[u[i]].push_back(v[i]);
            G[v[i]].push_back(u[i]);
        }
        solve();
        printf("%lld\n",ans);
    }
    /*
    7 6
    1 2
    2 3
    2 4
    2 5
    5 6
    5 7
    */