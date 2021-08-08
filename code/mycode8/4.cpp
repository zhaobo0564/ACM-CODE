#include<bits/stdc++.h>
using namespace std;

struct msg {
    int w, start, all, end;
}p[200];

deque<msg> q;

bool cmp(msg x, msg y) {
    return x.start < y.start;
}

int main() {
    int n, total;
    cin >> n >> total;

    for (int i = 1; i <= n; i++) {
        cin >> p[i].w >> p[i].start >> p[i].all;
        p[i].end = p[i].start + p[i].all;
    }

    sort(p + 1, p + n + 1, cmp); // �������ŵ�ʱ������

    q.push_back(p[1]);

    int time = 0;
    int maxn = 0;
    int sum = 0;
    int l = 1;
    int ans = 0;
    while (l <= n) {
        if (time == p[l].start) {
            sum += p[l].w;          // ���ϵ���������
            if (p[l].end < maxn) { 
                p[l].end = maxn;    // ���ǰ������ߵ�����ô�������ŵ�ʱ��Ӧ�ð���ǰ���ʱ������
            }
            maxn = max(p[l].end, maxn);
            q.push_front(p[l]);
            l++;
        }

        if (q.size() && q.back().end == time) {     // ����
            sum -= q.back().w;
            q.pop_back();
        }
        if (sum > total) {
            cout << l - 1 << endl;
            return 0;
        }
        time++;
        
    }

    cout << "safe" << endl;

    



}