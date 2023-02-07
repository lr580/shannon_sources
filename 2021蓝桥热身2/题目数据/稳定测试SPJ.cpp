// #include <bits/stdc++.h>
#define oj
// #undef oj
#ifdef oj
#include "testlib.h"
#endif
typedef long long ll;
typedef double db;
#define re register
using namespace std;
#define sc(x) scanf("%lld", &x)
#define rep(i, a, b) for (re ll i = a; i < b; ++i)
#define repe(i, a, b) for (re ll i = a; i <= b; ++i)
#define red(i, a, b) for (re ll i = a; i > b; --i)
#define rede(i, a, b) for (re ll i = a; i >= b; --i)
db b, c;
int n, m, a, d, k;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    n = inf.readInt(), m = inf.readInt();

    for (int i = 1; i <= n; ++i)
    {
        a = inf.readInt();
    }
    while (m--)
    {
        a = inf.readInt();
        for (int i = 1; i <= a; ++i)
        {
            d = inf.readInt();
        }
        k += (a - 1);
    }
    for (int i = 1; i <= k; ++i)
    {
        b = ouf.readReal();
        c = ans.readReal();
        if (!doubleCompare(c, b, 1e-2))
            quitf(_wa, "WA in output %d : %.12lf %.12lf", i, b, c);
    }
    quitf(_ok, "AC");
}