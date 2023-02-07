#include "testlib.h"
using namespace std;
typedef long long ll;
#define mn 100010
ll a[mn], b[mn], n, p = 1e9 + 7, t, xors;
string ans1, ans2, out1, out2;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    n = inf.readLong();
    for (ll i = 1, n2 = 1; i <= n; ++i, n2 = n2 * 2 % p)
    {
        a[i] = inf.readLong();
        a[i] = (a[i] + a[i - 1]) % p;
        b[i] = n2 * a[i] % p;
        xors ^= b[i];
    }
    ans1 = ans.readString();
    ans2 = ans.readString();
    out1 = ouf.readString();
    out2 = ouf.readString();
    if (ans1 != out1 || ans2 != out2)
    {
        quitf(_wa, "WA of judgements");
    }
    t = ouf.readLong();
    if (t <= 0 || t > 2 * n)
    {
        quitf(_wa, "incorrect t");
    }
    for (ll i = 0, x, y, xorpre = xors; i < t; ++i, xorpre = xors)
    {
        x = ouf.readLong();
        y = ouf.readLong();
        if (b[x] < y || y <= 0)
        {
            quitf(_wa, "out of range");
        }
        xors ^= b[x];
        b[x] -= y;
        xors ^= b[x];
        if (xors * xorpre || !(xors + xorpre))
        {
            quitf(_wa, "incorrect movement");
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        if (b[i] != 0)
        {
            quitf(_wa, "remains unsolved");
        }
    }
    quitf(_ok, "AC");
}