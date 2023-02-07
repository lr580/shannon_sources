#include "testlib.h"
using namespace std;
typedef long long ll;
typedef double db;
#define mn 100010
ll n;
db r, sr, r2, sr2;
string j, sj;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    j = ouf.readString();
    sj = ans.readString();
    if (j != sj)
    {
        quitf(_wa, "wa");
    }
    if (sj == "perfect")
    {
        quitf(_ok, "ac");
    }
    r = ouf.readReal();
    sr = ans.readReal();
    if (sj == "yes")
    {
        r2 = ouf.readReal();
        sr2 = ans.readReal();
        if (!doubleCompare(sr2, r2, 1e-6))
        {
            quitf(_wa, "wa");
        }
    }
    if (!doubleCompare(sr, r, 1e-6))
    {
        quitf(_wa, "wa");
    }
    quitf(_ok, "ac");
}