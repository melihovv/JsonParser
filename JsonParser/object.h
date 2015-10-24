/*!
 *\file object.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of json object class.
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <map>
#include "value.h"

namespace melihovv {
    namespace Json {

        class Value;

        /*!
         * Json object class.
         */
        class Object
        {
        public:
            /*!
             * Constructs an empty json object.
             */
            Object();

            /*!
             * Constructs json object with members members.
             */
            explicit Object(const std::map<std::string, Value>& members);

            /*!
             * Creates a copy of object.
             */
            Object(const Object& object);

            /*!
             * Destroys the object.
             */
            ~Object();

            /*!
             * Returns a Value representing the value for the key key.
             */
            Value value(const std::string& key) const throw(std::out_of_range);

            /*!
             * Returns true if object is empty.
             */
            bool isEmpty() const;

            /*!
             * Returns true if object is equal to object.
             */
            bool operator==(const Object& object);

            /*!
             * Assigns the object to object.
             */
            Object& operator=(const Object& object);

        private:
            std::map<std::string, Value> _members;
        };
    }
}

#endif // OBJECT_H
