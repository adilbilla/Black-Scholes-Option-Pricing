#include "BlackScholesPricer.h"

#ifndef PERPETUAL_AMERICAN_PUT_OPTION_H
#define PERPETUAL_AMERICAN_PUT_OPTION_H

class PerpetualAmericanPutOption : public BlackScholesPricer {

public:

	PerpetualAmericanPutOption();
	virtual ~PerpetualAmericanPutOption();

	PerpetualAmericanPutOption(double S, double K, double r, double sigma, double b);
	PerpetualAmericanPutOption(const PerpetualAmericanPutOption& american_option);

	PerpetualAmericanPutOption& operator=(const PerpetualAmericanPutOption& rhs);

	virtual double price() const override;

};

#endif

