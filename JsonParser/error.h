/*!
 *\file error.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of error class.
 */

#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <sstream>
#include "location.hh"

namespace melihovv {
    namespace Json {

        /*!
         * Error class.
         */
        class Error
        {
        public:
            Error(const Json::location& location,
                const std::string& message);

            /*
            * Return error message.
            */
            std::string error() const;

        private:
            Json::location location;
            std::string message;
        };
    }
}

#endif
