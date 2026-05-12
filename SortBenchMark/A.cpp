#include <iostream>
#include <cstring>
using namespace std;

static int arr[100005];
static int tmp[100005];
static int cnt[256];

void radix_sort(int* a, int n) {
    unsigned int* ua = (unsigned int*)a;
    unsigned int* ut = (unsigned int*)tmp;

    for (int shift = 0; shift < 32; shift += 8) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            cnt[(ua[i] >> shift) & 0xFF]++;
        }

        if (shift == 24) {
            int pos[256];
            pos[128] = 0;
            for (int i = 129; i < 256; i++) {
                pos[i] = pos[i-1] + cnt[i-1];
            }
            pos[0] = pos[255] + cnt[255];
            for (int i = 1; i < 128; i++) {
                pos[i] = pos[i-1] + cnt[i-1];
            }

            for (int i = 0; i < n; i++) {
                int b = (ua[i] >> 24) & 0xFF;
                ut[pos[b]++] = ua[i];
            }
        } else {
            int pos[256];
            pos[0] = 0;
            for (int i = 1; i < 256; i++) pos[i] = pos[i-1] + cnt[i-1];

            for (int i = 0; i < n; i++) {
                int b = (ua[i] >> shift) & 0xFF;
                ut[pos[b]++] = ua[i];
            }
        }
        unsigned int* temp = ua;
        ua = ut;
        ut = temp;
    }
    
    if ((int*)ua != a) {
        memcpy(a, ua, n * sizeof(int));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    radix_sort(arr, n);

    cout << n << '\n';
    for (int i = 0; i < n; i++) cout << arr[i] << '\n';

    return 0;
}