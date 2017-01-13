#ifndef CPP_SNIPPET_SRC_REVERSEGUARD_H_
#define CPP_SNIPPET_SRC_REVERSEGUARD_H_
#include "nocopyable.h"

namespace cpp
{
    template<typename T>
    class ReverseGuard : private nocopyable
    {
    public:
        ReverseGuard(T *ptr) : m_pStorge(ptr) {};
        ~ReverseGuard()
        {
            *m_pStorge = !(*m_pStorge);
        };
    private:
        T *m_pStorge;
    }; // class ReverseGuard : private nocopyable
}

#endif /* CPP_SNIPPET_SRC_REVERSEGUARD_H_ */
