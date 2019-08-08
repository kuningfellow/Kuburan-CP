// Extended Euclidan algorithm
// finds x and y such that
//  ax + by = GCD(a,b) <= Bezout Identitiy
// returns: GCD(a, b)
// GCD = greatest common divisor
template<typename T>
T EUclid(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  } else {
    T g = EUclid(b, a%b, x, y);
    T tmp = y;
    y = -a/b*y + x, x = tmp;
    return g;
  }
}
