#include "NotImplementedException.h"

NotImplementedException::NotImplementedException(const std::string& function) : std::logic_error("NotImplementedException: " + function) {}
NotImplementedException::~NotImplementedException() {}

const char* NotImplementedException::what() const {

	return std::logic_error::what();

}