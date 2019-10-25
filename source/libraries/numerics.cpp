/*
 * numerics.cpp
 *
 *  Created on: 25 ott 2019
 *      Author: Simone Giordano
 */

#include "numerics.hpp"

namespace numerics
{
	uint64_t sum_first_muls(const uint64_t floor_value,
					   	   	std::initializer_list<int> muls_list)
	{								//Sums multiples of numbers list in	initializer list up to floor_value
		uint64_t number_sum = 0;

		for(uint64_t current_number = 1; //iterating up to floor_value
			current_number < floor_value;
			++current_number)
		{
			for(auto mul : muls_list) //Iterating initializer list
			{
				if(current_number % mul == 0)
				{
					number_sum += current_number;
					break; //Needed in order to avoid current_number to be counted more than once
				}
			}

		}
		return number_sum;
	}
};
