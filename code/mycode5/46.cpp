// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int t, n;
//     scanf("%d", &t);
//     while (t--) {
//         scanf("%d", &n);
//         int a = 6, b = 10, c = 14;

//         int sum = a + b + c;
//         if (n - sum > 0 && n - sum != 6 && n - sum != 10 && n - sum != 14) {
//             puts("YES");
//             printf("%d %d %d %d\n", a, b, c,n - sum);
//         } else if (n - sum == 6) {
//             puts("YES");
//             printf("6 10 15 5\n");
//         } else if (n - sum == 10) {
//             puts("YES");
//             puts("6 10 15 9");
//         } else if (n - sum == 14) {
//             puts("YES");
//             puts("6 10 15 13");
//         }
        
//         else {
//             puts("NO");
//         }
//     }
// }

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int N=1e6+7;

ll p[N], h[N] , uh[N], hp[N], _p[N];

vector <int> G[N];

ll isnot[N];

vector<int>g[N];
void getys(){
        for(int i=2;i<N;i++){
            if(!isnot[i]) {
                for (int j = i; j < N; j += i) {
                    isnot[j] = true;
                    G[j].push_back(i);
                }
            }
    }

    
}

ll sum[N];

void init(){
    int top = 0;
    for(int i = 1; i <= 1000; i++){
        for(int j = i ; j < N; j += i){
            if(i * i <= j){
                sum[j] += i;
                if(j / i != i){
                    sum[j] += (j / i);
                }
            }
        }
    }

}

bool check(ll P,ll H){
    ll a = 10;
    a++;
	ll x,y;
	x=(P+H)/2;
	y=x-H + a;
    y -= a;

	if(x+y==P&&x>=0&&y>=0) return 1;
	else return 0;
}

int flag=1;

ll read() {
    ll x;
    scanf("%lld", &x);
    return x;
}

void dfs(int u,int fa){
	for(auto to:G[u]){
        if (to != fa) {
            dfs(to, u);
            p[u]+=p[to];
        }
		
	}
	hp[u]=(p[u]+h[u])/2;
	uh[u]=hp[u]-h[u];
	if(hp[u]+uh[u]!=p[u]||uh[u]<0||hp[u]<0) flag=0;
}

void dfs1(int u,int fa){
	ll tmp=0;
	for(auto to:G[u]){
		if (to != fa) {
            dfs1(to,u);
		    tmp+=uh[to]; 
        }
		
	}
	ll t=0;
	if(uh[u]<=_p[u]) t=0;
	else t=uh[u]-_p[u];
	if(tmp<t) flag=0;
}

int main(){
    init();
	int T = read();
    int n, m;
	while(T--){
		n = read(), m = read();
		for(int i=1;i<=n;i++) G[i].clear();

		for(int i=1;i<=n;i++) _p[i]=p[i]=read();
		for(int i=1;i<=n;i++) h[i]=read();

		for(int i=1;i<n;i++){
			int u = read(),v=read();
			G[u].push_back(v);
			G[v].push_back(u);
		}

		flag=1;
		dfs(1,0);
		dfs1(1,0);
  
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}



