#include <iostream>

/*int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}*/

long long gcd_fast(long long a, long long b)
{
  if (a > b) //so that we may divide the greater by the smaller
  {
    if (b == 0)
    {
      return a; //when we find no remainders, return that
    }
    return gcd_fast(b, (a % b)); // if there is a remainder, do the same, with the lesser number, and the remainder of the division
  }
  else //the other case
  {
    if (a == 0)
    {
      return b;
    }
    return gcd_fast((b % a), a);
  }
}

int main()
{
  long long a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
