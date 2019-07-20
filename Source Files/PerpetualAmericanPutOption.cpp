#include "PerpetualAmericanPutOption.h"

PerpetualAmericanPutOption::PerpetualAmericanPutOption() : BlackScholesPricer() {}
PerpetualAmericanPutOption::~PerpetualAmericanPutOption() {}

PerpetualAmericanPutOption::PerpetualAmericanPutOption(double S, double K, double r, double sigma, double b) : BlackScholesPricer(S, K, 0.0, r, sigma, b) {}
PerpetualAmericanPutOption::PerpetualAmericanPutOption(const PerpetualAmericanPutOption& american_option) : BlackScholesPricer(american_option) {}

PerpetualAmericanPutOption& PerpetualAmericanPutOption::operator=(const PerpetualAmericanPutOption& rhs) {
	if (this == &rhs) return *this;
	BlackScholesPricer::operator=(rhs);
	return *this;
}

double PerpetualAmericanPutOption::price() const {

	double y_two = (1.0 / 2.0) - (m_b / std::pow(m_sigma, 2))
		- std::sqrt(std::pow(m_b / std::pow(m_sigma, 2) - (1.0 / 2.0), 2) + ((2 * m_r) / std::pow(m_sigma, 2)));

	return (m_K / (1 - y_two)) * std::pow((((y_two - 1) / y_two) * (m_S / m_K)), y_two);

}