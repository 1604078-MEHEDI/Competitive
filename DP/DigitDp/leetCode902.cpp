vector<int> digits, a;
int n, nx;
int dp[12][2][2];

int go(int pos, int flag, int Start) {
    if (pos == n)return Start;
    int &ret = dp[pos][flag][Start];
    if (~ret) return ret;
    int tot = 0;
    if (Start == 0) {
        tot = go(pos + 1, 0, 0);
    }

    int limit = (flag) ? digits[pos] : a.back();
    for (int i = 0; i < nx; i++) {
        int x = a[i];
        if (x > limit)break;
        tot += go(pos + 1, flag && (x == limit), 1);
    }
    return ret = tot;
}

void Init(int x) {
    while (x) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    n = digits.size();
    // dbg(nx,n);
}


///https://leetcode.com/problems/numbers-at-most-n-given-digit-set/submissions/
int atMostNGivenDigitSet(vector<string>& Dig, int n) {
    Init(n);
    for (auto x : Dig) {
        a.push_back(stoi(x));
    }
    // dbg(a);
    // dbg(digits);
    nx = a.size();
    memset(dp, -1, sizeof dp);
    return go(0, 1, 0);
}
