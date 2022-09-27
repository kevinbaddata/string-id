// MathLibrary.h
#pragma once
#include <iostream>

constexpr const unsigned long long StringIdHashConcat(unsigned long long base, const char* str)
{
    return (*str) ? (StringIdHashConcat((base ^ *str) * 0x100000001b3, str + 1)) : base;
}

constexpr const unsigned long long StringIdHash(const char* str)
{
    return StringIdHashConcat(0xcbf29ce484222325, str);
}

class StringID
{
public:
	const char* str;
    constexpr const unsigned long long GetValue() const 
	{
		return StringIdHash(str);
	}
};


#define SID_VAL(str) (StringIdHash(str))
