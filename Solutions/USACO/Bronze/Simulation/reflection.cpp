#include <bits/stdc++.h>
#define INF INT_MAX
#define miniF INT_mini
#define ll long long
#define ull unsigned long long
#define ld long double
#define PB push_back 
#define PF push_front
#define P_F pop_front
#define P_B pop_back
#define F front
#define B back
#define f first
#define s second
#define MP make_pair
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b) for(ll i = a; i >= b; i--)
#define PI 3.14159265358979323846
 
using namespace std;
 
const ld EPSILON = 0.0000001;

int paints(int i, int j, vector<vector<int>> &m) {
  int n = m.size();
  return m[i][j] + m[i][n - 1 - j] + m[n - 1 - i][j] + m[n - 1 - i][n - 1 - j];
}

pair<int, int> to_zero_sector(int i, int j, int n) {
  if (i < n/2 and j < n/2) return MP(i, j);
  if (i < n/2) return MP(i, n - 1 - j);
  if (j < n/2) return MP(n - 1 - i, j);
  return MP(n - 1 - i, n - 1 - j);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, u; cin >> n >> u;
  vector<vector<int> > m(n, vector<int> (n));

  FOR(i, 0, n) {
    FOR(j, 0, n) {
      char c; cin >> c;
      if (c == '#') {
        m[i][j] = 1;
      }
    }
  }

  int min = 0;
  FOR(i, 0, n/2) {
    FOR(j, 0, n/2) {
      int k = paints(i, j, m);
      
      if (k == 0 or k == 4) {
        continue;
      }

      if (k%2) min++;
      else min += 2;
    }
  }

  cout << min << '\n';
  FOR(i, 0, u) {
    int x, y, xo, yo; cin >> x >> y;
    x--; y--;
    xo = x; yo = y;

    pair<int, int> p = to_zero_sector(x, y, n);
    x = p.f;
    y = p.s;

    int prev = paints(x, y, m);
    m[xo][yo] = 1 - m[xo][yo];
    int curr = paints(x, y, m);

    int prevAugment = 0;
    int currAugment = 0;

    if (prev%2) prevAugment = 1;
    else if (prev == 2) prevAugment = 2;

    if (curr%2) currAugment = 1;
    else if (curr == 2) currAugment = 2;

    min += currAugment - prevAugment;
    cout << min << '\n';
  }

  return 0;
}