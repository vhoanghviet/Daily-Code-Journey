#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> dscanh;
void nhap() {
    cin >> n; cin.ignore();
    for(int i = 1 ; i <= n; i++) {
        string s;
        getline(cin, s, '\n');
        stringstream ss(s);
        int x;
        while(ss >> x) {
            dscanh.push_back({i,x});
        }
    }
}

int main() {
    nhap();
    sort(dscanh.begin(), dscanh.end(), [](pair<int,int> p1 , pair<int,int> p2)->bool{
        if(p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    });
    for(auto it : dscanh) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}