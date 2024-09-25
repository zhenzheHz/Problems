#include <bits/stdc++.h>
using namespace std;
int graph[5][5];
bool colored[5][5];
int main() {
    unordered_map<int,pair<int,int>> cord;
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            cin >> graph[i][j];
            cord[graph[i][j]] = {i,j};
        }
    }
    int draw;
    while(cin >> draw) {
        if(draw == -1) break;
        auto [x,y] = cord[draw];
        colored[x][y] = 1;
    }
    int rk = 0, id = 100;
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            if(colored[i][j]) continue;
            colored[i][j] = 1;
            int row = 0,col = 0,diag = 0,d2 = 0;
            for(int r=0;r<5;r++) {
                row += colored[r][j];
                col += colored[i][r];
                diag += colored[r][r];
                d2 += colored[r][4-r];
            }
            int x = (row==5), y = (col==5), z = (diag==5), k = (d2==5);
            if(x+y+z+k > rk) {
                rk = x+y+z+k;
                // cout << i << ' '  << j << '\n';
                id = graph[i][j];
            }else if(x+y+z+k == rk) {
                id = min(id,graph[i][j]);
            }
            colored[i][j] = 0;
        }
    }
    cout << id << '\n';
}