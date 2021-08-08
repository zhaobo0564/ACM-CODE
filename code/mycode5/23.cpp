#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int>q;
    q[1]++;
    q[2]++;
    q[3]++;
    q[2]--;
    auto it = q.lower_bound(2);
    q.erase(it);
       it = q.lower_bound(2);
    cout << it -> first << " " << it->second << endl;
}