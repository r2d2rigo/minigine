#include "InvalidOperationException.hpp"

namespace Minigine
{
	InvalidOperationException::InvalidOperationException(const string& errorMessage)
	{
		this->message = errorMessage;
	}

	const char* InvalidOperationException::what() const throw()
	{
		return this->message.c_str();
	}
}