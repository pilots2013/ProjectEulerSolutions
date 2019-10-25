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
#include "numerics.hpp"

inline void fib_advance(uint64_t& previous, uint64_t& current)
{
	uint64_t temporary {current}; //Temporary used as support to advance in the fib series
	current += previous;
	previous = temporary;
}

uint64_t fib_even_sum(uint64_t floor_value) //Sums the even fibonacci numbers up to floor_value
{
	uint64_t number_sum {0};
	uint64_t current_fib {1}; //Current fibonacci number
	uint64_t prev_fib {0}; //Previous fibonacci number


	while(current_fib < floor_value)
	{
		fib_advance(prev_fib, current_fib);

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

	std::cout << numerics::sum_first_muls(1500000, {2, 3, 5}) << std::endl;
	return 0;
}
