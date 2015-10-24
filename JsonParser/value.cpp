#include "value.h"

melihovv::Json::Value::Value(const ValueType& type /*= ValueType::NULL_VALUE*/)
    : Value(type, 0, false, "")
{
}

melihovv::Json::Value::Value(long double number)
    : Value(ValueType::NUMBER, number, false, "")
{
}

melihovv::Json::Value::Value(bool boolean)
    : Value(ValueType::BOOL, 0, boolean, "")
{
}

melihovv::Json::Value::Value(const std::string& string)
    : Value(ValueType::STRING, 0, false, string)
{
}

melihovv::Json::Value::Value(const Array& array)
    : Value(ValueType::ARRAY, 0, false, "")
{
    *this->_array = array;
}

melihovv::Json::Value::Value(const Object& object)
    : Value(ValueType::OBJECT, 0, false, "")
{
    *this->_object = object;
}

melihovv::Json::Value::Value(const Value& value)
    : Value(value._type, value._number, value._boolean, value._string)
{
    delete _array;
    _array = new Array(*value._array);
    delete _object;
    _object = new Object(*value._object);
}

melihovv::Json::Value::Value(
    const ValueType& type,
    long double number,
    bool boolean,
    const std::string& string
    )
{
    _array = new Array();
    _object = new Object();
    _type = type;
    _number = number;
    _boolean = boolean;
    _string = string;
}

melihovv::Json::Value::~Value()
{
    delete _array;
    delete _object;
}

bool melihovv::Json::Value::isNull() const
{
    return _type == ValueType::NULL_VALUE;
}

bool melihovv::Json::Value::isNumber() const
{
    return _type == ValueType::NUMBER;
}

bool melihovv::Json::Value::isBoolean() const
{
    return _type == ValueType::BOOL;
}

bool melihovv::Json::Value::isString() const
{
    return _type == ValueType::STRING;
}

bool melihovv::Json::Value::isArray() const
{
    return _type == ValueType::ARRAY;
}

bool melihovv::Json::Value::isObject() const
{
    return _type == ValueType::OBJECT;
}

long double melihovv::Json::Value::number() const
{
    return _number;
}

std::string melihovv::Json::Value::string() const
{
    return _string;
}

bool melihovv::Json::Value::boolean() const
{
    return _boolean;
}

melihovv::Json::Array melihovv::Json::Value::array() const
{
    return *_array;
}

melihovv::Json::Object melihovv::Json::Value::object() const
{
    return *_object;
}

bool melihovv::Json::Value::operator==(const Value& value) const
{
    return
        _number == value._number &&
        _string == value._string &&
        _type == value._type &&
        *_object == *value._object &&
        *_array == *value._array;
}

melihovv::Json::Value& melihovv::Json::Value::operator=(const Value& value)
{
    if (this != &value)
    {
        _number = value._number;
        _string = value._string;
        _boolean = value._boolean;
        _type = value._type;

        delete _array;
        _array = new Array(*value._array);
        delete _object;
        _object = new Object(*value._object);
    }

    return *this;
}
