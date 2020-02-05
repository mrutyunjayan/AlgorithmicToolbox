#include <iostream>
#include <vector>
#include <cmath>
using std::vector;

unsigned long long fibonacci_sum_fast(unsigned long long &n);
unsigned long long fibonacci_partial_sum_fast(unsigned long long &n, unsigned long long &m);
unsigned long long fibonacci_fast(unsigned long long n);

const int pisano[60] = {0, 1, 2, 4, 7, 2, 0, 3, 4, 8, 3,
                        2, 6, 9, 6, 6, 3, 0, 4, 5, 0, 6, 7, 4, 2, 7, 0, 8, 9, 8, 8, 7,
                        6, 4, 1, 6, 8, 5, 4, 0, 5, 6, 2, 9, 2, 2, 5, 8, 4, 3, 8, 2, 1,
                        4, 6, 1, 8, 0, 9, 0};

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    long long sum = 0;

    long long current = 0;
    long long next = 1;

    for (long long i = 0; i <= to; ++i)
    {
        if (i >= from)
        {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

unsigned long long fibonacci_sum_fast(unsigned long long &n)
{
    n = n % 60; // The Pisano Period of 10 is 60;
    return pisano[n];
}

unsigned long long fibonacci_partial_sum_fast(unsigned long long &from, unsigned long long &to)
{
    long long sum = 0;
    if (from == to)
    {
        return fibonacci_fast(from % 60) % 10; //if m and n are the same return the sum Fn till then
    }
    else
    {
        from %= 60;
        to %= 60;

        from = fibonacci_fast(from + 1) - 1; //Sum(Fn) = Fn+2 -1, for the lower number, the sum is up till the number, not inclusive of it
        to = fibonacci_fast(to + 2) - 1;
        /*if ((to - from) > 0)
        {
            sum = (to - from) % 10;
            return abs(sum);
        }*/
        return (to - (from % 10) + 10) % 10; //to correctly calculate the remainders of negative numbers
    }
}


unsigned long long fibonacci_fast(unsigned long long n)
{

    unsigned long long arr[n + 1]; //Create an array of size 'n' to store all the fibonacci numbers
    arr[0] = 0;
    arr[1] = 1; //Initialize the first two numbers

    for (int i = 2; i < n + 1; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[n];
}

int main()
{
    unsigned long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_partial_sum_fast(from, to) << '\n';
}
