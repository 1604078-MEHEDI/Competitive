
//https://leetcode.com/problems/find-all-good-strings/submissions/
//1397. Find All Good Strings
class Solution {
public:
    ///Time: O(n*m*2*2*26), where n<=500, m<=50 is length of evil
    int dp[505][55][2][2] = {};
    int findGoodStrings(int n, string s1, string s2, string evil) {
        return go(0, 0, true, true, n, s1, s2, evil, computeLPS(evil));
    }

    int go(int i, int evilMatched, bool leftBound, bool rightBound,
           int n, string &s1, string &s2, string &evil, const vector<int> lps) {
        if (evilMatched == (int)evil.size())return 0; // contain `evil` as a substring -> not good string
        if (i == n)return 1; // good string
        int &ret = dp[i][evilMatched][leftBound][rightBound];
        if (ret)return ret;
        char from = leftBound ? s1[i] : 'a';
        char to = rightBound ? s2[i]  : 'z';
        int res = 0;
        for (char ch = from; ch <= to; ch++) {
            int j = evilMatched;
            while (j > 0 && evil[j] != ch)j = lps[j - 1];
            if (ch == evil[j])j++;
            res += go(i + 1, j, leftBound && (ch == from), rightBound && (ch == to), n, s1, s2, evil, lps);
            res %= 1000000007;
        }
        return ret = res;
    }


// longest prefix also suffix
    vector<int> computeLPS(const string &str) {
        int n = str.size();
        vector<int> lps = vector<int> (n);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && str[i] != str[j])j = lps[j - 1];
            if (str[i] == str[j])lps[i] = ++j;
        }
        return lps;
    }
};
