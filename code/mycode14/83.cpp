#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<double, bool> pdb;
const int N = 1e5 + 10;
priority_queue<pdb> heap;
inline bool read(int &x){
    char ch=getchar();
    x=0;
    int s=1;
    for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')s=-s;else if(ch==EOF)return false;
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    x*=s;
    return true;
}
void func(){
    priority_queue<pdb> temp;
    while(heap.size()) {
        pdb now = heap.top();
        heap.pop();
        if(now.second) now.first *= 0.8;
        temp.push(now);
    }
    swap(temp, heap);
}
int main(){
    int n, m, t, k, w;
    double ans = 0.0;
    read(n),read(m),read(t),read(k);
    for(int i = 0; i < n; i++){
        read(w);
        heap.push({w, false});
    }
    for(int i = 0; i < m; i++){
        read(w);
        heap.push({w, true});
    }
    k = t - k;
    bool lock = true;
    while(t--){
        fuck:
        pdb now = heap.top();
        heap.pop();
        if(now.second){
            if(k <= 0 && lock) {
                heap.push(now);
                func();
                lock = false;
                goto fuck;
            }
            if(k >= 0) k--;
        }
        ans += now.first;
        now.first *= 0.6;
        heap.push(now);
    }
    printf("%.2lf", ans);
    return 0;
}
