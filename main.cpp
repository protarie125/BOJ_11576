#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll a, b, m;
vl D;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> a >> b >> m;

  D = vl(m);
  for (auto&& x : D) {
    cin >> x;
  }

  reverse(D.begin(), D.end());

  auto total = 0LL;
  auto q = 1LL;
  for (auto i = 0; i < m; ++i) {
    total += q * D[i];
    q *= a;
  }

  if (0 == total) {
    cout << 0;
    return 0;
  }

  auto ans = vl{};
  while (0 < total) {
    ans.push_back(total % b);
    total /= b;
  }

  for (auto i = ans.rbegin(); i != ans.rend(); ++i) {
    cout << *i << ' ';
  }

  return 0;
}