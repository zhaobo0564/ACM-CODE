#include<bits/stdc++.h>
using namespace std;

int n, p, a[3000];
vector<int>v;

int main(){
    scanf("%d %d", &n, &p);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int pos = 0;
    for(int i = 1; i <= 2000; i++){
        int cnt = i;
        for(int j = 1; j <= n; j++){
            if(cnt >= a[j]){
                cnt++;
            }else{
                cnt = 0;
                break;
            }
        }
        if(cnt){
            pos = i;
            break;
        }
    }
    for(int i = pos; i <= 2000; i++){
        int cnt = 0;
        int cat = i;
        int f = 0;
        for(int j = 0; j< n; j++){
            int cn = upper_bound(a + 1, a + n + 1, cat + j) - a;
            cn--;
            cn = cn - j;
            if(cn >= p){
                f = 1;
                break;
            }
        
        }
        if(f == 0){
            v.push_back(i);
        }else{
            break;
        }
    }
    cout << v.size() << endl;
    for(int i: v){
        printf("%d ", i);
    }
    puts("");
}