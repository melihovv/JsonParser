#include "error.h"

melihovv::Json::Error::Error(const Json::location& location,
    const std::string& message)
{
    this->location = location;
    this->message = message;
}

std::string melihovv::Json::Error::error() const
{
    std::ostringstream stream;
    stream << location << ": " << message;
    return stream.str();
}
