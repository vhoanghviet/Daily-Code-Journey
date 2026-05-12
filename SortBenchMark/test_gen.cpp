#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

unsigned long long sd = 20070530;
unsigned int m_rd() {
    sd = (1103515245 * sd + 12345) % 2147483648;
    return (unsigned int)sd;
}

void m_sw(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void m_st(vector<int> &a, int l, int r, bool rv) {
    if (l >= r) return;
    int p = a[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        if (!rv) {
            while (a[i] < p) i++;
            while (a[j] > p) j--;
        } else {
            while (a[i] > p) i++;
            while (a[j] < p) j--;
        }
        if (i <= j) {
            m_sw(a[i], a[j]);
            i++; j--;
        }
    }
    m_st(a, l, j, rv);
    m_st(a, i, r, rv);
}

string s_ch(int d) {
    string s = "";
    for (int i = 0; i < d; i++) s += (char)('a' + m_rd() % 26);
    return s;
}

void t_i(int stt) {
    int n = 100000;
    cout << n << "\n";
    if (stt == 1) {
        for (int i = 0; i < n; i++) cout << (int)m_rd() << "\n";
    } else if (stt == 2) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = m_rd();
        m_st(v, 0, n - 1, false);
        for (int i = 0; i < n; i++) cout << v[i] << "\n";
    } else if (stt == 3) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = m_rd();
        m_st(v, 0, n - 1, true);
        for (int i = 0; i < n; i++) cout << v[i] << "\n";
    } else if (stt == 4) {
        int x = m_rd();
        for (int i = 0; i < n; i++) cout << x << "\n";
    } else {
        for (int i = 0; i < n; i++) cout << (i % 2 == 0 ? 2147483647 : -2147483648) << "\n";
    }
}

void t_sl(int stt) {
    int n = 100000;
    cout << n << "\n";
    if (stt == 1) {
        for (int i = 0; i < n; i++) cout << s_ch(100) << "\n";
    } else if (stt == 2) {
        string t_to = s_ch(90);
        for (int i = 0; i < n; i++) cout << t_to << s_ch(10) << "\n";
    } else if (stt == 3) {
        string s = s_ch(100);
        for (int i = 0; i < n; i++) cout << s << "\n";
    } else if (stt == 4) {
        for (int i = 0; i < n; i++) {
            string s = "";
            for(int j = 0; j < 100; j++) s += (m_rd() % 2 == 0 ? 'a' : 'b');
            cout << s << "\n";
        }
    } else {
        for (int i = 0; i < n; i++) cout << "aaaaaaaaaa" << s_ch(5) << "\n";
    }
}

void t_sll(int stt) {
    int n = 10000;
    cout << n << "\n";
    if (stt == 1) {
        for (int i = 0; i < n; i++) cout << s_ch(10 + (i % 91)) << "\n";
    } else if (stt == 2) {
        string t_to = s_ch(95);
        for (int i = 0; i < n; i++) cout << t_to << s_ch(5) << "\n";
    } else if (stt == 4) {
        for (int i = 0; i < n; i++) cout << s_ch(10 + m_rd() % 91) << "\n";
    } else if (stt == 3) {
        for (int i = 0; i < n; i++) cout << s_ch(i % 2 == 0 ? 10 : 100) << "\n";
    } else {
        for (int i = 0; i < n; i++) cout << string(100, 'z') << "\n";
    }
}

int m_at(char* s) {
    int r = 0;
    for (int i = 0; s[i] != '\0'; i++) r = r * 10 + (s[i] - '0');
    return r;
}


int main(int argc, char* argv[]) {
    if (argc < 3) return 1;
    char* lb = argv[1];
    int stt = m_at(argv[2]);
    if (strcmp(lb, "int") == 0) t_i(stt);
    else if (strcmp(lb, "strlexi") == 0) t_sl(stt);
    else if (strcmp(lb, "strlenlexi") == 0) t_sll(stt);
    return 0;
}