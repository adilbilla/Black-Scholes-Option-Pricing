#include "BlackScholesPricer.h"

#ifndef EUROPEAN_PUT_OPTION_H
#define EUROPEAN_PUT_OPTION_H

class EuropeanPutOption : public BlackScholesPricer {

public:

	EuropeanPutOption(double S, double K, double T, double r, double sigma, double b);
	EuropeanPutOption(const EuropeanPutOption& source);

	EuropeanPutOption();
	virtual ~EuropeanPutOption();

	EuropeanPutOption& operator=(const EuropeanPutOption& epo);

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

#endif // !EUROPEAN_PUT_OPTION_H
