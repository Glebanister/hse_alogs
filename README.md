# My contest solving toolset

## What is this

In process of studying sometimes we solving contests and I use this template.

Template itself located in `main.cpp`.

## How to use it

First, make sure this code works on your machine:
```bash
make --version
clang-10 --version
```
If `acm.math.spbu.ru` is not your platform, you can't use `optimization.h` file, but you can simply copy and paste fast IO from there.
Let's solve A+B problem with this template, here is solution:

```c++
#include <bits/stdc++.h>
// #include "optimization.h" // only if solving on acm.math.spbu.ru !!!
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

    int a, b;
    std::cin >> a >> b;
    int result = a - b;
    debug(res);
    std::cout << result << std::endl;

    return 0;
}
```

You can put test to `input` file, if you don't want to type it every time you compile your code. Otherwise, you can compile with `make nlocal`, then you will be able to put your test in command line by yourself. By default, input read from `input`.
So, I type `make` in command line and it works like:

```c++
gleb@ZenBook:~/Documents/hse/y2/algo/prac$ cat input
7 3
gleb@ZenBook:~/Documents/hse/y2/algo/prac$ make
======= BEGIN =======
4
=======  END  =======
gleb@ZenBook:~/Documents/hse/y2/algo/prac$
```

## How to print-debug

You may notice that we didn't solve A+B problem correctly. So, we want to see out `res` variable. So we just add `debug(res)`:

```c++
int a, b;
std::cin >> a >> b;
int result = a - b;
debug(result);
std::cout << result << std::endl;
```

And now we type `make` in CL:

```bash
======= BEGIN =======
result: 4
4
=======  END  =======
```

`debug` is extremely powerful:

```c++
std::map<int, std::pair<float, std::set<std::string>>> weird_1{{1, {0.01, {"hello", "hi"}}}};
debug(weird_1);
std::unordered_multimap<int, std::set<std::pair<int, int>>> weird_2{{2, {{}, {}}}, {}};
debug(weird_2);
std::vector<std::string> long_strings{"no", "sssssssssssssssssssssssssssssssssssssssss", "sdfssssssssssssssssssss", "hello", "hi", "how are you"};
debug(long_strings);
std::vector<std::pair<float, double>> short_strings{{1, 2}, {3, 4}};
debug(short_strings);
```

We getting pretty result:

```bash
======= BEGIN =======
weird_1: {1: (0.010000, ["hello", "hi"])}
weird_2: [(0, []), (2, [(0, 0)])]
long_strings: ["no",
"sssssssssssssssssssssssssssssssssssssssss",
"sdfssssssssssssssssssss",
"hello",
"hi",
"how are you"]
short_strings: [(1.000000, 2.000000), (3.000000, 4.000000)]
=======  END  =======
```

Works with a lot of `STL` containers.
