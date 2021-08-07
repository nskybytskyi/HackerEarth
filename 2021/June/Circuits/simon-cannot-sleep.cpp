#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int hh, mm; char colon;
  cin >> hh >> colon >> mm;
  int c = 0;
  if (hh >= 12) {
    c = 11;
    hh -= 12;
  }
  c += hh;
  if (60. * hh / 11. <= mm) {
    ++c;
  }
  cout << c << "\n";
  return 0;
}