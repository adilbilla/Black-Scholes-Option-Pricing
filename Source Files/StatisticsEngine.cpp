#include <ctime>

#include "StatisticsEngine.h"

boost::random::mt19937 StatisticsEngine::MT_Engine{};
boost::math::normal StatisticsEngine::normal_distribution{};

template <typename E, typename D>
boost::variate_generator<E&, D> StatisticsEngine::generate(E& engine, D distribution) {
	return boost::variate_generator<E&, D>(engine, distribution);
}

boost::random::variate_generator<boost::random::mt19937&, boost::random::normal_distribution<>> StatisticsEngine::Normal_RNG() {
	boost::random::normal_distribution<> normal;
	StatisticsEngine::MT_Engine.seed(static_cast<boost::uint32_t>(std::time(0)));

	return StatisticsEngine::generate<boost::random::mt19937&, boost::random::normal_distribution<>>(StatisticsEngine::MT_Engine,
													 normal);
}

double StatisticsEngine::Normal_PDF(double x) {
	return boost::math::pdf(StatisticsEngine::normal_distribution, x);
}

double StatisticsEngine::Normal_CDF(double x) {
	return boost::math::cdf(StatisticsEngine::normal_distribution, x);
}
