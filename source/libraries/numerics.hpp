/*
 * numerics.hpp
 *
 *  Created on: 25 ott 2019
 *      Author: Simone Giordano
 */

#ifndef SOURCE_LIBRARIES_NUMERICS_HPP_
#define SOURCE_LIBRARIES_NUMERICS_HPP_

#include <cstdint>
#include <iostream>

namespace numerics
{
	uint64_t sum_first_muls(const uint64_t, std::initializer_list<int>); //const int represents the floor value
																	//initializer list contains the multiples to consider
};



#endif /* SOURCE_LIBRARIES_NUMERICS_HPP_ */
