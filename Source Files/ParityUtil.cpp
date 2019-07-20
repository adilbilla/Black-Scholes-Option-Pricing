#include "ParityUtil.h"

#include <boost/tuple/tuple.hpp>

#include <cmath>
#include <iostream>

bool ParityUtil::PutCallParityCheck(const EuropeanCallOption& eco, const EuropeanPutOption& epo) {

	double call_price = eco.price(), put_price = epo.price();

	double strike_price = eco.strike_price(),
		risk_free_interest_rate = eco.risk_free_interest_rate(),
		exercise_date = eco.exercise_date(),
		asset_price = eco.asset_price();

	double rhs = call_price + strike_price * std::exp(-risk_free_interest_rate * exercise_date),
		lhs = put_price + asset_price,
		epsilon = .0001;

	return std::abs(rhs - lhs) < epsilon;
}

double ParityUtil::compute_call_price(const EuropeanPutOption& epo) {

	double put_price = epo.price(),
		strike_price = epo.strike_price(),
		risk_free_interest_rate = epo.risk_free_interest_rate(),
		exercise_date = epo.exercise_date(),
		asset_price = epo.asset_price();

	return put_price + asset_price - strike_price * std::exp(-risk_free_interest_rate * exercise_date);

}

double ParityUtil::compute_put_price(const EuropeanCallOption& eco) {

	double call_price = eco.price(),
		strike_price = eco.strike_price(),
		risk_free_interest_rate = eco.risk_free_interest_rate(),
		exercise_date = eco.exercise_date(),
		asset_price = eco.asset_price();

	return call_price + strike_price * std::exp(-risk_free_interest_rate * exercise_date) - strike_price;

}