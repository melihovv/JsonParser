#include <gtest\gtest.h>
#include <sstream>
#include "../JsonParser/driver.h"

TEST(JsonParser, Object)
{
    std::istringstream iss(R"(
{
    "key1": {
        "key": "value"
    },
    "key2": {},
    "key3": [
        42,
        [true, null],
        {"key": "value"}
    ]
}
)");
    melihovv::Json::Driver driver(&iss);
    melihovv::Json::Document doc = driver.parse();

    ASSERT_TRUE(doc.isObject());
    ASSERT_FALSE(doc.isArray());
    ASSERT_EQ(
        "value",
        doc.object().value("key1").object().value("key").string()
        );
    ASSERT_TRUE(doc.object().value("key2").object().isEmpty());
    ASSERT_EQ(42, doc.object().value("key3").array()[0].number());
    ASSERT_EQ(true, doc.object().value("key3").array()[1].array()[0].boolean());
    ASSERT_TRUE(true, doc.object().value("key3").array()[1].array()[0].isNull());
    ASSERT_EQ(
        "value",
        doc.object().value("key3").array()[2].object().value("key").string()
        );
}

TEST(JsonParser, Array)
{
    std::istringstream iss(R"(
[
    {
        "key": "value",
        "key": "value2"
    },
    {
        "key2": 2
    }
]
)");
    melihovv::Json::Driver driver(&iss);
    melihovv::Json::Document doc = driver.parse();

    ASSERT_FALSE(doc.isObject());
    ASSERT_TRUE(doc.isArray());
    ASSERT_EQ("value", doc.array()[0].object().value("key").string());
    ASSERT_EQ(2, doc.array()[1].object().value("key2").number());
}
