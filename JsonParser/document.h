/*!
 *\file document.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of json document class.
 */

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "array.h"
#include "object.h"
#include "valuetype.h"

namespace melihovv {
    namespace Json {

        /*!
         * Json document class.
         */
        class Document
        {
        public:
            /*!
             * Creates an empty Document.
             */
            Document();

            /*!
             * Creates Document from object.
             */
            explicit Document(const Object& object);

            /*!
             * Creates Document from array.
             */
            explicit Document(const Array& array);

            /*!
             * Creates copy of document.
             */
            Document(const Document& document);

            /*!
             * Destroys the document.
             */
            ~Document();

            /*!
             * Return true if document contains an object.
             */
            bool isObject() const;

            /*!
             * Return true if document contains an array.
             */
            bool isArray() const;

            /*!
             * Returns true if document is null.
             */
            bool isNull() const;

            /*!
             * Returns true if document doesn't contain any data.
             */
            bool isEmpty() const;

            /*!
             * Returns Array contained in the document.
             */
            Array array() const;

            /*!
             * Returns Object contained in the document.
             */
            Object object() const;

            /*!
             * Returns true if document is equal to document.
             */
            bool operator==(const Document& document);

            /*!
             * Assigns the document to this document.
             */
            Document& operator=(const Document& document);

        private:
            ValueType _type = ValueType::UNDEFINED;
            Object _object;
            Array _array;
        };
    }
}

#endif // DOCUMENT_H
