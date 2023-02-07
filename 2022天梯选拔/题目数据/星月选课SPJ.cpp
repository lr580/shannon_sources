#include "testlib.h"
typedef long long ll;
typedef double db;
using namespace std;
db so1, sa1;
ll n;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    n = inf.readLong();
    so1 = ouf.readReal();
    sa1 = ans.readReal();
    if (!doubleCompare(sa1, so1, 1e-2))
    {
        quitf(_wa, "WA");
    }
    quitf(_ok, "AC");
}