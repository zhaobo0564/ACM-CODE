#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int t, a[N], b[N], n;

map<int, int>up, down;

vector<int>g;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        g.clear();
        up.clear();
        down.clear();
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &a[i], &b[i]);
            up[a[i]]++;
            down[b[i]]++;
            g.push_back(a[i]);
            g.push_back(b[i]);
        }
        sort(g.begin(), g.end());
        g.erase(unique(g.begin(), g.end()), g.end());
        int station = 0;
        for(int i = 1; i <= n; i++){
            if(up[a[i]] == 0 && down[a[i]] == 0){
                station++;
            }
        }
        int ans = 0, maxn = 0;
        for(int i: g){
          //  cout << "i = " << i << " "<<up[i] << " " << down[i] << endl;
            ans += up[i] - down[i];
            
            maxn = max(ans, maxn);
        }
        printf("%d %d\n", g.size() - station, maxn);





    }
}