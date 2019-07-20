#include "BlackScholesPricer.h"

#ifndef EUROPEAN_CALL_OPTION_H
#define EUROPEAN_CALL_OPTION_H

class EuropeanCallOption : public BlackScholesPricer {
	
public:

	EuropeanCallOption(double S, double K, double T, double r, double sigma, double b);
	EuropeanCallOption(const EuropeanCallOption& source);
	
	EuropeanCallOption();
	virtual ~EuropeanCallOption();

	EuropeanCallOption& operator=(const EuropeanCallOption& eco);

	virtual double price() const override;

	// Option Sensitivities
	virtual double FairValue() const override;
	virtual double Delta()     const override;
	virtual double Vega()      const override;
	virtual double Theta()     const override;
	virtual double Rho()       const override;
	virtual double Lambda()    const override;
	virtual double Gamma()     const override;
	virtual double Vanna()     const override;
	virtual double Charm()     const override;
	virtual double Vomma()     const override;
	virtual double Veta()      const override;
	virtual double Speed()     const override;
	virtual double Zomma()     const override;
	virtual double Color()     const override;
	virtual double Ultima()    const override;
	virtual double DualDelta() const override;
	virtual double DualGamma() const override;

};

#endif // !EUROPEAN_CALL_OPTION_H


