#include "testlib.h"
using namespace std;
typedef long long ll;
#define mn 583
ll t, n, nans, w[mn], c[mn][mn], d[mn];
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    t = inf.readLong();
    n = ouf.readLong();
    nans = ans.readLong();
    // quitf(_ok, "ac");
    if (n == -1)
    {
        quitf(_wa, "-1 is impossible");
    }
    else if (n < 1 || n > 580)
    {
        quitf(_wa, "number of buildings exceed limit");
    }
    else
    {
        for (ll i = 1; i <= n; ++i)
        {
            w[i] = ouf.readLong();
            if (w[i] <= 1 || w[i] > 58)
            {
                quitf(_wa, "important value of buildings exceed limit");
            }
        }
        for (ll i = 1; i <= n; ++i)
        {
            for (ll j = 1; j <= n; ++j)
            {
                c[i][j] = ouf.readLong();
                if (c[i][j] < 0 || c[i][j] > 1 || (i == j && c[i][j] == 1))
                {
                    quitf(_wa, "wrong relationship");
                }
            }
        }
        ll csum = 0;
        for (ll i = 1; i <= n; ++i)
        {
            for (ll j = 1; j <= n; ++j)
            {
                d[i] += c[i][j];
                csum += c[i][j];
                if (c[i][j] != c[j][i])
                {
                    quitf(_wa, "asymmetric relationship");
                }
            }
        }
        if (csum / 2 > 5800)
        {
            quitf(_wa, "too much relationships");
        }
        ll ct = 0;
        for (ll i = 1; i <= n; ++i)
        {
            ll v = 1;
            for (ll j = 1; j <= d[i]; ++j)
            {
                v *= w[i];
            }
            ct += v;
        }
        if (t != ct)
        {
            quitf(_wa, "your answer %lld isn't equals to t", ct);
        }
    }
    quitf(_ok, "ac");
}