#include "BlackScholesPricer.h"
#include "StatisticsEngine.h"

#include <stdexcept>
#include <cmath>

BlackScholesPricer::BlackScholesPricer(double S, double K, double T, double r, double sigma, double b) :
	m_S(S), m_K(K), m_T(T), m_r(r), m_sigma(sigma), m_b(b) {}

BlackScholesPricer::BlackScholesPricer(const BlackScholesPricer& source) :
	m_S(source.m_S), m_K(source.m_K), m_T(source.m_T), m_r(source.m_r), m_sigma(source.m_sigma), m_b(source.m_b) {}

BlackScholesPricer::BlackScholesPricer() : m_S(0.0), m_K(0.0), m_T(0.0), m_r(0.0), m_sigma(0.0), m_b(0.0) {}
BlackScholesPricer::~BlackScholesPricer() {}

BlackScholesPricer& BlackScholesPricer::operator=(const BlackScholesPricer& bsop) {

	if (this == &bsop) return *this;

	m_S = bsop.m_S;
	m_K = bsop.m_K;
	m_T = bsop.m_T;
	m_r = bsop.m_r;
	m_sigma = bsop.m_sigma;
	m_b = bsop.m_b;

	return *this;
}

boost::tuple<double, double, double, double, double, double> BlackScholesPricer::parameter_vector() const {
	return boost::make_tuple(m_S, m_K, m_T, m_r, m_sigma, m_b);
}

double BlackScholesPricer::d_one() const {

	return (std::log(m_S / m_K) + (m_b + std::pow(m_sigma, 2) / 2) * m_T)
		/ (m_sigma * std::sqrt(m_T));

}

double BlackScholesPricer::d_two() const {

	return this->d_one() - (m_sigma * std::sqrt(m_T));

}

boost::tuple<double, double> BlackScholesPricer::d_pairs() const {
	return boost::make_tuple(this->d_one(), this->d_two());
}

void BlackScholesPricer::modify_state(const std::vector<double>& pricing_parameters) {

	if(pricing_parameters.size() != 6) throw std::logic_error("Option Pricing Vector must have exactly 6 parameters");

	m_S = pricing_parameters.at(0);
	m_K = pricing_parameters.at(1);
	m_T = pricing_parameters.at(2);
	m_r = pricing_parameters.at(3);
	m_sigma = pricing_parameters.at(4);
	m_b = pricing_parameters.at(5);

}

// output operator

std::ostream& operator<<(std::ostream& os, const BlackScholesPricer& bsp) {

	os << "Asset Price: " << bsp.m_S << "\nStrike Price: "
		<< bsp.m_K << "\nExercise Date: " << bsp.m_T
		<< "\nRisk-Free-Interest-Rate: " << bsp.m_r
		<< "\nConstant Volatility: " << bsp.m_sigma
		<< "\nCost Of Carry: " << bsp.m_b;

	return os;
}



// Option Sensitivities

double BlackScholesPricer::FairValue() const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Delta()     const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Vega()      const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Theta()     const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Rho()       const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Lambda()    const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Gamma()     const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Vanna()     const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Charm()     const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Vomma()     const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Veta()      const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Speed()     const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Zomma()     const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Color()     const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::Ultima()    const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::DualDelta() const { throw NotImplementedException(__FUNCTION__); }
double BlackScholesPricer::DualGamma() const { throw NotImplementedException(__FUNCTION__); }
