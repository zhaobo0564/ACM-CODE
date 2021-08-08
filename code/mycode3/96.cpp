#include<bits/stdc++.h>
using namespace std;

int a[100], t, m;
string s;
int b[100];
int vis[200];

vector<int>g, v;
int main(){
    scanf("%d", &t);
    while(t--){
        g.clear();
        cin >> s;
        scanf("%d", &m);
        for(int i = 1; i <= m; i++){
            b[i] = 0;
        }
        for(int i = 1; i <= m; i++){
            scanf("%d", &a[i]);
            if(a[i] == 0){
                g.push_back(i);
                a[i] = -1;
            }
        }
        for(int i = 'a'; i <= 'z'; i++)vis[i] = 0;
        for(int i = 0; i < s.size(); i++){
            vis[s[i]]++;
        }
        int cnt = 0;
        while(1){
            int cn = g.size();
            for(int i: g){
                cout << i << " ";
            }
            cout << endl;
            cnt += cn;
            for(int i = 'z'; i >= 'a'; i--){
                if(vis[i] >= cn){
                    vis[i] -= cn;
                    for(int j: g){
                        b[j] = i;
                    }
                    break;
                }
            }
            if(cnt == m)break;
            for(int i = 1; i <= m; i++){
                if(a[i] == -1)continue;
                int cat = 0;
                for(int j : g){
                    cat += abs(i - j);
                }
                if(cat == a[i]){
                    v.push_back(i);
                    a[i] = -1;
                }
            }
            g.clear();
            for(int i: v){
                g.push_back(i);
            }
            v.clear();
        }
        for(int i = 1; i <= m; i++){
            printf("%c", b[i]);
        }
        puts("");
    }
}
