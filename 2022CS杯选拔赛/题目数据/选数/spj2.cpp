
#include "testlib.h"
using ll = long long;
const ll maxn = 1e5 + 10;
ll seed, n, a[maxn];
using namespace std;
ll nextRand()
{
    static ll x = seed;
    x ^= x << 11;
    x ^= x >> 45;
    x ^= x << 14;
    return (x % n + n) % n;
}
ll f(ll x)
{
    ll cnt = 0;
    for (ll i = 0; i < n; ++i)
    {
        cnt = (cnt + (a[i] ^ (i * x))) % n;
    }
    return cnt;
}
signed main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    n = inf.readLong();
    seed = inf.readLong();
    for (int i = 0; i < n; ++i)
    {
        a[i] = nextRand();
    }
    ll u = ouf.readLong(), v = ouf.readLong();
    if (u == v || u < 0 || v < 0 || u >= n || v >= n)
    {
        quitf(_wa,"u,v out of ranges");
    }
    if (f(u) != f(v))
    {
        quitf(_wa,"f(u) not equals to f(v)");
    }
    quitf(_ok,"ac");
}