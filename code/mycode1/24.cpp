#include<bits/stdc++.h>
using namespace std;

int n;
string s;

string work(int d){
    string a = "";
    for(int i = 0; i < d; i++){
        a += s[i];
    }
    reverse(a.begin(), a.end());
    for(int i = d; i < n; i++){
        a += s[i];
    }
    return a;
}

int main(){
    scanf("%d", &n);
    cin >> s;

    vector<int>g;
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            g.push_back(i);
        }
    }

    for(int i = 0; i < g.size(); i++){
        s = work(g[i]);  
    }
  cout << s << endl;


}