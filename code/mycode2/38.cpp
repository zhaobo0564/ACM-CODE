#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N], n;

vector<int>g;

int get_id(int x){
    return lower_bound(g.begin(), g.end(), x) - g.begin() + 1; 
}

int work(int l, int r){

}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

}