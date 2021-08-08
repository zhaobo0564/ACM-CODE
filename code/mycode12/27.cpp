#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[507];
ll n, ans = 0;
ll   cnt[507];




int vis[507][507], p[507];
vector<int> g[507];
bool match(int x, int f) {
    for (int i = 0; i < g[x].size(); i++) {
        int to = g[x][i];
        if (vis[f][to] == 0) {
            vis[f][to] = 1;
            if (p[to] == 0 || match(p[to], f)) {
                p[to] = x;
                return true; 
            }
        }
    }
    return false;
}

bool check(int x, int y){
    if(s[x].length()!= s[y].length()){
        return true;
    }
    vector<int> v;
    for (int i=0;i<s[x].length();i++){
        if (s[x][i]!= s[y][i]) {
            v.push_back(i);
        }
    }
    if(v.size()>2){
        return true;
    }
    swap(s[x][v[0]],s[x][v[1]]);
    int f=0;
    for (int i=0;i<s[x].length();i++) {
        if(s[x][i]!=s[y][i]){
            f=1;
            break;
        }
    }
    swap(s[x][v[0]], s[x][v[1]]);
    if(f==1){
        return true;
    }
    return false;
}
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!check(i,j)){
                //cout << i << " " << j <<;
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
     int ans = 0;
    for (int i = 1; i <=  n; i++) {
        memset(vis, 0, sizeof(vis));
        if (match(i, i)) ans++;
    }
    
    cout <<  n - ans / 2 << endl;
}
