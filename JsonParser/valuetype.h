/*!
 *\file valuetype.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of json value type.
 */

#ifndef VALUETYPE_H
#define VALUETYPE_H

enum class ValueType
{
    BOOL,
    NUMBER,
    STRING,
    NULL_VALUE,
    OBJECT,
    ARRAY,
    UNDEFINED
};

#endif // VALUETYPE_H
