#include "document.h"

melihovv::Json::Document::Document()
{
}

melihovv::Json::Document::Document(const Object& object)
    : _object(object)
    , _type(ValueType::OBJECT)
{
}

melihovv::Json::Document::Document(const Array& array)
    : _array(array)
    , _type(ValueType::ARRAY)
{
}

melihovv::Json::Document::Document(const Document& document)
    : _array(document._array)
    , _object(document._object)
    , _type(document._type)
{
}

melihovv::Json::Document::~Document()
{
}

bool melihovv::Json::Document::isObject() const
{
    return _type == ValueType::OBJECT;
}

bool melihovv::Json::Document::isArray() const
{
    return _type == ValueType::ARRAY;
}

bool melihovv::Json::Document::isNull() const
{
    return _type == ValueType::UNDEFINED;
}

bool melihovv::Json::Document::isEmpty() const
{
    return _object.isEmpty() && _array.isEmpty();
}

melihovv::Json::Array melihovv::Json::Document::array() const
{
    return _array;
}

melihovv::Json::Object melihovv::Json::Document::object() const
{
    return _object;
}

bool melihovv::Json::Document::operator==(const Document& document)
{
    return
        _type == document._type &&
        _object == document._object &&
        _array == document._array;
}

melihovv::Json::Document&
melihovv::Json::Document::operator=(const Document& document)
{
    if (this != &document)
    {
        _type = document._type;
        _array = document._array;
        _object = document._object;
    }

    return *this;
}
