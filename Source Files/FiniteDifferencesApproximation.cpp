#include "FiniteDifferencesApproximation.h"

#ifndef FINITE_DIFFERENCES_APPROXIMATION_CPP
#define FINITE_DIFFERENCES_APPROXIMATION_CPP

template <typename OptionType>
double FiniteDifferencesApproximation<OptionType>::Delta(BlackScholesPricer* option) {

	OptionType financial_instrument(*static_cast<OptionType*>(option));
	double current_asset_price = financial_instrument.asset_price(), h = 1E-3;

	financial_instrument.asset_price(current_asset_price + h);
	double price_1 = financial_instrument.price();

	financial_instrument.asset_price(current_asset_price - h);
	double price_2 = financial_instrument.price();

	return (price_1 - price_2) / (2 * h);

}

template <typename OptionType>
double FiniteDifferencesApproximation<OptionType>::Gamma(BlackScholesPricer* option) {

	OptionType financial_instrument(*static_cast<OptionType*>(option));
	double current_asset_price = financial_instrument.asset_price(), h = 1E-3;

	financial_instrument.asset_price(current_asset_price + h);
	double price_1 = financial_instrument.price();

	financial_instrument.asset_price(current_asset_price - h);
	double price_2 = financial_instrument.price();

	return (price_1 - 2 * option->price() + price_2) / std::pow(h, 2);

}

#endif