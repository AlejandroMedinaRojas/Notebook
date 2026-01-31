template<typename T>
T StringToInt128(const string& s) {
    T number = 0;
    size_t i = 0;
    bool neg = false;
    if (is_signed_v<T>){
        if (s[0] == '-'){
            neg = true;
            i = 1;
        }
    }
    for (; i < s.size(); ++i){
        number = number * 10 + (s[i] - '0');
    }
    if (is_signed_v<T>) return neg? -number : number;
    return number;
}

template<typename T>
string Int128ToString(T number) {
    if (number == 0) return "0";
    bool neg = false;
    if (is_signed_v<T>){
        if (number < 0){
            neg = true;
            number = -number;
        }
    }
    string s;
    while (number > 0) {
        s.push_back('0' + number % 10);
        number /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

// StringToInt128
// Time complexity O(s)
// Space complexity O(1)

// Int128ToString
// Time complexity O(s)
// Space complexity O(s)