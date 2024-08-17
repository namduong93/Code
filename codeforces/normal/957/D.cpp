/**
 *    author:  namduong93
 *    created: unknown
 *    complexity: unknown
 **/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdo(i, a, b) for (int i = a; i >= b; --i)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define SZ(x) ((int)(x).size())

int get_bit(int x, int i)
{
    return x & (1 << i);
}
int turn_bit(int x, int i) { return x | (1 << i); }
int swap_bit(int x, int i) { return x ^ (1 << i); }

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 998244353;
const int N = 300005;
const int inf = 1e9 + 7;

int n;
int a[N], m[N], t1[N], t2[N];
string str;
string s[N];
stack<int> st;
priority_queue<pii, vector<pii>, greater<pii>> d_heap;
multiset<int> ms;

void Solve()
{
    cin >> n;
    fto(i, 1, n) cin >> m[i];
    fdo(i, n, 1)
    {
        t1[i] = max(t1[i + 1] - 1, 0ll);
        t1[i] = max(t1[i], m[i] + 1);
    }
    fto(i, 1, n)
    {
        t2[i] = max(t1[i], t2[i - 1]);
        t2[i] = max(t2[i], m[i] + 1);
    }
    // fto(i, 1, n) cout << t2[i] << ' ';
    int ans = 0;
    fto(i, 1, n)
    {
        ans += t2[i] - m[i] - 1;
    }
    cout << ans;
}

int32_t main()
{

    if (fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Test = 1;
    // cin >> Test;
    fto(iTest, 1, Test)
    {
        Solve();
    }

    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}