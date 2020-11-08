int dp[22][2][22];
map<int, int>Prime;//, vis;
void Init() {
    Prime[2] = Prime[3] = Prime[5] = Prime[7] = 1;
    Prime[11] = Prime[13] = Prime[17] = Prime[19] = 1;
    //Prime[2] = Prime[3] = Prime[5] = Prime[7] = 1;
}
int rev(string s) {
    reverse(s.begin(), s.end());
    int ret = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1')ret += 1 << i;
    }
    //dbg(s, ret);
    return ret;
}

int rev(vector<int> &s) {
    reverse(s.begin(), s.end());
    int ret = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 1)ret |= 1 << i;
    }
    return ret;
}
vector<int> BIN(int x) {
    //dbg(x);
    bool flag = false;
    vector<int> digits;
    for (int i = 30; i >= 0; i--) {
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

int go(vector<int> &digits, int pos, bool flag, int sm, string x = "") {
    if (pos == nx) {
        // if (Prime[sm]) {
        //     //dbg(sm);
        //     rev(x);//dbg(x, rev(x));
        // }
        return (Prime[sm]);
    }
    int &ret = dp[pos][flag][sm];
    if (~ret) {
        //dbg("r");
        // / rev(x);
        return ret;
    }
    int tot = 0;
    int limit = (flag) ? digits[pos] : 1;
    for (int i = 0; i <= limit; i++) {
        bool newflag = flag;
        if (i < limit) newflag = 0;
        tot += go(digits, pos + 1, newflag, sm + i,  x += (i + '0'));
    }
    return ret = tot;
}




int solve(int x) {
    vector<int> digits = BIN(x);
    nx = digits.size();
   // dbg(digits);
    // dbg(rev(digits));
   // dbg(digits.size());
    memset(dp, -1, sizeof dp);
    return go(digits, 0, 1, 0);
}


///https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/submissions/
///762. Prime Number of Set Bits in Binary Representation
int countPrimeSetBits(int L, int R) {
    Init();
    //dbg(Prime);
    int r = solve(R);
    int l = solve(L - 1);
    //dbg(r, l);
    return r - l;
}



