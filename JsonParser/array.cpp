#include "array.h"

melihovv::Json::Array::Array()
{
}

melihovv::Json::Array::Array(const Array& array)
    : _elements(array._elements)
{
}

melihovv::Json::Array::Array(const std::vector<Value>& elements)
    : _elements(elements)
{
}

melihovv::Json::Array::~Array()
{
}

bool melihovv::Json::Array::isEmpty() const
{
    return _elements.size() == 0;
}

melihovv::Json::Value melihovv::Json::Array::operator[](int index) const
{
    return _elements.at(index);
}

bool melihovv::Json::Array::operator==(const Array& array)
{
    return _elements == array._elements;
}

melihovv::Json::Array& melihovv::Json::Array::operator=(const Array& array)
{
    if (this != &array)
    {
        _elements = array._elements;
    }

    return *this;
}
