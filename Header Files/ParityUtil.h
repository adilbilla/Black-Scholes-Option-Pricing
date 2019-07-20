#include "EuropeanCallOption.h"
#include "EuropeanPutOption.h"

#ifndef PARITY_UTIL_H
#define PARITY_UTIL_H

struct ParityUtil {

	static bool PutCallParityCheck(const EuropeanCallOption& eco, const EuropeanPutOption& epo);
	static double compute_call_price(const EuropeanPutOption& epo);
	static double compute_put_price(const EuropeanCallOption& eco);

};

#endif

