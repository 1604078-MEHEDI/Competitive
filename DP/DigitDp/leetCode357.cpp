vector<int> digits;
int n, nx;
int dp[12][2][2][1 << 11];

int go(int pos, int flag, int nonZero, int mask) {
    if (pos == n)return nonZero;
    int &ret = dp[pos][flag][nonZero][mask];
    if (~ret) return ret;
    int tot = 0;
    int limit = (flag) ? digits[pos] : 9;
    for (int i = 0; i <= limit; i++) {
        int newnonZero = nonZero;
        if (i != 0)newnonZero = 1;

        int newMask = mask;
        if (newnonZero)newMask |= (1 << i);
        int curBit = (mask & (1 << i));
        if (!curBit)
            tot += go(pos + 1, flag && (i == limit), newnonZero, newMask);
    }
    return ret = tot;
}

void Init(int x) {
    x = pow(10, x) - 1;
    while (x) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    n = digits.size();
    //dbg(n,digits);
    // dbg(nx,n);
}

//https://leetcode.com/problems/count-numbers-with-unique-digits/
//357. Count Numbers with Unique Digits
int countNumbersWithUniqueDigits(int n = 2) {
    Init(n);
    memset(dp, -1, sizeof dp);
    int ans = go(0, 1, 0, 0) + 1;
   // dbg(ans);
    return ans;
}
