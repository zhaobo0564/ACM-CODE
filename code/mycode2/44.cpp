#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

int a[N], n;
int L[N], R[N];

map <int, int>mp;

bool work(int l, int r){
    //cout << l << " " << r << endl;
    if(r <= l) return true;

    int i = l;
    int j = r;
    while(i <= r){
        if(L[i] < l && R[i] > r){
            return work(l, i - 1) && work(i + 1, r);
        }
        if(L[j] < l && R[j] > r){
            return work(l, j - 1) && work(j + 1, r);
        }
        i++;
        j--;
    }
    return false;

}


int main(){
    scanf("%d", &n);
    for(int  i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(mp[a[i]]){
            L[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }
    mp.clear();
    for(int i = n; i; i--){
        if(mp[a[i]]){
            R[i] = mp[a[i]];
        }else{
            R[i] = n + 1;
        }
        mp[a[i]] = i;
    }
    if(work(1, n)){
        puts("chong");
    }else{
        puts("fuchong");
    }

}