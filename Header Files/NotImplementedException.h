#include <stdexcept>

#ifndef NOT_IMPLEMENTED_EXCEPTION_H
#define NOT_IMPLEMENTED_EXCEPTION_H

class NotImplementedException : public std::logic_error {

public:

	NotImplementedException(const std::string& function);
	~NotImplementedException();

	virtual const char* what() const;

};

#endif

