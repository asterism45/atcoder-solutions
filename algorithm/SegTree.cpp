//RMQ用のSeg(指定区間のMax欲しい)
//st.query(l, r, 1, st.siz + 1, 1)
class SegmentTree {
public:
    ll siz = 1;
    vll dat;
    SegmentTree(ll N) {
        while (siz < N) siz *= 2;
        dat.resize(2 * siz);
        rep(i, 2 * siz) dat[i] = 0;
    }
    void update(ll pos, ll x) {
        ll num = pos + siz - 1;
        dat[num] = x;
        while ((num /= 2) != 0)
            // ここを変更する
            dat[num] = max(dat[2 * num], dat[2 * num + 1]);
    }
    ll query(ll l, ll r, ll a, ll b, ll u) {
        // returnを変更する
        if (b <= l || r <= a)
            return -INF;
        else if (l <= a && b <= r)
            return dat[u];

        ll m = (a + b) / 2;
        return max(query(l, r, a, m, 2 * u), query(l, r, m, b, 2 * u + 1));
    }
};