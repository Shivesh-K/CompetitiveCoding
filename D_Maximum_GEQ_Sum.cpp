#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define GOLD ((1 + sqrt(5)) / 2)
#define ll long long
const double PI = 3.14159265358979323846264338327950288419716939937510582097494459230;

class SegmentTree
{
    vector<ll> v;
    bool minTree;

public:
    SegmentTree(const vector<ll> &_v, bool _minTree = false)
    {
        ll t = 1;
        while (t < _v.size())
            t <<= 1;
        v = vector<ll>(2 * t, minTree ? INT_MAX : INT_MIN);
        minTree = _minTree;

        for (int i = 0; i < _v.size(); ++i)
            set(i, _v[i]);
    }

    void set(ll index, ll val)
    {
        index += v.size() / 2;
        v[index] = val;
        while (index > 1)
        {
            index >>= 1;
            v[index] = (minTree ? min(v[2 * index], v[2 * index + 1]) : max(v[2 * index], v[2 * index + 1]));
        }
    }

    ll query(ll l, ll r, ll tl, ll tr, ll index = 1)
    {
        if (l == tl && r == tr)
            return v[index];

        ll mid = (tl + tr) / 2;
        if (r <= mid)
            return query(l, r, tl, mid, index * 2);
        if (l > mid)
            return query(l, r, mid + 1, tr, index * 2 + 1);

        ll t1 = query(l, mid, tl, mid, index * 2);
        ll t2 = query(mid + 1, r, mid + 1, tr, index * 2 + 1);

        return minTree ? min(t1, t2) : max(t1, t2);
    }

    void print()
    {
        ll x = 1, i = 1, p = 1;
        while (i <= x)
        {
            cout << v[i++] << " ";
            if (i > x)
            {
                p <<= 1;
                x += p;
                cout << "\n";
                if (x >= v.size())
                    return;
            }
        }
    }
};

void compute()
{
    ll n;
    cin >> n;
    vector<ll> v(n), vl(n, -1), vr(n, n);
    for (ll &t : v)
        cin >> t;

    vector<ll> st;
    for (int i = 0; i < n; ++i)
    {
        while (st.size() && v[st.back()] <= v[i])
            st.pop_back();

        if (st.size())
            vl[i] = st.back();
        st.push_back(i);
    }

    st.clear();
    for (int i = n - 1; i >= 0; --i)
    {
        while (st.size() && v[st.back()] <= v[i])
            st.pop_back();

        if (st.size())
            vr[i] = st.back();
        st.push_back(i);
    }

    ll m = 1;
    while (m <= n)
        m <<= 1;
    vector<ll> pre(m);
    for (int i = 0; i < n; ++i)
        pre[i + 1] = v[i] + pre[i];

    SegmentTree minSeg(pre, true);
    SegmentTree maxSeg(pre, false);

    for (int i = 0; i < n; ++i)
    {
        ll mx = maxSeg.query(i + 1, vr[i], 0, m - 1);
        ll mn = minSeg.query(vl[i] + 1, i, 0, m - 1);
        if (v[i] < mx - mn)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main()
{
#ifdef debug
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
    {
        compute();
    }
#ifdef debug
    fprintf(stdout, "\nTIME: %.3lf sec\n", (double)clock() / (CLOCKS_PER_SEC));
#endif
    return 0;
}