#include<bits/stdc++.h>
using namespace std;

string be, en;
int k;

vector<int>a, b;
vector<int>ans;
int an[200007];

string work(){
 
}

int main(){
    scanf("%d", &k);
    cin >> be;
    cin >> en;
    for(int i = 0; i < be.length(); i++){
        a.push_back(be[i] - 'a');
    }
    for(int i = 0; i < en.length(); i++){
        b.push_back(en[i] - 'a');
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    a.push_back(0);
    for(int i = 0; i < a.size() - 1; i++){
        int cnt = a[i] + b[i];
        ans.push_back(cnt % 26);
        a[i + 1] += cnt / 26;
    }
    ans[a.size() - 2] += a[a.size() - 1] * 26;
    reverse(ans.begin(), ans.end());
    ans.push_back(0);
    for(int i = 0; i < ans.size() -1; i++){
        int mod = ans[i] % 2;
        ans[i] = ans[i] / 2;
        ans[i + 1] += mod % 2 * 26; 
    }
    for(int i = 0; i < ans.size() - 1; i++){
        printf("%c", ans[i] + 'a' );
    }
    puts("");
    
}