#include "testlib.h"
typedef long long ll;
typedef double db;
using namespace std;
db a, b, c;
string so, sa;
ll n;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    n = inf.readLong();
    for (ll i = 0; i < n; ++i)
    {
        so = ouf.readString();
        sa = ans.readString();
        if (sa[0] == 'e' || sa[0] == 'd')
        {
            if (so != sa)
            {
                quitf(_wa, "WA");
            }
        }
        else
        {
            stringstream sso(so), ssa(sa);
            sso >> b;
            ssa >> c;
            if (!doubleCompare(c,b,1e-2))
            {
                quitf(_wa, "WA");
            }
        }
    }
    quitf(_ok, "AC");
}