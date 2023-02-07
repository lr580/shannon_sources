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
__int128 a, b, x, y, xa, ya;
bool check()
{
    __int128 c = __gcd(a, b);
    return a * x + b * y == c;
}
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    a = inf.readLong();
    b = inf.readLong();
    x = ouf.readLong();
    y = ouf.readLong();
    xa = ans.readLong();
    ya = ans.readLong();
    if (!check())
    {
        quitf(_wa, "WA");
    }
    else
    {
        quitf(_ok, "AC");
    }
}