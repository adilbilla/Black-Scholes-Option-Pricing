#include <boost/tuple/tuple.hpp>
#include <vector>
#include <ostream>
#include <memory>

#include "NotImplementedException.h"

#ifndef BLACK_SCHOLES_PRICER
#define BLACK_SCHOLES_PRICER

// abstract base class for all Financial Instruments 
// that have pricing characteristics derived from the
// black scholes framework

class BlackScholesPricer {

protected:

	double m_S; // asset price
	double m_K; // strike price
	double m_T; // exercise (maturity) date
	double m_r; // risk-free interest rate
	double m_sigma; // constant volatility
	double m_b; // cost of carry.

public:

	BlackScholesPricer(double S, double K, double T, double r, double sigma, double b);
	BlackScholesPricer(const BlackScholesPricer& source);
	
	BlackScholesPricer();
	virtual ~BlackScholesPricer();

	BlackScholesPricer& operator=(const BlackScholesPricer& bsop);

	boost::tuple<double, double, double, double, double, double> parameter_vector() const;

	double d_one() const;
	double d_two() const;

	boost::tuple<double, double> d_pairs() const;

	virtual double price() const = 0;

	// accessor and mutator functions

	double asset_price() const { return m_S; }
	double strike_price() const { return m_K; }
	double exercise_date() const { return m_T; }
	double risk_free_interest_rate() const { return m_r; }
	double constant_volatility() const { return m_sigma; }
	double cost_of_carry() const { return m_b; }

	void asset_price(double S);
	void strike_price(double K);
	void exercise_date(double T);
	void risk_free_interest_rate(double r);
	void constant_volatility(double sigma);
	void cost_of_carry(double b);

	// modify entire object state through vector input - useful for matrix pricer
	void modify_state(const std::vector<double>& pricing_parameters);

	friend std::ostream& operator<<(std::ostream& os, const BlackScholesPricer& bsp);

	// Option Sensitivities
	virtual double FairValue() const;
	virtual double Delta()     const;
	virtual double Vega()      const;
	virtual double Theta()     const;
	virtual double Rho()       const;
	virtual double Lambda()    const;
	virtual double Gamma()     const;
	virtual double Vanna()     const;
	virtual double Charm()     const;
	virtual double Vomma()     const;
	virtual double Veta()      const;
	virtual double Speed()     const;
	virtual double Zomma()     const;
	virtual double Color()     const;
	virtual double Ultima()    const;
	virtual double DualDelta() const;
	virtual double DualGamma() const;
	

};

inline void BlackScholesPricer::asset_price(double S) { m_S = S; }

inline void BlackScholesPricer::strike_price(double K) { m_K = K; }

inline void BlackScholesPricer::exercise_date(double T) { m_T = T; }

inline void BlackScholesPricer::risk_free_interest_rate(double r) { m_r = r; }

inline void BlackScholesPricer::constant_volatility(double sigma) { m_sigma = sigma; }

inline void BlackScholesPricer::cost_of_carry(double b) { m_b = b; }

#endif // !BLACK_SCHOLES_PRICER


