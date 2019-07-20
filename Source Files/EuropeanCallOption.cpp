#include "EuropeanCallOption.h"
#include "StatisticsEngine.h"
#include <cmath>

EuropeanCallOption::EuropeanCallOption(double S, double K, double T, double r, double sigma, double b) :
	BlackScholesPricer(S, K, T, r, sigma, b) {}

EuropeanCallOption::EuropeanCallOption(const EuropeanCallOption& source) : BlackScholesPricer(source) {}

EuropeanCallOption::EuropeanCallOption() {}
EuropeanCallOption::~EuropeanCallOption() {}

EuropeanCallOption& EuropeanCallOption::operator=(const EuropeanCallOption& eco) {
	if (this == &eco) return *this;

	BlackScholesPricer::operator=(eco);

	return *this;
}

double EuropeanCallOption::price() const {

	double S, K, T, r, sigma, b, d_one, d_two;

	boost::tie(S, K, T, r, sigma, b) = this->parameter_vector();
	boost::tie(d_one, d_two) = this->d_pairs();

	return (S * std::exp((b - r) * T) * StatisticsEngine::Normal_CDF(d_one)) -
		(K * std::exp(-r * T) * StatisticsEngine::Normal_CDF(d_two));

}

// Option Sensitivities

double EuropeanCallOption::FairValue() const {

	double q = m_r - m_b;

	return m_S * std::exp(-q * m_T) * StatisticsEngine::Normal_CDF(this->d_one())
		- std::exp(-m_r * m_T) * m_K * StatisticsEngine::Normal_CDF(this->d_two());

}

double EuropeanCallOption::Delta() const {

	double q = m_r - m_b;
	
	return std::exp(-q * m_T) * StatisticsEngine::Normal_CDF(this->d_one());
}

double EuropeanCallOption::Vega() const {

	double q = m_r - m_b;

	return m_S * std::exp(-q * m_T) * StatisticsEngine::Normal_PDF(this->d_one()) * std::sqrt(m_T);

}

double EuropeanCallOption::Theta() const {

	double q = m_r - m_b;

	return -std::exp(-q * m_T) * ((m_S * StatisticsEngine::Normal_PDF(this->d_one()) * m_sigma) / (2 * std::sqrt(m_T)))
		- m_r * m_K * std::exp(-m_r * m_T) * StatisticsEngine::Normal_CDF(this->d_two())
		+ q * m_S * std::exp(-q * m_T) * StatisticsEngine::Normal_CDF(this->d_one());

}

double EuropeanCallOption::Rho() const {

	double q = m_r - m_b;

	return m_K * m_T * std::exp(-m_r * m_T) * StatisticsEngine::Normal_CDF(this->d_two());

}

double EuropeanCallOption::Lambda() const {

	return (this->Delta()) * (m_S / this->FairValue());

}

double EuropeanCallOption::Gamma() const {

	double q = m_r - m_b;

	return std::exp(-q * m_T) * (StatisticsEngine::Normal_PDF(this->d_one()) / (m_S * m_sigma * std::sqrt(m_T)));

}

double EuropeanCallOption::Vanna() const {

	return (this->Vega() / m_S) * (1 - (this->d_one() / (m_sigma * std::sqrt(m_T))));

}

double EuropeanCallOption::Charm() const {

	double q = m_r - m_b;

	return q * std::exp(-q * m_T) * StatisticsEngine::Normal_CDF(this->d_one()) -
		std::exp(-q * m_T) * StatisticsEngine::Normal_PDF(this->d_one()) *
		((2 * (m_r - q) * m_T - this->d_two() * m_sigma * std::sqrt(m_T)) / (2 * m_T * m_sigma * std::sqrt(m_T)));

}


double EuropeanCallOption::Vomma() const {

	return this->Vega() * ((this->d_one() * this->d_two()) / m_sigma);

}

double EuropeanCallOption::Veta() const {

	double q = m_r - m_b;

	return -m_S * std::exp(-q * m_T) * StatisticsEngine::Normal_PDF(this->d_one()) * std::sqrt(m_T)
		* (q + (((m_r - q) * this->d_one()) / (m_sigma * std::sqrt(m_T) ) -
		( (1 + this->d_one() * this->d_two()) / (2 * m_T))));

}

double EuropeanCallOption::Speed() const {

	return (this->Gamma() / m_S) * ((this->d_one() / (m_sigma * std::sqrt(m_T))) + 1);

}

double EuropeanCallOption::Zomma() const {

	return this->Gamma() * ((this->d_one() * this->d_two() - 1) / m_sigma);

}

double EuropeanCallOption::Color() const {

	double q = m_r - m_b;
	
	return -std::exp(-q * m_T) * (((StatisticsEngine::Normal_PDF(this->d_one())) / (2 * m_S * m_T * m_sigma * std::sqrt(m_T)))
		* (2 * q * m_T + 1 + ((((2 * (m_r - q) * m_T - this->d_two() * m_sigma * std::sqrt(m_T)) / (m_sigma * std::sqrt(m_T)))
				       * this->d_one()))));

}

double EuropeanCallOption::Ultima() const {

	double d_one, d_two, d_product;
	boost::tie(d_one, d_two) = this->d_pairs();
	d_product = d_one * d_two;

	return (-this->Vega() / std::pow(m_sigma, 2)) * (d_product * (1 - d_product) + std::pow(d_one, 2) + std::pow(d_two, 2));

}

double EuropeanCallOption::DualDelta() const {

	return -std::exp(-m_r * m_T) * StatisticsEngine::Normal_CDF(this->d_two());

}

double EuropeanCallOption::DualGamma() const {

	return std::exp(-m_r * m_T) * (StatisticsEngine::Normal_PDF(this->d_two()) / (m_K * m_sigma * std::sqrt(m_T)));

}
