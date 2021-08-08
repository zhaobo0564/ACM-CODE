#include<bits/stdc++.h>

using namespace std;
char mp[10][10];

int n, m, s, t, cnt[10][10], sum = 0;
int fn[100];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool judge(int x, int y) {
    if (x > n || y > m || x < 1 || y < 1) {
        return false;
    }
    return true;
}

struct node {
    int sta, x, y, xx, yy, step; // sta��¼�Ѿ��ߵĵ㣨����������� ��3��λ����1 ��ʾ�Ѿ����˱��Ϊ3�ĵ㣩
                                // x, yΪ��һ���˵�λ�ã� xx, yyΪ�ڶ����˵�λ�ã� stepΪ�ߵ�ʱ��
};

queue<node> q;

bool vis[300000][5][5][5][5]; // ���б�ǣ� ��һά���Ѿ��ߵ�·����������Ϣ ����Ĵ��ߵ����ꡣ

int bfs() {
    q.push({fn[cnt[s][t]], s, t, s, t, 0});
    while (q.size()) {
        node cd = q.front();
        q.pop();
        if (cd.sta == sum) {  // ����Ѿ��ߵĿյص�״̬�� ���пյص�״̬��ȣ� ˵���Ѿ��������пյأ�ֱ�ӷ��ش�
            return cd.step;
        }
        if (vis[cd.sta][cd.x][cd.y][cd.xx][cd.yy]) continue;
        vis[cd.sta][cd.x][cd.y][cd.xx][cd.yy] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = cd.x + dx[i];
            int ny = cd.y + dy[i];
            if (judge(nx, ny) && mp[nx][ny] != 'X') {
                for (int j = 0; j < 4; j++) {
                    int nxx = cd.xx + dx[j];
                    int nyy = cd.yy + dy[j];
                    if (judge(nxx, nyy) && mp[nxx][nyy] != 'x') {
                        q.push({cd.sta | fn[cnt[nx][ny]] | fn[cnt[nxx][nyy]], nx, ny, nxx, nyy, cd.step + 1});
                    }
                }
            }
        }
    }
    return 0;
}


int main() {
    fn[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fn[i] = fn[i - 1] * 2;
    }
    cin >> n >> m;
    int top = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'S') {
                s = i, t = j;
            } 
            if (mp[i][j] != 'X') {
                sum |= (1 << top);   // �����пյصı����Ϣѹ���Ķ�������
            }
            cnt[i][j] = top++; // ��ÿ�����λ�ý��б�ŷ�������Ʋ���
        }
    }
    cout << bfs() << endl;
    
}
