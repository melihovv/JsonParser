#include "object.h"

melihovv::Json::Object::Object()
{
}

melihovv::Json::Object::Object(const Object& object)
    : _members(object._members)
{
}

melihovv::Json::Object::Object(const std::map<std::string, Value>& members)
    : _members(members)
{
}

melihovv::Json::Object::~Object()
{
}

melihovv::Json::Value
melihovv::Json::Object::value(const std::string& key) const
{
    return _members.at(key);
}

bool melihovv::Json::Object::isEmpty() const
{
    return _members.size() == 0;
}

bool melihovv::Json::Object::operator==(const Object& object)
{
    return _members == object._members;
}

melihovv::Json::Object& melihovv::Json::Object::operator=(const Object& object)
{
    if (this != &object)
    {
        _members = object._members;
    }

    return *this;
}
