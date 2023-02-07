// #include <bits/stdc++.h>
#define oj
// #undef oj
#ifdef oj
#include "testlib.h"
#include <sstream>
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
ll k;
string r, output, nos = "no solution";
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    k = inf.readLong();
    r = ans.readLine();
    if (r == nos)
    {
        output = ouf.readLine();
        for (int i = 11; i < output.size(); i++)
        {
            if (output[i] != ' ')
            {
                quitf(_wa, "not a valid answer");
            }
        }
        if (output.substr(0, 11) != nos)
            quitf(_wa, "%lld shall no solution but got %s", k, output);
        else
            quitf(_ok, "no solution");
    }
    else
    {
        ll a = ouf.readInt(-100, 100);
        ll b = ouf.readInt(-100, 100);
        ll c = ouf.readInt(-100, 100);
        if (a * a * a + b * b * b + c * c * c == k && a && b && c)
            quitf(_ok, "%lld right with %lld %lld %lld", k, a, b, c);
        else
            quitf(_wa, "%lld wrong with %lld %lld %lld (one possible is %s)", k, a, b, c, r);
    }
}