#include "BlackScholesPricer.h"

#ifndef PERPETUAL_AMERICAN_CALL_OPTION
#define PERPETUAL_AMERICAN_CALL_OPTION


class PerpetualAmericanCallOption : public BlackScholesPricer {

public:

	PerpetualAmericanCallOption();
	virtual ~PerpetualAmericanCallOption();

	PerpetualAmericanCallOption(double S, double K, double r, double sigma, double b);
	PerpetualAmericanCallOption(const PerpetualAmericanCallOption& american_option);

	PerpetualAmericanCallOption& operator=(const PerpetualAmericanCallOption& rhs);

	virtual double price() const override;

};


#endif

