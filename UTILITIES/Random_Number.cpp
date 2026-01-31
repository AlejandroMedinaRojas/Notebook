mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
T RandVal(T lo = numeric_limits<T>::min(), T hi = numeric_limits<T>::max()) {
    return uniform_int_distribution<T>(lo, hi)(rng);
}