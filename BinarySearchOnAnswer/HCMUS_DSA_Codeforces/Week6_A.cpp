#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<bool> occupied(m, false);
    vector<int> chain_count(m, 0);
    const long long P = 53;

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;

        long long h = 0;
        for (char c : s) {
            h = (h * P + (long long)c) % m;
        }

        int index = (int)h;
        int jump = 0;

        while (jump < 5 && occupied[index]) {
            index = (index + 1) % m;
            jump++;
        }

        int do_dai_chuoi = chain_count[index];
        occupied[index] = true;
        chain_count[index]++;

        cout << jump << " " << do_dai_chuoi << "\n";
    }
    return 0;
}