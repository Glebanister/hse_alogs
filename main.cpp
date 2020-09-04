#include <bits/stdc++.h>
#include "optimization.h"
#define debug(expr)
#ifdef LOCAL
#include "debug.h"
#endif

signed main()
{
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    auto a = 10;
    std::map<int, std::pair<float, std::set<std::string>>> x{{1, {0.01, {"hello", "hi"}}}};
    debug(x);

    return 0;
}
