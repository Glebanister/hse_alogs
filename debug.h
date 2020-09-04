#pragma once

#include <type_traits>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

#undef debug
#define debug(value) std::cerr << BOLDYELLOW << #value << ": " << RESET << BOLDYELLOW << debug_impl_(value) << std::endl \
                               << RESET

constexpr std::size_t max_string_len = 40;

inline std::string debug_impl_(const std::string &x);
template <typename T, typename = std::enable_if_t<std::is_same_v<std::string, decltype(std::to_string(std::declval<T>()))>>>
inline std::string debug_impl_(const T &x);
template <typename T, typename U>
inline std::string debug_impl_(const std::pair<T, U> &x);
template <typename T, typename U>
inline std::string debug_impl_(const std::map<T, U> &x);
template <typename T, typename U>
inline std::string debug_impl_(const std::unordered_map<T, U> &x);
template <typename T, std::void_t<decltype(std::declval<T>().begin())> * = nullptr>
inline std::string debug_impl_(const T &x);

inline std::string debug_impl_(const std::string &x)
{
    return "\"" + x + "\"";
}

template <typename T, typename>
inline std::string debug_impl_(const T &x)
{
    return std::to_string(x);
}

template <typename T, typename U>
inline std::string debug_impl_(const std::pair<T, U> &x)
{
    return "(" + debug_impl_(x.first) + ", " + debug_impl_(x.second) + ")";
}

template <typename T, typename U>
inline std::string debug_impl_(const std::map<T, U> &x)
{
    std::string res = "{";
    int cnt = 0;
    for (const auto &[key, value] : x)
    {
        res += debug_impl_(key) + ": " + debug_impl_(value);
        if (++cnt != x.size())
        {
            res += ", ";
        }
    }
    return res + "}";
}

template <typename T, typename U>
inline std::string debug_impl_(const std::unordered_map<T, U> &x)
{
    std::string res = "{";
    int cnt = 0;
    for (const auto &[key, value] : x)
    {
        res += debug_impl_(key) + ": " + debug_impl_(value);
        if (++cnt != x.size())
        {
            res += ", ";
        }
    }
    return res + "}";
}

template <typename T, std::void_t<decltype(std::declval<T>().begin())> *>
inline std::string debug_impl_(const T &x)
{
    std::string res = "[";
    std::vector<std::string> results;
    std::size_t max_len = 0;
    for (auto it = x.begin(); it != x.end();)
    {
        std::string cur = debug_impl_(*it);
        if (++it != x.end())
        {
            cur += ",";
        }
        max_len = std::max(max_len, cur.size());
        results.emplace_back(std::move(cur));
    }

    std::string delim = " ";

    if (max_len > max_string_len)
    {
        delim = "\n";
    }

    int cnt = 0;
    for (auto &&str : results)
    {
        res += std::move(str);
        if (++cnt != results.size())
        {
            res += delim;
        }
    }

    res += "]";
    return res;
}

// template <typename T, std::is_same_v<std::> * = nullptr>
// inline std::string debug_impl_(const T &x)
// {
//     return std::to_string(x);
// }
