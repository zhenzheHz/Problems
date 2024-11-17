#include <bits/stdc++.h>
using namespace std;
void Convert(string symbol,int32_t &now,int32_t &order) {
    if(symbol == "A") return now = 0 ,void();
    if(symbol == "4") return order *= -1,void();
    if(symbol == "5") return void();
    if(symbol == "10") return now+10>99? now-=10 : now+=10,void();
    if(symbol == "J") return void();
    if(symbol == "Q") return now+20>99? now-=20 : now+=20,void();
    if(symbol == "K") return now = 99,void();
    return now += stoi(symbol),void();
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    char player,card;
    vector<array<string,13>> record(4);
    for(int32_t i=0;i<4;i++) {
        cin >> player;
        for(int32_t j=0;j<13;j++) {
            cin >> record[i][j];
        }
    }
    array<int32_t,4> pointer = {0,0,0,0},score = {0,0,0,0};
    int32_t now = 0, go = 1;
    while(score[now] <= 99) {
        Convert(record[now][pointer[now]],score[now],go);
        if(score[now] > 99 || pointer[now] == 12) {
            cout << (char)'A'+now << '\n' << record[now][pointer[now]];
            return 0;
        }
        pointer[now] += 1;
        now += go;
    }
}