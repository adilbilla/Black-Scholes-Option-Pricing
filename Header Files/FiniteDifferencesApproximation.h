#include "BlackScholesPricer.h"

#ifndef FINITE_DIFFERENCES_APPROXIMATION_H
#define FINITE_DIFFERENCES_APPROXIMATION_H


template <typename OptionType> class FiniteDifferencesApproximation {

public:

	static double Delta(BlackScholesPricer* option);
	static double Gamma(BlackScholesPricer* option);

};

#ifndef FINITE_DIFFERENCES_APPROXIMATION_CPP
#include "FiniteDifferencesApproximation.cpp"
#endif

#endif

