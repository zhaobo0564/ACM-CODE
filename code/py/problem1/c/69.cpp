#include<bits/stdc++.h>
using namespace std;
const int N = 40;

int mp[N][N], n;

bool work(int x, int y, int base) {
    int right = 0, left = 0, up = 0, down = 0;
    int right_down = 0, left_down = 0, right_up = 0, left_up = 0;
    for (int i = 0; i <= 4; i++) {
        if (mp[x][y + i] == base) {
            right++;
        } 
        if (mp[x + i][y] == base) {
            down++;
        }
        if (x - i > 0 && mp[x - i][y] == base) {
            left++;
        }
        if (y - i > 0 && mp[x][y - i] == base) {
            up++;
        } 
        if (mp[x + i][y + i] == base) {
            right_down++;
        }
        if (x - i > 0 && y - i > 0 && mp[x - i][y - i] == base) {
            left_up++;
        }
        if (x - i > 0 && mp[x - i][y + i] == base) {
            right_up++;
        } 
        if (y - i > 0 && mp[x + i][y - i] == base) {
            left_down++;
        }

    }
    if (right == 5 || left == 5 || down == 5 || up == 5 ||
        right_down == 5 || left_up == 5 || right_up == 5 || left_down == 5) {
        return true;
    }
    return false;
}



int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if (i % 2 == 1) {
            mp[x][y] = 1;
            if (work(x, y, 1)) {
                cout << "xiaoming " << i << endl;
                return 0;
            }
        } else {
            mp[x][y] = 2;
            if (work(x, y, 2)) {
                cout << "xiaohong " << i << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}