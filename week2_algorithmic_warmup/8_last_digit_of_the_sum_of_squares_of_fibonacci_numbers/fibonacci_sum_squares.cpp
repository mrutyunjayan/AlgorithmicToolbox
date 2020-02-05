#include <iostream>

unsigned long long fibonacci_fast(unsigned long long n);
unsigned long long fibonacci_partial_sum_fast(unsigned long long &from, unsigned long long &to);

const int pisano[60] = {0, 1, 2, 4, 7, 2, 0, 3, 4, 8, 3,
                        2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 7,
                        6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1,
                        4, 6, 1, 8, 0, 9, 0};

int fibonacci_sum_squares_naive(unsigned long long n)
{
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current = 1;
    unsigned long long sum = 1;

    for (unsigned long long i = 0; i < n - 1; ++i)
    {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

unsigned long long fibonacci_fast(unsigned long long n)
{
    if (n <= 1)
    {
        return n;
    }
    unsigned long long first = 0, second = 1, third;

    for (int i = 2; i <= n; i++)
    {
        third = (first + second) % 10;
        first = second;
        second = third;
    }

    return third % 10;
}

unsigned long long fibonacci_sum_squares_fast(unsigned long long &n)
{
    unsigned long long height, width, sum;

    height = fibonacci_fast(n % 60);
    width = fibonacci_fast((n + 1) % 60);

    sum = (height * width) % 10;
    return sum;
}

int main()
{
    unsigned long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
