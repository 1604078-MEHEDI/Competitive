//https://leetcode.com/problems/number-of-digit-one/submissions/
//Number of Digit One
class Solution {
public:
    int dp[16][2][16];
    vector<int> digits;
    int nx;
    int go(int pos, int flag, int sm) {
        if (pos == nx)return sm;
        int &ret = dp[pos][flag][sm];
        if (~ret) return ret;
        int tot = 0;
        int limit = (flag) ? digits[pos] : 9;
        for (int i = 0; i <= limit; i++) {
            if (i == 1)
                tot += go(pos + 1, flag && (i == limit), sm + 1);
            else tot += go(pos + 1, flag && (i == limit), sm);
        }
        return ret = tot;
    }

    int countDigitOne(int n) {
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        nx = digits.size();
        reverse(digits.begin(), digits.end());
        //dbg(digits)
        memset(dp, -1, sizeof dp);
        return go(0, 1, 0);
    }
};
