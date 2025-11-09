#include "candies.h"
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
const int BS = 333;
 
 
vector<ll> compute_function(const vector<int>& ops) {
  vector<ll> stk;
  stk.push_back(4e18);
  stk.push_back(2e18);
  for (auto delta : ops) {
    if (delta == 0) continue;
    if (delta > 0) {
      ll rem = delta, px = 0;
      while (true) {
        ll x = stk.back();
        if (x - px > rem) {
          stk.push_back(px + rem);
          stk.push_back(0);
          break;
        } 
        rem -= (x - px);
        stk.pop_back();
        px = stk.back();
        stk.pop_back();
      }
    } else {
      ll rem = -delta;
      while (true) {
        ll px = stk.back(); stk.pop_back();
        ll x = stk.back();
        if (x - px > rem) {
          stk.push_back(px + rem);
          break;
        }
        rem -= (x - px);
        stk.pop_back();
      }
    }
  }
  
  stk.push_back(0);
  stk.push_back(0);
  reverse(stk.begin(), stk.end());
  return stk;
}
 
vector<int> distribute_candies(
    vector<int> c, vector<int> l,
    vector<int> r, vector<int> v) {
  int n = c.size();
 
  
  // Sort each bucket increasingly by c[i] to facilitate easy evaluation of f.
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  for (int i = 0; i < n; i += BS) {
    int j = min(i + BS, n);
    sort(order.begin() + i, order.begin() + j, [&](int a, int b) {
      return c[a] < c[b];
    });
  }
 
  vector<ll> stk;
  vector<int> a(n, 0), na(n, 0);
  vector<vector<int>> ops(n / BS + 1);
 
  auto commit = [&](int bi) {
    if (ops[bi].empty()) return;
    int l = bi * BS, r = min(n, (bi + 1) * BS);
 
    // compute f(.) and evaluate it in all c[i] of this bucket
    auto stk = compute_function(ops[bi]);
    ll value = 0;
    int ptr = 0;
    for (int i = l; i < r; ++i) {
      int ci = c[order[i]];
      while (stk[ptr + 1] < ci) {
        if (ptr % 2 == 0)
          value += stk[ptr + 1] - stk[ptr];
        ++ptr;
      }
      if (ptr % 2 == 0) {
        na[order[i]] = value + (ci - stk[ptr]);
      } else {
        na[order[i]] = value;
      }
    }
  
    // Adapt for non-zero initial values.
    ll mind = 0, maxd = 0, nowd = 0;
    for (auto x : ops[bi]) {
      nowd += x;
      mind = min(mind, nowd);
      maxd = max(maxd, nowd);
    }
    for (int i = l; i < r; ++i) {
      ll hi = min(c[i] - maxd, (ll)a[i]);
      ll lo = -mind;
      if (lo < hi) 
        na[i] += hi - lo; 
    }
 
    // Housekeeping.
    for (int i = l; i < r; ++i) 
      a[i] = na[i];
    ops[bi].clear();
  };
 
  int q = l.size();
  for (int i = 0; i < q; ++i) {
    int bl = l[i] / BS, br = r[i] / BS;
    commit(bl); commit(br); 
    for (int j = l[i]; j <= r[i]; ) {
      if (j % BS == 0 && (j + BS - 1) <= r[i]) {
        ops[j / BS].push_back(v[i]);
        j += BS;
      } else {
        a[j] = max(0, min(a[j] + v[i], c[j]));
        j += 1;
      }
    }
  }
 
  for (int i = 0; i < n; i += BS)
    commit(i / BS);
  return a;
}