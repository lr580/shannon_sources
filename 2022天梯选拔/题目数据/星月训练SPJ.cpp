#include "testlib.h"
typedef long long ll;
typedef double db;
using namespace std;
db so1, so2, sa1, sa2;
ll n;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    n = inf.readLong();
    so1 = ouf.readReal();
    so2 = ouf.readReal();
    sa1 = ans.readReal();
    sa2 = ans.readReal();
    if (!doubleCompare(sa1, so1, 1e-2) || !doubleCompare(sa2, so2, 1e-2))
    {
        quitf(_wa, "WA");
    }
    quitf(_ok, "AC");
}