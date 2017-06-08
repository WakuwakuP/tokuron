#include <cstdio>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;

void permutation (vector<int> perm, vector<int> pre, vector<int> post, int n);
int check (vector<int> perm);

int countResult = 0;

int main() {
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> t(a, a + 10);
  vector<int> perm;
  int ans = 0;

  permutation(perm, perm, t, t.size());
  printf("%d", countResult);

  return 0;
}

void permutation (vector<int> perm, vector<int> pre, vector<int> post, int n) {
  int i, len, tmp;
  vector<int> rest, elem, tm;
  if (n > 0) {
    for (i = 0, len = post.size(); i < len; ++i) {
      rest = vector<int>(post.begin() + i, post.end());
      tm = rest;
      tm.erase(tm.begin() + i);
      elem = tm;
      copy(elem.begin(), elem.end(), back_inserter(pre));
      permutation(perm, pre, rest, n - 1);
    }
  } else {
    check (pre);
  }
}

int check (vector<int> perm) {
  int read = perm[6] * 1000 + perm[2] * 100 + perm[0] * 10 + perm[1];
  int write = perm[9] * 10000 + perm[6] * 1000 + perm[3] * 100 + perm[8] * 10 + perm[2];
  int talk = perm[8] * 1000 + perm[0] * 100 + perm[5] * 10 + perm[4];
  int skill = perm[7] * 10000 + perm[4] * 1000 + perm[3] * 100 + perm[5] * 10 + perm[5];

  if (read + write + talk == skill && perm[6] != 0 && perm[9] != 0 && perm[8] != 0 && perm[7] != 0) {
    countResult++;
  }
}
