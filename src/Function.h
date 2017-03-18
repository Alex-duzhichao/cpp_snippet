#ifndef CPP_SNIPPET_SRC_FUNCTION_H_
#define CPP_SNIPPET_SRC_FUNCTION_H_

template<typename T>
inline bool isPower(const T& value)
{
    return !(value & (value - 1));
}

template<typename T>
inline T getNextPower(const T& value)
{
    if(isPower(value)) return value;
    // return ((value / 2) + 1) * 2;
}

#endif /* CPP_SNIPPET_SRC_FUNCTION_H_ */
