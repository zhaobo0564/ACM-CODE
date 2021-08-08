#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

int main() {
    ll n;

    vector<char>s;
    for (int i = 'a'; i <= 'z'; i++) {
        s.push_back(i);
    }
    cin >> n;
    vector<char>ans;
    n--;
    while(n ) {
        
        ans.push_back(s[n % 26]);
        n = n / 26;
    }
    reverse(ans.begin(), ans.end());
    for (auto i: ans) {
        cout << i;
    }
    cout << endl;
}