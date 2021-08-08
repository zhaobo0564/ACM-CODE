#include<bits/stdc++.h>
using namespace std;
 
const int N = 300;
 
string s;
int t, n;
 
vector<int> g[N];
 
void work(int p, string a) {
    vector<string>v;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '[') {
            string cnt = "";
            int pos = i + 1;
            while (a[pos] != ']') {
                cnt += a[pos];
                pos++;
            }
            i = pos;
            v.push_back(cnt);
        }
    }
    if (v[0][0] == '*') {
        g[p].push_back(0);
    } else if (v[0].size() == 5) {
        g[p].push_back(3);
    } else if (v[0][0] == 'o' ) {
        g[p].push_back(1);
    } else if (v[0][0] == 't') {
        g[p].push_back(2);
    }
    if (v[1][0] == '*') {
        g[p].push_back(0);
    } else if (v[1][0] == 'd') {
        g[p].push_back(1);
    } else if (v[1][0] == 's') {
        g[p].push_back(2);
    } else if (v[1][0] == 'o') {
        g[p].push_back(3);
    }
    if (v[2][0] == '*') {
        g[p].push_back(0);
    } else if (v[2][1] == 'o') {
        g[p].push_back(1);
    } else if (v[2][1] == 't') {
        g[p].push_back(2);
    } else if (v[2][1] == 'p') {
        g[p].push_back(3);
    }
    if (v[3][0] == '*') {
        g[p].push_back(0);
    } else if (v[3][0] == 'r') {
        g[p].push_back(1);
    } else if (v[3][0] == 'g') {
        g[p].push_back(2);
    } else if (v[3][0] == 'p') {
        g[p].push_back(3);
    }
}
 
 
 
 
 
vector<int>pos[6][6][6][6];



int judge(int a, int b, int c, int d, int x, int y) {
    if (pos[a][b][c][d].size()) {
        if (pos[a][b][c][d].size() == 1) {
            if (pos[a][b][c][d][0] != x && pos[a][b][c][d][0] != y) {
                return pos[a][b][c][d][0];
            }
        } else if (pos[a][b][c][d].size() == 2) {
            if (pos[a][b][c][d][0] != x && pos[a][b][c][d][0] != y) {
                return pos[a][b][c][d][0];
            } else if (pos[a][b][c][d][1] != x && pos[a][b][c][d][1] != y) {
                return pos[a][b][c][d][1];
            }
        } else (pos[a][b][c][d].size() > 2) {
            if (pos[a][b][c][d][0] != x && pos[a][b][c][d][0] != y) {
                return pos[a][b][c][d][0];
            } else if (pos[a][b][c][d][1] != x && pos[a][b][c][d][1] != y) {
                return pos[a][b][c][d][1];
            } else {
                return pos[a][b][c][d][2];
            }
        }
    }
    return -1;
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    int ca = 1;
    while (t--) {
        cin >> n;
        
        for (int i = 0; i <= 5; i++) {
            for (int j = 0; j <= 5; j++) {
                for (int k = 0; k <= 5; k++) {
                    for (int z = 0; z <= 5; z++) {
                        pos[i][j][k][z].clear();
                    }
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            cin >> s;
            g[i].push_back(0);
            work(i, s);
        }

        

        for (int i = 1; i <= n; i++) {
            pos[g[i][1]][g[i][2]][g[i][3]][g[i][4]].push_back(i);
            
        }
        for (int i = 0; i <= 4; i++) {
            for (int j = 0; j <= 4; j++) {
                for (int k = 0; k <= 4; k++) {
                    for (int z = 0; z <= 4; z++) {
                        if (pos[i][j][k][z].size()){
                            sort(pos[i][j][k][z].begin(), pos[i][j][k][z].end());
                            pos[i][j][k][z].erase(unique(pos[i][j][k][z].begin(), pos[i][j][k][z].end()),pos[i][j][k][z].end());
                        }
                    }
                }
            }
        }
        int f = -1;
        int xx, yy;
        for (int i = 1; i <= n; i++) {
            for (int j =  1; j <= n; j++) {
                if (i == j) continue;
                int aa[5];
               
                for (int k = 1; k <= 4; k++) {
                    if (g[i][k] == 0 || g[j][k] == 0) {
                        aa[k] = 0;
                    
                    } else if (g[i][k] == 1 && g[j][k] == 1) {
                        aa[k] = 1;
                        //f = 1000000000;
                    } else if (g[i][k] == 2 && g[j][k] == 2) {
                        aa[k] = 2;
                    } else if (g[i][k] == 3 && g[j][k] == 3) {
                        aa[k] = 3;
                    } else if (g[i][k] == 1 && g[j][k] == 2) {
                        aa[k] = 3;
                    } else if (g[i][k] == 1 && g[j][k] == 3) {
                        aa[k] = 2;
                      
                    } else if (g[i][k] == 2 && g[j][k] == 3) {
                        aa[k] = 1;
                        
                    } else if (g[i][k] == 2 && g[j][k] == 1) {
                        aa[k] = 3;
                        
                    } else if (g[i][k] == 3 && g[j][k] == 1) {
                        aa[k] = 2;
                        
                    } else if (g[i][k] == 3 && g[j][k] == 2) {
                        aa[k] = 1;
                    
                    }
                }
                if (f > 0) break;
                int a = aa[1], b = aa[2], c = aa[3], d = aa[4];
              
                 if (a == 0 && b && c && d) {
                     
                    for (int k = 0; k <= 4; k++) {
                        f = judge(k, b, c, d, i, j);
                        if (f > 0) break;
                    }

                } else if (a && b == 0 && c && d ) {
                    
                    for (int k = 0; k <= 4; k++) {
                        f = judge(a, k, c, d, i, j);
                        if (f > 0) break;
                    }
                    
                } else if (a && b && c == 0 && d) {
                
                    for (int k = 0; k <= 4; k++) {
                        f = judge(a, b, k, d, i, j);
                        if (f > 0) break;
                    }
                    
                } else if (a && b && c && d == 0) {
                    
                    for (int k = 0; k <= 4; k++) {
                        f = judge(a, b, c, k, i, j);//f = 1000000000;
                        if (f > 0) break;
                    }
                    
                } else if (a == 0 && b == 0 && c && d) {
              
                    for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            f = judge(k, z, c, d, i, j);
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                    
                } else if (a == 0 && b && c == 0 && d) {
                  
                    for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            f = judge(k, b, z, d, i, j);//f = 1000000000;
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                     
                } else if (a == 0 && b && c && d == 0) {
                    
                    for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            f = judge(k, b, c, z, i, j);
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                    
                } else if (a && b == 0 && c == 0 && d) {
                    for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            f = judge(a, k, z, d, i, j);
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                   
                } else if (a && b == 0 && c && d == 0) {
                    for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            f = judge(a, k, c, z, i, j);
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                      
                } else if (a && b && c == 0 && d == 0) {
                    for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            f = judge(a, b, k, z, i, j);
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                   
                } else if (a == 0 && b == 0 && c == 0 && d) {
                    for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            for (int w = 0; w <= 4; w++) {
                                f = judge(k, z, w, d, i, j);
                                if (f > 0) break;
                            }
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                   
                } else if (a == 0 && b == 0 && c && d == 0) {
                    for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            for (int w = 0; w <= 4; w++) {
                                f = judge(k, z, c, w, i, j);
                                if (f > 0) break;
                            }
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                    
                } else if (a == 0 && b && c == 0 && d == 0) {
                    for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            for (int w = 0; w <= 4; w++) {
                                f = judge(k, b, z, w, i, j);
                                if (f > 0) break;
                            }
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                    
                } else if (a && b == 0 && c == 0 && d == 0) {
                     for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            for (int w = 0; w <= 4; w++) {
                                f = judge(a, k, z, w, i, j);
                                if (f > 0) break;
                            }
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                    
                } else if (a == 0 && b == 0 && c == 0 && d == 0) {
                    for (int k = 0; k <= 4; k++) {
                        for (int z = 0; z <= 4; z++) {
                            for (int w = 0; w <= 4; w++) {
                                for(int q = 0; q <= 4; q++) {
                                    f = judge(k, z, w, q, i, j);
                                    if (f > 0) break;
                                }
                                
                                if (f > 0) break;
                            }
                            if (f > 0) break;
                        }
                        if (f > 0) break;
                    }
                    
                } else if (a && b && c && d) {
                    f = judge(a, b, c, d, i, j);
                    
                } else {
                    f = 1000000000;
                }
                if (f > 0) {
                    xx = i; yy = j;
                    break;
                }
            }
            if (f > 0) break;
        }   
        int ok = 0;
        vector<int>v;
        int xxx, yyy, zzz;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                for (int k = 1; k <= n; k++) {
                    if (i == k || j == k) continue;
                    
                    ok = 0;
                   for (int z = 1;  z<= 4; z++) {
                       v.clear();
                       v.push_back(g[i][z]);
                       v.push_back(g[j][z]);
                       v.push_back(g[k][z]);
                       sort(v.begin(), v.end());
                       if (v[0] == 0) {
                           ok++;
                       } else if (v[0] != v[1] && v[1] != v[2] && v[0] != v[2]) {
                           ok++;
                       } else if (v[0] == v[1] && v[1] == v[2]) {
                           ok++;
                       }
                   }
                   if (ok == 4){
                       xxx = i, yyy = j, zzz = k;
                       break;
                   } 
                   
                    
                }
                if (ok == 4) break;
            }
            if (ok == 4) break;
        }
        if (f == 1000000000 ) {
            if (ok != 4) {
                cout << "Case #" << ca++ << ": -1\n";
            } else
            
             cout << "Case #" << ca++ << ": " << xxx << " " << yyy << " " << zzz << "\n";
        }
        else if (ok != 4) {
            cout << "Case #" << ca++ << ": -1\n";
        } else {
           

            cout << "Case #" << ca++ << ": " << xx << " " << yy << " " << f << "\n";
        }
 
         
 
 
    }
}