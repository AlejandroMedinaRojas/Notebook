#pragma once
#include <bits/stdc++.h>
using namespace std;

template<typename T, typename = void> struct is_pair : false_type {};
template<typename T> struct is_pair<T, void_t<typename T::first_type, typename T::second_type>> : true_type {};

template<typename T, typename = void> struct is_tuple : false_type {};
template<typename T> struct is_tuple<T, void_t<decltype(tuple_size<T>::value)>> : true_type {};

#define dbg(...) do { \
    const char* _s = #__VA_ARGS__; \
    auto _print = [&](auto&& self, const auto& dbgx) -> void { \
        using dbgX = decay_t<decltype(dbgx)>; \
        if constexpr (is_same_v<dbgX, bool>) { \
            cout << dbgx; \
        } \
        else if constexpr (is_arithmetic_v<dbgX> && !is_same_v<dbgX, bool> && !is_same_v<dbgX, char> && !is_same_v<dbgX, signed char> && !is_same_v<dbgX, unsigned char>) { \
            cout << dbgx; \
        } \
        else if constexpr (is_same_v<dbgX, char> || is_same_v<dbgX, signed char> || is_same_v<dbgX, unsigned char>) { \
            cout << dbgx; \
        } \
        else if constexpr (is_same_v<dbgX, string> || is_same_v<dbgX, string_view> || is_convertible_v<dbgX, const char*>) { \
            cout << dbgx; \
        } \
        else if constexpr (is_pair<dbgX>::value) { \
            cout << '{'; self(self, dbgx.first); cout << ", "; self(self, dbgx.second); cout << '}'; \
        } \
        else if constexpr (is_tuple<dbgX>::value && !is_pair<dbgX>::value) { \
            cout << '{'; \
            apply([&](auto&&... xs){ size_t i = 0; ((self(self, xs), cout << (++i == sizeof...(xs) ? "" : ", ")), ...); }, dbgx); \
            cout << '}'; \
        } \
        else if constexpr (is_convertible_v<dbgX, bool> && !is_arithmetic_v<dbgX>) { \
            cout << static_cast<bool>(dbgx); \
        } \
        else { \
            cout << "{ "; \
            for (auto& e : dbgx) { self(self, e); cout << " "; } \
            cout << "}"; \
        } \
    }; \
    auto _process_arg = [&](const auto& arg) { \
        while (*_s == ' ' || *_s == ',') ++_s; \
        const char* _b = _s; \
        int depth = 0; bool in_s = false, in_d = false; \
        while (*_s) { \
            char c = *_s; \
            if (!in_s && c == '\"') in_d = !in_d; \
            else if (!in_d && c == '\'') in_s = !in_s; \
            else if (!in_s && !in_d) { \
                if (c == '(' || c == '{' || c == '[') ++depth; \
                else if (c == ')' || c == '}' || c == ']') --depth; \
                else if (c == ',' && depth == 0) break; \
            } \
            ++_s; \
        } \
        cout.write(_b, _s - _b); cout << " = "; \
        _print(_print, arg); cout << "; "; \
    }; \
    ([&]<typename... Ts>(Ts&&... args){ ((_process_arg(args)), ...); })(__VA_ARGS__); \
    cout << '\n'; \
} while (0)