#ifndef CPP_SNIPPET_SRC_CGI_H_
#define CPP_SNIPPET_SRC_CGI_H_

// #include "type_transform.h"

namespace cpp
{
class CGI
{
public:
    static std::string Encode(const std::string & sSrc);
    static std::string Decode(const std::string & sSrc);
    static std::string Convert(const std::string & sSrc, const char * from = "gbk", const char * to = "utf-8");
};
} // namespace cpp



#endif /* CPP_SNIPPET_SRC_CGI_H_ */
