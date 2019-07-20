#include <boost/random/variate_generator.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/math/distributions.hpp>

#ifndef STATISTICS_ENGINE_H
#define STATISTICS_ENGINE_H

class StatisticsEngine {

private:

	static boost::random::mt19937 MT_Engine;
	static boost::math::normal normal_distribution;

	template <typename E, typename D>
	static boost::random::variate_generator<E&, D> generate(E& engine, D distribution);

public:

	static boost::random::variate_generator<boost::random::mt19937&, boost::random::normal_distribution<>> Normal_RNG();
	static double Normal_PDF(double x);
	static double Normal_CDF(double x);
};

#endif // !STATISTICS_ENGINE_H


