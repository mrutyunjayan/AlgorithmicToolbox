#include <iostream>

unsigned long long pisano_period(const long long &m);
unsigned long long get_fibonacci_huge_fast(const unsigned long long &n, const unsigned long long &m);

unsigned long long pisano_period(const long long &m)
{
    unsigned long long first = 0, second = 1, third;

    for (int i = 0; i < m * m; i++)
    {
        third = (first + second) % m;
        first = second;
        second = third;
        if (first == 0 && second == 1)
        {
            return i + 1;
        }
    }
}

unsigned long long get_fibonacci_huge_fast(unsigned long long &n, const unsigned long long &m)
{
    n = n % pisano_period(m);
    unsigned long long first = 0, second = 1, third = n;

    for (int i = 1; i < n; i++)
    {
        third = (second + first) % m;
        first = second;
        second = third;
    }

    return third % m;
}


int main()
{
    unsigned long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
