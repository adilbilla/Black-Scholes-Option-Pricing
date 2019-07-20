#include "PricingUtil.h"
#include "BlackScholesPricer.h"

#include <stdexcept>
#include <algorithm>

#ifndef PRICING_UTIL_CPP
#define PRICING_UTIL_CPP

// utilize member function pointers to make pricing utilities as generic as possible

template <typename OptionType>
std::vector<double> PricingUtil::mesh_pricer(BlackScholesPricer* option, double (BlackScholesPricer::* function)() const,
					     std::size_t lower_bound, std::size_t upper_bound, std::size_t mesh_size) {

	OptionType financial_instrument(*static_cast<OptionType*>(option));
	std::vector<double> generated_prices;

	for (std::size_t price = lower_bound; price <= upper_bound; price += mesh_size) {

		financial_instrument.asset_price(price);
		generated_prices.push_back((financial_instrument.* function)());

	}

	return generated_prices;

}

template <typename OptionType>
std::vector<double> PricingUtil::matrix_pricer(const std::vector<std::vector<double>>& option_parameters, BlackScholesPricer* option,
					       double (BlackScholesPricer::* function)() const) {

	OptionType financial_instrument(*static_cast<OptionType*>(option));
	std::vector<double> generated_function_values;

	std::for_each(std::begin(option_parameters), std::end(option_parameters), [&](const std::vector<double>& option_params) {
			
		financial_instrument.modify_state(option_params);
		generated_function_values.push_back((financial_instrument.* function)());

		});

	return generated_function_values;

}

#endif
