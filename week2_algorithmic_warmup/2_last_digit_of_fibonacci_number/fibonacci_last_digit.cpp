#include <iostream>

/*int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}*/

int get_fibonacci_last_digit_fast(int n)
{
    int one;
    int two = 1;
    int buff;

    for(int i = 0; i < n; i++)
    {
        buff = one;
        one = (one + two);
        if(one > 9)
        {
            one = one%10;
        }
        two = buff;
        //std::cout << one << std::endl;
    }

    return one;
}

int main()
{
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
}
