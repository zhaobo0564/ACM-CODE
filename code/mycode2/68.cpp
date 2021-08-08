#include<bits/stdc++.h>
using namespace std;

const int N = 3e4 + 7;

struct node{
    string s;
    node(){
    }
    node(string s){
        this->s = s;
    }
    bool operator <(const node x)const{	
		return s > x.s;
	}
    
};

int t, n, m;

vector<int>g[N];

map<string, int>vis;
int top = 1;
int dul[N];
priority_queue<node>q;
string str[N];
vector<string>ans;


int main(){
    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);
    cin >> t;
    while(t--){
        memset(dul,0,sizeof(dul));
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            string a;
            cin >> a;
            vis[a] = i;
            str[i] = a;
            
        }
        for(int i = 1; i <= m; i++){
            string u, v;
            cin >> u >> v;
            dul[vis[v]]++;
            g[vis[u]].push_back(vis[v]);
        }
   
        for(int i = 1; i <= n; i++){
            if(dul[i] == 0){
                q.push(str[i]);
            }
        }
        while(q.size()){
            node cd = q.top();
            int cnt = vis[cd.s];
            q.pop();
            dul[cnt] = -1;
            ans.push_back(cd.s);
            for(int i = 0; i < g[cnt].size(); i++){
                int to = g[cnt][i];
                dul[to]--;
                if(dul[to] == 0){
                    q.push(str[to]);
                }
            }
        }
        cout << "Case #" << top++ << ":\n";
        if(ans.size() != n){
            cout << "Impossible\n";
        }else{
            for(string i: ans){
                cout << i << endl;
            }
        }
        for(int i = 1; i <= n; i++)g[i].clear();
        ans.clear(); vis.clear();

    }
}



