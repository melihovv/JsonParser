/*!
 *\file array.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of json array class.
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include "value.h"

namespace melihovv {
    namespace Json {

        class Value;

        /*!
         * Json array class.
         */
        class Array
        {
        public:
            /*!
             * Creates an empty json array.
             */
            Array();

            /*!
             * Creates json array with elements elements.
             */
            explicit Array(const std::vector<Value>& elements);

            /*!
             * Creates a copy of array.
             */
            Array(const Array& array);

            /*!
             * Destroys the array.
             */
            ~Array();

            /*!
             * Returns true if array is empty.
             */
            bool isEmpty() const;

            /*!
             * Returns the Value at index position index.
             */
            Value operator[](int index) const throw(std::out_of_range);

            /*!
             * Returns true if array is equal to array.
             */
            bool operator==(const Array& array);

            /*!
             * Assigns the array to array.
             */
            Array& operator=(const Array& array);

        private:
            std::vector<Value> _elements;
        };
    }
}

#endif // ARRAY_H
