struct cmp {
	bool operator()(const Edge &x, const Edge &y) const { return x.w < y.w; }
};

set<Edge, cmp> v;