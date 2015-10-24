#include "driver.h"
#include "lexer.h"

melihovv::Json::Driver::Driver(std::istream* is /*= 0*/)
    : lexer(std::unique_ptr<Lexer>(new Lexer(is)))
    , parser(std::unique_ptr<Parser>(new Parser(*lexer.get(), *this)))
{
}

melihovv::Json::Driver::~Driver()
{
}

melihovv::Json::Document melihovv::Json::Driver::parse()
{
    errors.clear();
    parser->parse();

    if (errors.size() != 0)
    {
        for (auto error : errors)
        {
            std::cout << error.error() << std::endl;
        }
        return Document();
    }

    return document;
}

void melihovv::Json::Driver::switchInputStream(std::istream* is)
{
    lexer->switch_streams(is);
}

void melihovv::Json::Driver::setFileName(const std::string& fileName)
{
    this->fileName = fileName;
}

void melihovv::Json::Driver::addError(
    const location& location,
    const std::string& message
    )
{
    errors.push_back(Error(location, message));
}
