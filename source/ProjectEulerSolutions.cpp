//============================================================================
// Name        : ProjectEulerSolutions.cpp
// Author      : Pilots2013
// Version     : 0.0.1
// Copyright   : 
// Description : Solutions to ProjectEuler.net problems
//============================================================================

#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
#include <algorithm>
#include "palindrome.hpp"

constexpr int32_t MAX_NUMBER_VALUE = 1000;

int sum_first_3and5muls(int floor_value) //Sums multiples of 3 and 5 up to floor_value
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
int fib_even_sum(int floor_value) //Sums the even fibonacci numbers up to floor_value
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

        if(current_fib % 2 == 0) //Checks if current_fib is an even number
		{
			number_sum += current_fib;
		}

	}
	return number_sum;
}


int largest_prime(uint64_t n) //Precondition: n is larger or equal than 2.
							  //uint64 is necessary for large inputs
							  //This needs optimization
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


int main() {

	std::cout << palindrome::largest_prod_palindrome(5) << std::endl;
	return 0;
}
