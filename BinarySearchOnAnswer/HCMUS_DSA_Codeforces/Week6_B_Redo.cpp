#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int M = 1000007;
bool leaf_existed[M];
int count_leaves = 0;
int getHashFromString(string &s1, string &s2) {
    string s = s1 + "#" + s2;
    int hash = 0;
    for(int i = 0 ; i < (int)s.size(); i++) {
        hash = (hash * 53 + (s[i])) % M;
    }
    return hash;
}
void insert(int h) {
    if(leaf_existed[h]) return;
    leaf_existed[h] = true;
    count_leaves++;
}

void solve() {

    int n;
    cin >> n;
    int m = n;
    while(n--) {
        string s1, s2;
        cin >> s1 >> s2;
        int h = getHashFromString(s1,s2);
        // cout << "Case " << m - n << " : " << hash_species << " " << color_value << endl;
        insert(h);
    }
    cout << count_leaves;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}