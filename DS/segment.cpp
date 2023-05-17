#define lc (v<<1)
#define rc (lc|1)
#define mid ((l+r)>>1)
struct segment{
    int seg[maxn<<2], lazy[maxn<<2];
    void build(int v = 1, int l = 1, int r = maxn){
        if(r - l == 1){
            seg[v] = 0;
            return;
        }
        build(lc, l, mid);
        build(rc, mid, r);
        seg[v] = seg[lc] + seg[rc];
    }
    void shift(int v, int l, int r){
        if(!lazy[v])return;
        seg[v] += lazy[v];
        if(r - l == 1)
            lazy[v] = 0, return;
        lazy[lc] += lazy[v];
        lazy[rc] += lazy[v];
        lazy[v] = 0;
    }
    void update(int L, int R, int val, int v = 1, int l = 1, int r = maxn){
        if(r <= L or R <= l)
            return;
        shift(v);
        if(L <= l and r <= R){
            lazy[v] += val;
            shift(v);
            return;
        }        
        update(L, R, val, lc, l, mid);
        update(L, R, val, rc, mid, r);
        seg[v] = seg[lc] + seg[rc];
    }
    void query(int L, int R, int val, int v = 1, int l = 1, int r = maxn){
        if(r <= L or R <= l)
            return 0;
        shift(v);
        if(L <= l and r <= R){
            return seg[v];
        }        
        return query(L, R, val, lc, l, mid) + query(L, R, val, rc, mid, r);
    }
};