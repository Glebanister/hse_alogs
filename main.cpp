#include <bits/stdc++.h>
// #include "optimization.h" // only if solving on acm.math.spbu.ru
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

    std::map<int, std::pair<float, std::set<std::string>>> weird_1{{1, {0.01, {"hello", "hi"}}}};
    debug(weird_1);
    std::unordered_multimap<int, std::set<std::pair<int, int>>> weird_2{{2, {{}, {}}}, {}};
    debug(weird_2);
    std::vector<std::string> long_strings{"no", "sssssssssssssssssssssssssssssssssssssssss", "sdfssssssssssssssssssss", "hello", "hi", "how are you"};
    debug(long_strings);
    std::vector<std::pair<float, double>> short_strings{{1, 2}, {3, 4}};
    debug(short_strings);

    return 0;
}
