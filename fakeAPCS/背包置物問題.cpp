#include <bits/stdc++.h>
using namespace std;
int32_t n,k,ans = 0;
vector<int32_t> books;
unordered_set<int32_t> backpack;
int32_t removal(int32_t current) {
    unordered_map<int32_t,int32_t> last_index;
    for(auto book : backpack) {
        last_index[book] = -1;
        for(int32_t i=current;i<books.size();i++) {
            if(books[i] == book) {
                last_index[book] = i;
                break;
            }
        }
    }
    int32_t max_index = -1, remove = -1;
    for(auto book : backpack) {
        if(last_index[book] == -1) return book;
        if(last_index[book] > max_index) {
            max_index = last_index[book];
            remove = book;
        }
    }
    return remove;
}
int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    // input
    cin >> n;
    cin.ignore();
    string line,s;
    getline(cin,line);
    stringstream ss;
    ss << line;
    while(ss >> s) books.push_back(stoi(s));
    cin >> k;
    // process
    int32_t index = 0,replace = 0;
    for(auto book : books) {
        //cout << index+1 << ":";
        if(backpack.find(book) != backpack.end()) {index += 1;continue;}
        // assert(backpack.find(book) == backpack.end());
        if(backpack.size() < k) {
            backpack.insert(book);
        } else {
            // assert(backpack.size() >= k);
            int32_t remove_book = removal(index);
            backpack.erase(remove_book);
            backpack.insert(book);
            replace += 1;
            //cerr << remove_book << '\n';
        }
        index += 1;
    }
    cout << replace << '\n';
}