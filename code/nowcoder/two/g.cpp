#include <bits/stdc++.h>
using namespace std;

int q;
multiset<int> g;

bool judge(int x, int y, int z) {
    if (!x || !y || !z) return false;
    if (x + y > z && x + z > y && z + y > x ) {
        return true;
    }
    return false;
}

int main () {
    scanf("%d", &q);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x; scanf("%d", &x);
            g.insert(x);
        } else if (op == 2) {
            int x; scanf("%d", &x);
            auto it = g.lower_bound(x);
            g.erase(it);
        } else {
            int x, y, z; scanf("%d", &x);
            int f = 0;
            auto it = g.lower_bound(x);
            if (it != g.end()) {
                y = *it;
            } else {
                y = 0;
            }
            it++;
            if (it != g.end()) {
                z = *it;
            } else {
                z = 0;
            }
            if (judge(x, y, z)) {
                puts("Yes");
            } else {
                it = g.upper_bound(x);
                if (it != g.begin()) {
                    it--;
                    y = *it;
                } else {
                    y = 0;
                }
                if (it != g.begin()) {
                    it--;
                    z = *it;
                } else {
                    z = 0;
                }
                if (judge(x, y, z)) {
                    puts("Yes");
                } else {
                    it = g.upper_bound(x);
                    if (it != g.end()) {
                        y = *it;
                    } else {
                        y = 0;
                    }
                    if (it != g.begin()) {
                        it--;
                        z = *it;
                    } else {
                        z = 0;
                    }
                    if (judge(x, y, z)) {
                        puts("Yes");
                    } else {
                        // it = g.upper_bound(x);
                        // if (it != g.begin()) {
                        //     it--;
                        //     y = *it;
                        // } else {
                        //     y = 0;
                        // }
                        // if (it != g.begin()) {
                        //     it--;
                        //     z = *it;
                        // } else {
                        //     z = 0;
                        // }
                        // if (judge(x, y, z)) {
                        //     puts("Yes");
                        // } else {
                        //     puts("No");
                        // }
                        puts("No");
                    }
                }
            }
        }
    }
}