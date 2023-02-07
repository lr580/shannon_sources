#include "testlib.h"
using namespace std;
typedef long long ll;
typedef double db;
#define mn 100010
ll n;
db p[2][2], sp[2][2];
string j, sj;
bool check(ll x, ll y)
{
    for (ll i = 0; i < 2; ++i)
    {
        if (!doubleCompare(sp[y][i], p[x][i], 1e-6))
        {
            return false;
        }
    }
    return true;
}
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    j = ouf.readString();
    sj = ans.readString();
    if (j != sj)
    {
        quitf(_wa, "wa");
    }
    if (sj == "yes")
    {
        for (ll i = 0; i < 2; ++i)
        {
            for (ll j = 0; j < 2; ++j)
            {
                p[i][j] = ouf.readReal();
                sp[i][j] = ans.readReal();
            }
        }
    }
    if (!((check(0, 0) && check(1, 1)) || (check(0, 1) && check(1, 0))))
    {
        quitf(_wa, "wa");
    }
    quitf(_ok, "ac");
}
// if (!doubleCompare(sr, r, 1e-6))
//  {
//      quitf(_wa, "wa");
//  }