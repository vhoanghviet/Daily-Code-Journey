#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> danh_sach_loai(n), danh_sach_mau_sac(n);
    int count = 0;

    for (int i = 0; i < n; ++i) {
        string loai, mau;
        cin >> loai >> mau;

        bool found = false;
        for (int j = 0; j < i; ++j) {
            if (danh_sach_loai[j] == loai && danh_sach_mau_sac[j] == mau) {
                found = true;
                break;
            }
        }

        if (!found) {
            danh_sach_loai[count] = loai;
            danh_sach_mau_sac[count] = mau;
            count++;
        }
        else {
            danh_sach_loai[i] = loai;
            danh_sach_mau_sac[i] = mau;
        }
    }

    cout << count << "\n";
    return 0;
}