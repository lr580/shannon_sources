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
string so, sa, si;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    si = inf.readString();
    so = ouf.readLine();
    sa = ans.readLine();
    if (so.substr(0, 11) == sa.substr(0, 11))
    {
        bool suc = true;
        for (auto c : so.substr(11))
        {
            if (!isspace(c))
            {
                suc = false;
                quitf(_wa, "WA");
                break;
            }
        }
        if (suc)
        {
            quitf(_ok, "AC");
        }
    }
    else
    {
        quitf(_wa, "WA");
    }
}