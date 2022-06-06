bits/stdc++.h>
namespace std;

int long long
endl '\n'

MOD = 1e9 + 7;
INF = LLONG_MAX >> 1;

class node, class F = std::function<node(const node &, const node &)>>
SegTree {
0;
vector<node> t;
F unite;

build(const int x, const int l, const int r, const std::vector<node> &a) {
== r) {
= a[l];
return;

int mid = (l + r) / 2;
int y = 2 * (mid - l + 1) + x;
x + 1, l, mid, a);
y, mid + 1, r, a);
unite(t[x + 1], t[y]);


update(const int x, const int l, const int r, const int p, const node &v) {
== p and p == r) {
= v;
return;

int mid = (l + r) / 2;
int y = 2 * (mid - l + 1) + x;
<= mid) {
update(x + 1, l, mid, p, v);
{
update(y, mid + 1, r, p, v);

t[x] = unite(t[x + 1], t[y]);
}

node query(const int x, const int l, const int r, const int ql, const int qr) const {
if (ql <= l and r <= qr) {
return t[x];
}
const int mid = (l + r) / 2;
const int y = 2 * (mid - l + 1) + x;
if (qr <= mid) {
return query(x + 1, l, mid, ql, qr);
} else if (mid < ql) {
return query(y, mid + 1, r, ql, qr);
} else {
return unite(query(x + 1, l, mid, ql, qr), query(y, mid + 1, r, ql, qr));
}
}

public:
SegTree() = default;
explicit SegTree(const int n, const node e, F f) : n(n), t(2 * n - 1, e), unite(std::move(f)) {}
explicit SegTree(const std::vector<node> &a, F f) : n(a.size()), t(2 * (a.size()) - 1), unite(std::move(f)) {
build(0, 0, n - 1, a);
}

void set(const int p, const node &v) {
assert(0 <= p and p < n);
update(0, 0, n - 1, p, v);
}

node get(const int l, const int r) const {
assert(0 <= l and l <= r and r < n);
return query(0, 0, n - 1, l, r);
}
};

signed main() {
ios::sync_with_stdio(false); cin.tie(NULL);

string s; cin >> s;
int n = s.size();

int q; cin >> q;

vector<int> a;
for (auto i : s)
a.push_back(1 << (i - 'a'));

SegTree seg(a, [](int x, int y) {return x | y;});

while (q--) {
int typ; cin >> typ;
if (typ == 1) {
int pos; char c;
cin >> pos >> c; pos--;

seg.set(pos, 1 << (c - 'a'));

} else {
int l, r; cin >> l >> r;
l--; r--;

cout << __builtin_popcount(seg.get(l, r)) << endl;
}
}
}