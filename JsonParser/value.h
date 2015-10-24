/*!
 *\file value.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of json value class.
 */

#ifndef VALUE_H
#define VALUE_H

#include "object.h"
#include "array.h"
#include "valuetype.h"

namespace melihovv {
    namespace Json {

        class Array;
        class Object;

        /*!
         * Json value class.
         */
        class Value
        {
        public:
            /*!
             * Creates a Value of type type.
             */
            explicit Value(const ValueType& type = ValueType::NULL_VALUE);

            /*!
             * Creates a Value of type NUMBER, with value number.
             */
            explicit Value(long double number);

            /*!
             * Creates a Value of type BOOL, with value boolean.
             */
            explicit Value(bool boolean);

            /*!
             * Creates a Value of type STRING, with value string.
             */
            explicit Value(const std::string& string);

            /*!
             * Creates a Value of type ARRAY, with value array.
             */
            explicit Value(const Array& array);

            /*!
             * Creates a Value of type OBJECT, with value object.
             */
            explicit Value(const Object& object);

            /*!
             * Creates a copy of value.
             */
            Value(const Value& value);

            /*!
             * Destroys the value.
             */
            ~Value();

            /*!
             * Returns true if the value is null.
             */
            bool isNull() const;

            /*!
             * Returns true if the value contains a number.
             */
            bool isNumber() const;

            /*!
             * Returns true if the value contains a boolean.
             */
            bool isBoolean() const;

            /*!
             * Returns true if the value contains a string.
             */
            bool isString() const;

            /*!
             * Returns true if the value contains an array.
             */
            bool isArray() const;

            /*!
             * Returns true if the value contains an object.
             */
            bool isObject() const;

            /*!
             * Converts the value to a number and returns it.
             */
            long double number() const;

            /*!
             * Converts the value to a string and returns it.
             */
            std::string string() const;

            /*!
             * Converts the value to a boolean and returns it.
             */
            bool boolean() const;

            /*!
             * Converts the value to an array and returns it.
             */
            Array array() const;

            /*!
             * Converts the value to an object and returns it.
             */
            Object object() const;

            /*!
             * Return true if value is equal to value.
             */
            bool operator==(const Value& value) const;

            /*!
             * Assigns the value stored in value to this object.
             */
            Value& operator=(const Value& value);

        private:
            /*!
             * Creates a Value of type type, with number number,
             * with boolean boolean, with string string.
             */
            Value(
                const ValueType& type,
                long double number,
                bool boolean,
                const std::string& string
                );

            long double _number = 0;
            std::string _string = "";
            bool _boolean = false;
            Array* _array = nullptr;
            Object* _object = nullptr;
            ValueType _type = ValueType::UNDEFINED;
        };
    }
}

#endif // VALUE_H
