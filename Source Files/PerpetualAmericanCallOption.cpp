#include "PerpetualAmericanCallOption.h"

PerpetualAmericanCallOption::PerpetualAmericanCallOption() : BlackScholesPricer() {}
PerpetualAmericanCallOption::~PerpetualAmericanCallOption() {}

PerpetualAmericanCallOption::PerpetualAmericanCallOption(double S, double K, double r, double sigma, double b) : BlackScholesPricer(S, K, 0.0, r, sigma, b) {}
PerpetualAmericanCallOption::PerpetualAmericanCallOption(const PerpetualAmericanCallOption& american_option) : BlackScholesPricer(american_option) {}

PerpetualAmericanCallOption& PerpetualAmericanCallOption::operator=(const PerpetualAmericanCallOption& rhs) {
	if (this == &rhs) return *this;
	BlackScholesPricer::operator=(rhs);
	return *this;
}

double PerpetualAmericanCallOption::price() const {

	double y_one = (1.0 / 2.0) - (m_b / std::pow(m_sigma, 2))
		+ std::sqrt(std::pow(m_b / std::pow(m_sigma, 2) - (1.0 / 2.0), 2) + ((2 * m_r) / std::pow(m_sigma, 2)));

	return (m_K / (y_one - 1)) * std::pow((((y_one - 1) / y_one) * (m_S / m_K)), y_one);

}