#include <iostream>

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
}

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
    return gcd_fast(a, (b % a));
  }
}

long long lcm_fast(long long a, long long b)
{
  long long gcd;
  gcd = gcd_fast(a, b); //compute gcd of the two numbers
  //std::cout << gcd << std::endl;
  a = a / gcd;  // divide one of the number by the gcd
  return a * b; // lcm is the result
}

int main()
{
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
