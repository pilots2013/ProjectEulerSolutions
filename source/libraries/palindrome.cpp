/*
 * palindrome.cpp
 *
 *  Created on: 24 ott 2019
 *      Author: Simone Giordano
 */
#include "palindrome.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>

namespace palindrome
{

uint64_t largest_prod_palindrome(const int product_digits) //Returns the highest integer palindrome obtained by the product of integers
												 //of product_digits number of digits
	{

		const uint64_t max_value = round(pow(10, product_digits));
		uint64_t first_term = max_value; // This will make both first_term and second_term start from the minimum value of
															 // product_digits number of digits
		uint64_t second_term = first_term;
		uint64_t product {0};
		uint64_t palindrome = 1;

		std::string check1, check2;
		const uint64_t min_value = round(pow(10, product_digits-1)); //Round functions is used due to some miscalculations where max_valued was truncated to 99

		while (first_term > min_value)
		{

			second_term = first_term;
			while(second_term > min_value)
			{
				product = first_term * second_term;
				--second_term;
				if (product <= palindrome)
				{
					break;
				}


					check1 = std::to_string(product);  //These instructions convert the product to string
					check2 = check1;				   //then checks if the product string and it's reverse are equal
					std::reverse(std::begin(check2), std::end(check2)); 	//REMINDER: This could be a function of it's own


				if(check1 == check2 && product > palindrome) //Checks for equality and if the candidate palindrome is largest than palindrome
				{
					palindrome = product;
				}
			}
			--first_term;


		}
		return palindrome;
	}

};
