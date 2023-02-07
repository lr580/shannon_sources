#include "testlib.h"
using namespace std;
typedef long long ll;
typedef double db;
#define mn 100010
ll n;
db x, y, r, sx, sy, sr;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    x = ouf.readReal();
    y = ouf.readReal();
    r = ouf.readReal();
    sx = ans.readReal();
    sy = ans.readReal();
    sr = ans.readReal();
    if (!(doubleCompare(sx, x, 1e-6) && doubleCompare(sy, y, 1e-6) &&doubleCompare(sr, r, 1e-6)))
    {
        quitf(_wa, "wa");
    }
    quitf(_ok, "ac");
}