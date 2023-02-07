#include "testlib.h"
using namespace std;
typedef long long ll;
typedef double db;
#define mn 100010
ll n;
db r, sr;
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    r = ouf.readReal();
    sr = ans.readReal();
    if (!doubleCompare(sr, r, 1e-6))
    {
        quitf(_wa, "wa");
    }
    quitf(_ok, "ac");
}