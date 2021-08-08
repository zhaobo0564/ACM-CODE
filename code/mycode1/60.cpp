#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int c, l;


pair<int, int> cow[N];

int main(){
    scanf("%d %d", &c, &l);
    for(int i = 1; i <= c; i++){
        scanf("%d %d", &cow[i].first, &cow[i].second);
    }

    map<int, int >spf;
    for(int i = 1; i <= l ; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        spf[x] += y;
    }
    sort(cow + 1, cow + c + 1);
    int ans = 0;
    for(int i = c; i ; i--){
        auto it = spf.upper_bound(cow[i].second);
        if(it == spf.begin())continue;
        it--;
       // cout << it->first << " " << it->second<< endl;

        if(it ->first >= cow[i].first  ){
            it->second--;
            ans++;
            if(it->second == 0){
                spf.erase(it);
            }
        }
    }
    printf("%d\n", ans);

}