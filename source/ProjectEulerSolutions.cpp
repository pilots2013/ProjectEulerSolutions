//============================================================================
// Name        : 3.cpp
// Author      : Pilots2013
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
#include <algorithm>

constexpr int32_t MAX_NUMBER_VALUE = 1000;

int sum_first_3and5muls(int floor_value)
{
	int number_sum = 0;
	for(int i = 1; i < floor_value; ++i)
	{
		if(i % 3 == 0 || i % 5 == 0)
				{
					number_sum += i;
				}
	}
	return number_sum;
}
int fib_even_sum(int floor_value)
{
	int number_sum = 0;
	int current_fib = 1; //Current fibonacci number
	int prev_fib = 0; //Previous fibonacci number
	int temp_fib = 0; //Temp fibonacci number used in the loop

	while(current_fib < floor_value)
	{
		temp_fib = current_fib;
		current_fib += prev_fib;
		prev_fib = temp_fib;

        if(current_fib % 2 == 0)
		{
			number_sum += current_fib;
		}

	}
	return number_sum;
}


int largest_prime(uint64_t n) //Precondition: n is larger or equal than 2
{
	int largest_prime {0};
	bool is_prime {0};

	if(n % 2 == 0) //Checks first if n is an even number, if so skips the whole factorization part
		largest_prime = n / 2;
	else
	{
		for(int factor = 1; factor <= sqrt(n); factor = factor + 2)
		{

			if (n % factor == 0) //If n is divisible by factor, check if factor is a prime (inside)
			{
				is_prime = 1;

				for(int prime_test = 3; is_prime && (prime_test <= sqrt(factor)); prime_test = prime_test + 2) //Checks if factor is a prime
				{
					if (factor % prime_test == 0) //If true, factor is not a prime
					{
						is_prime = false;
					}
				}

				if(is_prime) //If it is indeed a prime assigns largest_prime to it
				{
					largest_prime = factor;
				}

			}
		}
	}

	return largest_prime;
}

int largest_palindrome(const int product_digits)
{

	int i = round(pow(10, product_digits - 1));
	int j = i;
	int product {0};
	int palindrome = 1;

	std::string check1, check2;
	const int max_value = round(pow(10, product_digits));

	while (i < max_value)
	{

		j = i;
		while(j < max_value)
		{
			product = i * j;
			++j;
			check1 = std::to_string(product);
			check2 = check1;
			std::reverse(check2.begin(), check2.end());
			if(check1 == check2 && product > palindrome)
			{
				palindrome = std::stoi(check1);
			}
		}
		++i;


	}
    return palindrome;
}
int main() {

	std::cout << largest_palindrome(3) << std::endl;
	return 0;
}
