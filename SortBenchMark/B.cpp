#include <iostream>
#include <cstring>

using namespace std;

static char strs_data[100005][105];
static int idx_arr[100005];
static int tmp_arr[100005];
static int n;

void msd_radix_sort(int left, int right, int pos, int* idx, int* tmp) {
    if (left >= right || pos >= 100) return;

    int count[28];
    for (int i = 0; i < 28; i++) count[i] = 0;

    for (int i = left; i <= right; i++) {
        char c = strs_data[idx[i]][pos];
        if (c == '\0') count[0]++;
        else count[c - 'a' + 1]++;
    }

    int start_pos[28];
    start_pos[0] = left;
    for (int i = 1; i < 28; i++) {
        start_pos[i] = start_pos[i - 1] + count[i - 1];
    }

    int current_pos[28];
    for (int i = 0; i < 28; i++) current_pos[i] = start_pos[i];

    for (int i = left; i <= right; i++) {
        char c = strs_data[idx[i]][pos];
        int bucket = (c == '\0') ? 0 : (c - 'a' + 1);
        tmp[current_pos[bucket]++] = idx[i];
    }

    for (int i = left; i <= right; i++) {
        idx[i] = tmp[i];
    }

    for (int i = 1; i < 27; i++) {
        if (count[i] > 1) {
            msd_radix_sort(start_pos[i], start_pos[i] + count[i] - 1, pos + 1, idx, tmp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        cin >> strs_data[i];
        idx_arr[i] = i;
    }

    msd_radix_sort(0, n - 1, 0, idx_arr, tmp_arr);

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << strs_data[idx_arr[i]] << "\n";
    }

    return 0;
}