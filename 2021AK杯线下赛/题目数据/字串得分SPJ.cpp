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
string a;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    a = inf.readString();
    b = ouf.readReal();
    c = ans.readReal();
    if (fabs(b - c) <= 0.01001)
        quitf(_ok, "AC");
    else
        quitf(_wa, "WA");
}