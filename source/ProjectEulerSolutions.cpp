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

int largest_palindrome(const int product_digits) //Returns the highest integer palindrome obtained by the product of integers
												 //of product_digits number of digits
{

	int first_term = round(pow(10, product_digits - 1)); // This will make both first_term and second_term start from the minimum value of
														 // product_digits number of digits
	int second_term = first_term;
	int product {0};
	int palindrome = 1;

	std::string check1, check2;
	const int max_value = round(pow(10, product_digits)); //Round functions is used due to some miscalculations where max_valued was truncated to 99

	while (first_term < max_value)
	{

		second_term = first_term;
		while(second_term < max_value)
		{
			product = first_term * second_term;
			++second_term;

			check1 = std::to_string(product);  //These instructions convert the product to string
			check2 = check1;				   //then checks if the product string and it's reverse are equal
			std::reverse(check2.begin(), check2.end()); 	//REMINDER: This could be a function of it's own

			if(check1 == check2 && product > palindrome) //Checks for equality and if the candidate palindrome is largest than palindrome
			{
				palindrome = std::stoi(check1);
			}
		}
		++first_term;


	}
    return palindrome;
}
int main() {

	std::cout << largest_palindrome(3) << std::endl;
	return 0;
}
