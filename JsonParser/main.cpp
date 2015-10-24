#include <vld.h>
#include <sstream>
#include "driver.h"

int main(int argc, char* argv[])
{
    std::istringstream iss(R"(
{
    "key": {
        "key2": "value"
    },
    "key3": 1
}
)");
    melihovv::Json::Driver driver(&iss);
    melihovv::Json::Document doc = driver.parse();

    std::cout << doc
        .object().value("key")
        .object().value("key2").string()
        << std::endl;

    return 0;
}
