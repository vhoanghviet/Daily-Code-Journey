#include <iostream>
#include <vector>

using namespace std;

int X[100];
int n;
bool check() {
    for(int i = 2; i <= n; i++) {
        if(X[i] == 1 && X[i-1] == 1) {
            return false;
        }
    }
    return true;
}
void in()
{
    if(check()) {
        for (int i = 1; i <= n; i++)
        {
            cout << X[i];
        }
        cout << endl;
    }
}
void Try(int i)
{          
    for (int j = 0; j <= 1; j++)
    {
        X[i] = j;
        if (i == n)
        {
            in();
        }
        else
            Try(i + 1);
    }
}

int main()
{
    cin >> n;
    Try(1);
    cout << endl;
    return 0;
}