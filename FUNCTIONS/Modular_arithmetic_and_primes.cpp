template<typename T>
T ExtGCD(T a, T b, T& x, T& y) {
    x = 1, y = 0;
    T x1 = 0, y1 = 1;
    while (b){
        T q = a / b;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b, a - q * b);
    }
    return a;
}

template <typename T>
bool IsPrime(T x){
    if (x == 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (T i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

template<typename T>
vector<T> Eratosthenes(T n){
    vector<bool> isprime(n + 1, true);
    vector<T> primes;
    isprime[0] = isprime[1] = false;
    for (T i = 2; i * i <= n; ++i){
        if (isprime[i]){
            for (T j = i * i; j <= n; j += i){
                isprime[j] = false;
            }
        }
    }
    for (T i = 2; i <= n; ++i){
        if (isprime[i]) primes.push_back(i);
    }
    return primes;
}

template<typename T>
map<T, int> PrimeComposition(T x){
    map<T, int> prime_composition;
    while (x % 2 == 0){
        ++prime_composition[2];
        x /= 2;
    }
    while (x % 3 == 0){
        ++prime_composition[3];
        x /= 3;
    }
    for (T i = 5; i * i <= x; i += 6){
        while (x % i == 0){
            ++prime_composition[i];
            x /= i;
        }
        while (x % (i + 2) == 0){
            ++prime_composition[i + 2];
            x /= i + 2;
        }
    }
    if (x > 1)++prime_composition[x];
    return prime_composition;
}

// ExtGCD
// Time complexity: O(log min(a, b))
// Space complexity: O(1)

// IsPrime
// Time complexity: O(√n)
// Space complexity: O(1)

// EratosthenesSieve
// Time complexity: O(n log log n)
// Space complexity: O(n)

// PrimeComposition
// Time complexity: O(√n)
// Space complexity: O(log n)