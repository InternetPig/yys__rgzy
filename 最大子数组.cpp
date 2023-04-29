#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
const int INF = 0x3f3f3f;
const int N = 1e5 + 10;

int a[N], b[N], dp[N];
int n;
int ans;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    dp[1] = a[1];
    int ans = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (dp[i - 1] > 0)
            dp[i] = dp[i - 1] + a[i];
        else
            dp[i] = a[i];
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}
