#include "testlib.h"
using namespace std;
double a, b, c;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    a = inf.readReal();
    b = ouf.readReal();
    c = ans.readReal();
    if (!doubleCompare(c,b,1e-2))
    {
        quitf(_wa, "WA");
    }
    else
    {
        quitf(_ok, "AC");
    }
}