#include <iostream>
#include <algorithm>
using namespace std;

struct pos {
  long long p;
  int c;
} a[100005];
long long s[100005];

bool cmp(pos &p1, pos &p2) {
  return p1.c > p2.c;
}

int main() {
  int n;
  long long m;
  cin>>n>>m;
  for (int i=1; i<=n; i++)
    cin>>a[i].p>>a[i].c;
  sort(a+1, a+1+n, cmp);
  
  for (int i=1; i<=n; i++)
    s[i] = s[i-1]+a[i].p;
  int i = n;
  while (s[i-1] >= m)
    i--;
  int cnt = a[i].c;
  long long ans = a[i].c*m;
  while (i >= 1)
    ans += (a[i].c-cnt)*a[i].p, i--;
  cout<<ans<<'\n';
  
  return 0;
}
