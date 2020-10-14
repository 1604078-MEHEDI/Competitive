#include "solution.hpp"
using namespace std;


////https://binarysearch.com/room/Weekly-Contest-24-t9gad8UJRv?questionsetIndex=3


/*
You are given a list of non-negative integers nums and a two-dimensional list of integers queries where each element contains [x, limit].

Return a list such that for each query [x, limit], we find an e in nums such that e ≤ limit and XOR(e, x) is maximized. If there's no such e, use -1.
*/
class Trie {
public:
  int val;
  Trie* mp[2];
  Trie(int x) {
    val = x;
    mp[0] = mp[1] = NULL;
  }
};

Trie* root;

class Solution {
public:
  void Insert(int x) {
    auto tm = root;
    for (int i = 31;  i >= 0; i--) {
      if (x & (1 << i)) {
        if (!tm->mp[1])tm->mp[1] = new Trie(1);
        tm = tm->mp[1];
      }
      else {
        if (!tm->mp[0])tm->mp[0] = new Trie(0);
        tm = tm->mp[0];
      }
    }
  }

  int Find(int x) {
    int ans = 0;
    auto tm = root;
    for (int i = 31; i >= 0; i--) {
      int req_bit = (((1 << i)&x) == 0);
      if (tm->mp[req_bit]) {
        tm = tm->mp[req_bit];
        if (req_bit == 1)ans |= 1 << i;
      }
      else {
        tm = tm->mp[req_bit ^ 1];
        if (req_bit == 0)ans |= 1 << i;
      }
    }
    return ans;
  }

  vector<int> solve(vector<int> &a, vector<vector<int>> &Q) {
    root = new Trie(0);
    int n = a.size();
    sort(a.begin(), a.end());
    if (Q.size() == 0)return {};
    vector<int> ans(Q.size());
    pair<int, pair<int, int>> queries[Q.size() + 1];

    for (int i = 0; i < Q.size(); i++)
      queries[i] = {Q[i][1], {Q[i][0], i}};

    sort(queries, queries + Q.size());
    int j = 0;

    for (int i = 0; i < Q.size(); i++) {
      int lim = queries[i].first;
      int x = queries[i].second.first;
      int id = queries[i].second.second;
      while (j < n && lim >= a[j]) {
        Insert(a[j]);
        j++;
      }
      if (j == 0)ans[id] = -1;
      else ans[id] = Find(x);
    }
    return ans;

  }
};
