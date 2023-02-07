#include "testlib.h"
using namespace std;
typedef long long ll;
#define mn 105
ll n, s[mn], d[mn];
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    string t = inf.readString();
    stringstream ss(t);
    ll v;
    while (ss >> v)
    {
        s[++n] = v;
    }
    ll out1 = ouf.readLong();
    ll ans1 = ans.readLong();
    if (ans1 == -1)
    {
        if (out1 != ans1)
        {
            quitf(_wa, "no solution but output is not -1");
        }
        else
        {
            quitf(_ok, "ac");
        }
    }
    ll out2 = ouf.readLong();
    for (ll i = 1; i <= n; ++i)
    {
        if (s[i] == out1)
        {
            s[i] = out2;
            break;
        }
    }
    for (ll i = 1; i < n; ++i)
    {
        d[i] = s[i + 1] - s[i] - 1;
        if (d[i] < 0)
        {
            quitf(_wa, "monks crashed");
        }
    }
    ll sum = 0;
    for (ll i = 1; i < n; i += 2)
    {
        sum ^= d[i];
    }
    if (sum == 0)
    {
        quitf(_ok, "ac");
    }
    else
    {
        quitf(_wa, "%lld invalid movement", n);
    }
}