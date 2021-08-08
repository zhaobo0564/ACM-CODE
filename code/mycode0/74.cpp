#include<bits/stdc++.h>
using namespace std;



int t, n;

const int N = 1001;

int a[1007], vis[1007];

vector<int>v[20];

void fn(){
    int color  = 1;
    while(1){
        for(int i = 1; i <= 11; i++){
            if(v[i])
            for(int j = 1; j <= n; j++){
                
            }
        }
    }
}


int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        int color = 1;
        int cnt  = 1;
        v[1].push_back(a[1]);
        for(int i = 2; i <= n; i++){
            int ff = 0;
            for(int j = 1; j <= cnt; j++){
                int f = 0;
                for(int k = 0; k < v[j].size(); k++){
                    int g =__gcd(a[i], v[j][k]);
                    if(g == 1){
                        f = 1;
                        break;
                    }
                }
                if(f == 0){
                    ff = 1;
                    v[j].push_back(a[i]);
                    break;
                }
            }
            if(!ff){
                v[++cnt].push_back(a[i]);
            }
        }
        cout <<cnt << endl;
        for(int i = 1; i <= cnt; i++){
            for(int j:v[i]){
                cout <<j <<" ";
            }
            cout << endl;
        }
      //  cout << v[12][0] << endl;
        
    }
}