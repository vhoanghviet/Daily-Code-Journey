#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> dscanh;
void nhap() {
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int y;
        while(ss >> y) {
            if(i < y) dscanh.push_back({i,y});
        }
    }
}
int main() {
    nhap();
    sort(dscanh.begin(),dscanh.end());
    for(auto it : dscanh) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}