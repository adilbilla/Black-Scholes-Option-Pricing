#include <vector>
#include <algorithm>

#include "BlackScholesPricer.h"

#ifndef PRICING_UTIL_H
#define PRICING_UTIL_H


struct PricingUtil {

	template <typename OptionType>
	static std::vector<double> mesh_pricer(BlackScholesPricer* option, double (BlackScholesPricer::* function)() const,
					       std::size_t lower_bound, std::size_t upper_bound, std::size_t mesh_size);

	template <typename OptionType>
	static std::vector<double> matrix_pricer(const std::vector<std::vector<double>>& option_parameters, BlackScholesPricer* option,
						 double (BlackScholesPricer::* function)() const);

};

#ifndef PRICING_UTIL_CPP
#include "PricingUtil.cpp"
#endif

#endif
