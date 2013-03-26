#pragma once

#include <exception>
#include <string>

using std::exception;
using std::string;

namespace Minigine
{
	class InvalidOperationException : public exception
	{
	private:
		string message;

	public:
		InvalidOperationException(const string& errorMessage);
		virtual const char* what() const throw();
	};
}