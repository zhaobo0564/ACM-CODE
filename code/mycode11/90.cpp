#include<bits/stdc++.h>
using namespace std;

int getMinSwaps(vector<int> v)
{
    vector<int> v1(v);  
    sort(v1.begin(), v1.end());
    map<int,int> m;
    int len = v.size();
    for (int i = 0; i < len; i++)
    {
        m[v1[i]] = i;    
    }
    int loops = 0;      
    vector<bool> flag(len, false); 
    
    for (int i = 0; i < len; i++)
    {
        if (!flag[i])
        {
            int j = i;
            while (!flag[j])   
            {
                flag[j] = true;
                j = m[v[j]];    
            }
            loops++;
        }
    }
    return len - loops;
}
vector<int> v;

string s;
int main()
{
    int n,k;
    ios::sync_with_stdio(0);
    cin>>s;


    int L = 0, S = 0, M = 0;

    for (char i: s) {
       if (i == 'L') {
           L++;
       } else if (i == 'S') {
           S++;
       } else {
           M++;
       }
    }
    string xrev = "";
    for (int i = 0; i < L; i++) {
        xrev += 'L';
    }
    for (int i = 0; i < M; i++) {
        xrev += 'M';
    }
    for (int i = 0; i < S; i++) {
        xrev += 'S';
    }
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != xrev[i]) {
            ans++;
        }
    }
    cout << ans / 2<< endl;
    return 0;
}