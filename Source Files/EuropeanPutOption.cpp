#include "EuropeanPutOption.h"
#include "StatisticsEngine.h"
#include <cmath>

EuropeanPutOption::EuropeanPutOption(double S, double K, double T, double r, double sigma, double b) :
	BlackScholesPricer(S, K, T, r, sigma, b) {}

EuropeanPutOption::EuropeanPutOption(const EuropeanPutOption& source) : BlackScholesPricer(source) {}

EuropeanPutOption::EuropeanPutOption() {}
EuropeanPutOption::~EuropeanPutOption() {}

EuropeanPutOption& EuropeanPutOption::operator=(const EuropeanPutOption& epo) {
	if (this == &epo) return *this;

	BlackScholesPricer::operator=(epo);

	return *this;
}

double EuropeanPutOption::price() const {

	double S, K, T, r, sigma, b;
	double d_one, d_two;

	boost::tie(S, K, T, r, sigma, b) = this->parameter_vector();
	boost::tie(d_one, d_two) = this->d_pairs();

	return (K * std::exp(-r * T) * StatisticsEngine::Normal_CDF(-d_two)) -
		(S * std::exp(b - r) * StatisticsEngine::Normal_CDF(-d_one));

}

// Option Sensitivities

double EuropeanPutOption::FairValue() const {

	double q = m_r - m_b;

	return std::exp(-m_r * m_T) * m_K * StatisticsEngine::Normal_CDF(-this->d_two())
		- m_S * std::exp(-q * m_T) * StatisticsEngine::Normal_CDF(-this->d_one());

}

double EuropeanPutOption::Delta() const {

	double q = m_r - m_b;

	return -std::exp(-q * m_T) * StatisticsEngine::Normal_CDF(-this->d_one());

}

double EuropeanPutOption::Vega() const {

	double q = m_r - m_b;

	return m_S * std::exp(-q * m_T) * StatisticsEngine::Normal_PDF(this->d_one()) * std::sqrt(m_T);

}

double EuropeanPutOption::Theta() const {

	double q = m_r - m_b;

	return -std::exp(-q * m_T) * ((m_S * StatisticsEngine::Normal_PDF(this->d_one()) * m_sigma) / (2 * std::sqrt(m_T)))
		- m_r * m_K * std::exp(-m_r * m_T) * StatisticsEngine::Normal_CDF(-this->d_two())
		+ q * m_S * std::exp(-q * m_T) * StatisticsEngine::Normal_CDF(-this->d_one());

}

double EuropeanPutOption::Rho() const {

	double q = m_r - m_b;

	return -m_K * m_T * std::exp(-m_r * m_T) * StatisticsEngine::Normal_CDF(-this->d_two());

}

double EuropeanPutOption::Lambda() const {

	return (this->Delta()) * (m_S / this->FairValue());

}

double EuropeanPutOption::Gamma() const {

	double q = m_r - m_b;

	return std::exp(-q * m_T) * (StatisticsEngine::Normal_PDF(this->d_one()) / (m_S * m_sigma * std::sqrt(m_T)));

}

double EuropeanPutOption::Vanna() const {

	return (this->Vega() / m_S) * (1 - (this->d_one() / (m_sigma * std::sqrt(m_T))));

}

double EuropeanPutOption::Charm() const {

	double q = m_r - m_b;

	return -q * std::exp(-q * m_T) * StatisticsEngine::Normal_CDF(-this->d_one()) -
		std::exp(-q * m_T) * StatisticsEngine::Normal_PDF(this->d_one()) *
		((2 * (m_r - q) * m_T - this->d_two() * m_sigma * std::sqrt(m_T)) / (2 * m_T * m_sigma * std::sqrt(m_T)));

}

double EuropeanPutOption::Vomma() const {

	return this->Vega() * ((this->d_one() * this->d_two()) / m_sigma);

}

double EuropeanPutOption::Veta() const {

	double q = m_r - m_b;

	return -m_S * std::exp(-q * m_T) * StatisticsEngine::Normal_PDF(this->d_one()) * std::sqrt(m_T)
		* (q + (((m_r - q) * this->d_one()) / (m_sigma * std::sqrt(m_T)) -
		((1 + this->d_one() * this->d_two()) / (2 * m_T))));

}

double EuropeanPutOption::Speed() const {

	return (this->Gamma() / m_S) * ((this->d_one() / (m_sigma * std::sqrt(m_T))) + 1);

}

double EuropeanPutOption::Zomma() const {

	return this->Gamma() * ((this->d_one() * this->d_two() - 1) / m_sigma);

}

double EuropeanPutOption::Color() const {

	double q = m_r - m_b;

	return -std::exp(-q * m_T) * (((StatisticsEngine::Normal_PDF(this->d_one())) / (2 * m_S * m_T * m_sigma * std::sqrt(m_T)))
		* (2 * q * m_T + 1 + ((((2 * (m_r - q) * m_T - this->d_two() * m_sigma * std::sqrt(m_T)) / (m_sigma * std::sqrt(m_T)))
				       * this->d_one()))));

}

double EuropeanPutOption::Ultima() const {

	double d_one, d_two, d_product;
	boost::tie(d_one, d_two) = this->d_pairs();
	d_product = d_one * d_two;

	return (-this->Vega() / std::pow(m_sigma, 2)) * (d_product * (1 - d_product) + std::pow(d_one, 2) + std::pow(d_two, 2));

}

double EuropeanPutOption::DualDelta() const {

	return std::exp(-m_r * m_T) * StatisticsEngine::Normal_CDF(-this->d_two());

}

double EuropeanPutOption::DualGamma() const {

	return std::exp(-m_r * m_T) * (StatisticsEngine::Normal_PDF(this->d_two()) / (m_K * m_sigma * std::sqrt(m_T)));

}
