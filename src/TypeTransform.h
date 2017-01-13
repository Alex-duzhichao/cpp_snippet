#ifndef CPP_SNIPPET_SRC_TYPE_TRANSFORM_H_
#define CPP_SNIPPET_SRC_TYPE_TRANSFORM_H_

#include <stdlib.h>
#include <sstream>
#include <algorithm>

namespace cpp
{
    /*! \class TypeTransform
     *  \brief 类型转换工具类
     */
    class TypeTransform
    {
    public:
        static int StringToInt(const std::string &sSour)
        {
            return(atoi(sSour.c_str()));
        }

        static std::string IntToString(int nSour)
        {
            std::stringstream sTemp;
            sTemp << nSour ;
            return sTemp.str();
        }

        static long StringToLong(const std::string &sSour)
        {
            return atol(sSour.c_str());
        }

        static std::string LongToString(long nSour)
        {
            std::stringstream sTemp;
            sTemp << nSour ;
            return sTemp.str();
        }

        static long StringToLongLong(const std::string &sSour)
        {
            return atoll(sSour.c_str());
        }

        static std::string LongLongToString(long long nSour)
        {
            std::stringstream sTemp;
            sTemp << nSour ;
            return sTemp.str();
        }

        static float StringToFloat(const std::string &sSour)
        {
            return static_cast<float>(atof(sSour.c_str()));
        }

        static std::string FloatToString(float nSour)
        {
            std::stringstream sTemp;
            sTemp << nSour ;
            return sTemp.str();
        }

        static double StringToDouble(const std::string &sSour)
        {
            return(atof(sSour.c_str()));
        }

        static std::string DoubleToString(double nSour)
        {
            std::stringstream sTemp;
            sTemp << nSour ;
            return sTemp.str();
        }

        static std::string CharToHex(char c)
        {
            std::string sValue;
            static char MAPX[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
            sValue += MAPX[(c >> 4) & 0x0F];
            sValue += MAPX[c & 0x0F];
            return sValue;

        }

        static char HexToChar(const std::string &sHex)
        {
            unsigned char c = 0;

            for ( unsigned int i = 0;
                    i < std::min<unsigned int>(static_cast<unsigned int>(sHex.size()),
                        static_cast<unsigned int>(2));
                    ++i ) {
                // unsigned char c1 = static_cast<unsigned char>(std::toupper(sHex[i]));
                // unsigned char c2 = (c1 >= 'A') ? (c1 - ('A' - 10)) : (c1 - '0');
                // (c <<= 4) += c2;
            }

            return c;
        }

    };
} // namespace cpp

#endif /* CPP_SNIPPET_SRC_TYPE_TRANSFORM_H_ */
