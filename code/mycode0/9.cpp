#include<bits/stdc++.h>
using namespace std;
int a[600], n;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    stack<int>q;
    for(int i = 1; i <= n; i++){
        int x = i;
        while(!q.empty() && x == q.top()){
            q.pop();
            x++;
        }
        q.push(x);
        
    }
    vector<int>v;
    while(!q.empty()){
        cout << q.top() << " ";
        v.push_back(q.top());
        q.pop();
    }
    cout << endl;
    int ans = 0;
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] > v[i + 1]){
            swap(v[i], v[i + 1]);
        }
        if(v[i] == v[i + 1]){
            cout << " i= " << v[i] << endl;
            v[i + 1] = v[i + 1] + 1;
            ans++;
        }
    }
    printf("%d\n",v.size() - ans);
}