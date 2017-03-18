#include <iostream>
#include "CGI.h"

namespace cpp
{
    using std::string;
    std::string CGI::Encode(const std::string &sSrc)
    {
        std::string result;
        std::string::const_iterator pos;

        for(pos = sSrc.begin(); pos != sSrc.end(); ++pos) {
            if ( (*pos >= '0' && *pos <= '9') ||
                    (*pos >= 'A' && *pos <= 'Z') ||
                    (*pos >= 'a' && *pos <= 'z')) {
                result.append(1, *pos);
            } else {
                result.append("%" + TypeTransform::CharToHex(*pos));
            }
        }

        return result;
    }

    std::string CGI::Decode(const std::string &sSrc)
    {
        std::string result;
        std::string::const_iterator pos;

        for(pos = sSrc.begin(); pos != sSrc.end(); ++pos) {
            if ( *pos == '%' && std::distance(pos, sSrc.end()) > 2 ) {
                if ( std::tolower(*(pos + 1)) == 'u' &&
                        std::distance(pos, sSrc.end()) > 5 &&
                        std::isxdigit(*(pos + 2)) &&
                        std::isxdigit(*(pos + 3)) &&
                        std::isxdigit(*(pos + 4)) &&
                        std::isxdigit(*(pos + 5))) {
                    // string like %uABCD
                    pos = pos + 2;

                    unsigned short UnicodeWord;
                    UnicodeWord = TypeTransform::HexToChar(string(pos, pos + 2));
                    UnicodeWord = static_cast<unsigned short>(UnicodeWord << 8);
                    UnicodeWord = static_cast<unsigned short>(UnicodeWord
                            + TypeTransform::HexToChar(string(pos + 2, pos + 4)));
                    //result.append(ChrsetTools::USC2GB(string((char *)&UnicodeWord, 2)));

                    pos = pos + 3;
                } else if ( std::distance(pos, sSrc.end()) > 2 &&
                            std::isxdigit(*(pos + 1)) &&
                            std::isxdigit(*(pos + 2)) ) {
                    // string like %AB
                    ++pos;
                    result.append(1, TypeTransform::HexToChar(string(pos, pos + 2)));
                    ++pos;
                } else {
                    result.append(1, '%');
                }
            } else {
                result.append(1, *pos);
            }
        }

        return result;
    }



    /*string CGI::Convert(const string & sSrt, const char * from, const char * to)
    {
        char        *sin, *sout;
        size_t      lenin, lenout, ret;
        char        bufout[1024] = {0};
        iconv_t     c_pt;

        if ((c_pt = iconv_open(to, from)) == (iconv_t)-1)
        {
            return "";
        }

        lenin  = sSrt.length();
        lenout = sizeof(bufout);
        sin    = (char *)sSrt.c_str();
        sout   = bufout;
        ret = iconv(c_pt, &sin, &lenin, &sout, &lenout);
        iconv_close(c_pt);

        if (ret == (size_t)-1)
        {
            return "";
        }

        string s;
        s.assign(bufout, sizeof(bufout) - lenout);
        return s;
    }*/
}



