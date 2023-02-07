#include "testlib.h"
using ll = long long;

inline ll qpow(ll a, ll b)
{
    ll ans = 1, base = a;
    while (b)
    {
        if (b % 2)
            ans = ans * base;
        base = base * base;
        b /= 2;
    }
    return ans;
}

bool ok(ll l, ll r, ll x)
{
    if (l > r) return false;
    if (r - l >= 10)
    {
        // ac if x == 0
        return (x == 0);
    }

    // prevent overflow
    ll ss1 = 1, ss2 = 1, ss3 = 1, ss = 1;
    for (ll i = l; i <= r; i++)
    {
        std::string a = std::to_string(i);
        for (auto &j : a)
        {
            ss = ss * 1LL * (j - '0');
            ss1 = ss1 * (j - '0') % 998244353;
            ss2 = ss2 * (j - '0') % 1000000007;
            ss3 = ss3 * (j - '0') % 1000000009;
        }
    }

    return ((ss == x) && (ss1 == x % 998244353) && (ss2 == x % 1000000007) && (ss3 == x % 1000000009));
}

int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    // double pans = ouf.readDouble();
    // double jans = ans.readDouble();
    int t = inf.readInt(1, 20000);
    for (int inx = 1; inx <= t; inx++)
    {
        ll x = inf.readLong(0LL, 1000000000000000000LL);
        ll y = inf.readLong(0LL, 18LL);
        ll jans_l = ans.readLong(-1LL, 1LL * qpow(10, y) - 1LL);
        ll pans_l = ouf.readLong(-1LL, 1LL * qpow(10, y) - 1LL);
        if (jans_l == -1 && pans_l == -1)
        {
            // ac
            continue;
        }
        else if (jans_l == -1 && pans_l != -1)
        {
            ll pans_r = ouf.readLong(0LL, 1LL * qpow(10, y) - 1LL);
            if (ok(pans_l, pans_r, x))
            {
                // fail
                quitf(_fail, "An internal error was found when x = %lld, y = %lld.\nThis is NOT your fault, contact @bobby285271 for more info.", x, y);
            }
            else
            {
                // wa
                quitf(_wa, "Fail on check point 1.");
            }
        }
        else if (jans_l != -1 && pans_l == -1)
        {
            ll jans_r = ans.readLong(0LL, 1LL * qpow(10, y) - 1LL);
            if (ok(jans_l, jans_r, x))
            {
                // wa
                quitf(_wa, "Fail on check point 2.");
            }
            else
            {
                // fail
                quitf(_fail, "An internal error was found when x = %lld, y = %lld.\nThis is NOT your fault, contact @bobby285271 for more info.", x, y);
            }
        }
        else
        {
            ll jans_r = ans.readLong(0LL, 1LL * qpow(10, y) - 1LL);
            ll pans_r = ouf.readLong(0LL, 1LL * qpow(10, y) - 1LL);
            if (ok(pans_l, pans_r, x))
            {
                // ac
                continue;
            }
            else
            {
                // wa
                quitf(_wa, "Fail on check point 3.");
            }
        }
    }
    quitf(_ok, "OK, %d valid pair(s).", t);
}
