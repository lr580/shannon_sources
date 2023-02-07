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
db a, b, c;
string so, sa;
ll n;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    n = inf.readLong();
    for (ll i = 0; i < n; ++i)
    {
        b = ouf.readReal();
        c = ans.readReal();
        if (!doubleCompare(c, b, 1e-9))
        {
            quitf(_wa, "WA");
        }
    }
    quitf(_ok, "AC");
}