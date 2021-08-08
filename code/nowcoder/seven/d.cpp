#include<iostream>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
#define ll long long
ll n,k,vis[4000][4000];
queue<pair<ll,ll > >ho;
pair<ll,ll >lin;
void bfs(){
	for(ll i=1;i<=k;i++){
		ho.push({1,i});
	}
	while(!ho.empty()){
		lin=ho.front();
		ho.pop();
		if(vis[lin.first][lin.second]==1)continue;
		vis[lin.first][lin.second]=1;
		if(lin.first+lin.second<=n){
			ho.push({lin.first+lin.second,lin.second});
		}
		if(lin.first*lin.second<=n){
			ho.push({lin.first*lin.second,lin.second});
		}

	}
}

int h[4000];
map<int, int>q;

int main(){
	while (1) {
    	q.clear();
		memset(vis, 0, sizeof(vis));
		memset(h, 0, sizeof(h));
		scanf("%lld%lld",&n,&k);
	bfs();
	int cnt=0;

	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(vis[i][j]==1){
				cnt++;
				//printf("1 ");
				h[j] += vis[i][j];
                printf("%d %d\n", i, j);
			}else {
				//printf("0 ");
			}
		}
		puts("");
	}puts("");
	
	puts(" ");
    int sum = 0;
	for (int i = 1; i <= k; i++) {
        if (h[i] != 1) {
            sum += h[i];
        }
        cout << h[i] << " " ;
	
	}
    cout << endl;
  
	
	printf("\nans = %d\n",cnt);	
   // printf("sum = %d\n", sum);
	}

}

//1 4 8 13 18 24 30 36 43 50 56
