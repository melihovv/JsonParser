/*!
 *\file driver.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of driver class.
 */

#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <list>
#include <memory>
#include "error.h"
#include "location.hh"
#include "parser.tab.hh"
#include "document.h"

namespace melihovv {
    namespace Json {

        /*!
         * Driver class.
         */
        class Driver
        {
        public:
            Driver(std::istream* is = 0);
            ~Driver();

            /*!
             * Parse json.
             *\return Json document.
             */
            Document parse();

            /*!
             * Switch lexer input stream. Default is standard input
             * (std::cin).
             *\param[in] is Input stream.
             */
            void switchInputStream(std::istream* is);

            /*!
             * Set name of parsing file.
             *\param[in] fileName Name of parsing file.
             */
            void setFileName(const std::string& fileName);

            friend class Parser;
            friend class Lexer;

        private:
            /*!
             * Add error in list of errors.
             *\param[in] location Location of error.
             *\param[in] message Error message.
             */
            void addError(
                const location& location,
                const std::string& message
                );

            std::string fileName = "";
            std::list<Error> errors;
            std::unique_ptr<Lexer> lexer;
            std::unique_ptr<Parser> parser;
            Document document;
        };
    }
}

#endif // DRIVER_H
