#include "stringToNumber.h"

double stringToNumber(string text)
{
    double Result;

    istringstream convert(text);

    if ( !(convert >> Result) )
        Result = 0;
    return Result;
}
