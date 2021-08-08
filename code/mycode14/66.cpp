#include<bits/stdc++.h>

using namespace std;
double pai = acos(-1);

const int N = 1007;
struct node {
    double area;
    int x, y;
};
vector<node > ans;

int dist(int x) {
    return x * x + x * x;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string name; cin >> name;
        int x; cin >> x;
        if (name == "cube") {
            ans.push_back({(double)x * (double) x, x, 0});
        } else {
            ans.push_back({(double)x * (double) x * pai, x, 1});
        }
    }
    sort(ans.begin(), ans.end(), [](auto x, auto y) {
        return x.area < y.area;
    });
    for (int i = 1; i < ans.size(); i++) {
        if (ans[i - 1].y != ans[i].y) {
            if (ans[i - 1].y == 0 && ans[i].y == 1) {
                if (dist(ans[i - 1].x) > 4 * ans[i].x * ans[i].x) {
                    cout << "impossible\n";
                    return 0;
                }
            } else if (ans[i - 1].y == 1 && ans[i].y == 0) {
                if (ans[i].x < ans[i - 1].x * 2) {
                    cout << "impossible\n";
                    return 0;
                }
            }
        }
    }
    for (auto it: ans) {
        if (it.y == 0) {
            cout << "cube " << it.x << endl;
        } else {
            cout << "cylinder " << it.x << endl;
        }
    }

}