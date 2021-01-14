//1. make a vector in a order without dups

set<int> sa(a.begin(), a.end());
    a.assign(sa.begin(), sa.end());

//2. max and min element in vector
auto a = *max_element(v.begin(), v.end());
auto b = *min_element(v.begin(), v.end());
