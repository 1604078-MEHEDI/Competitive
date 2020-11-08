int dp[33][2][2];
vector<int> BIN(int x) {
    //dbg(x);
    bool flag = false;
    vector<int> digits;
    for (int i = 31; i >= 0; i--) {
        if (x & (1 << i)) {
            flag = true;
            digits.push_back(1);
        }
        else if (flag)digits.push_back(0);
    }
    //dbg(digits, x, rev(digits));
    return digits;
}


int nx;

int go(vector<int> &digits, int pos, bool flag, int prv) {
    if (pos == nx) return 1;
    int &ret = dp[pos][flag][prv];
    if (~ret) return ret;
    int tot = 0;
    int limit = (flag) ? digits[pos] : 1;
    for (int i = 0; i <= limit; i++) {
        bool newflag = flag;
        if (i < limit) newflag = 0;
        if (prv != 1 || i != 1)
            tot += go(digits, pos + 1, newflag, i);
    }
    return ret = tot;
}



///https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/submissions/
//600. Non-negative Integers without Consecutive Ones
int solve(int x) {
    vector<int> digits = BIN(x);
    nx = digits.size();
    memset(dp, -1, sizeof dp);
    return go(digits, 0, 1, 0);
}

int findIntegers(int n) {
    return solve(n);
}
