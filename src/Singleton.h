/**
 * @File : Singleton.h
 * @Brief : Singleton template
 * @Author : Name:AlexDu Email:duzhichaomail@gmail.com
 * @Version : 1.0.0
 * @Date : 2017-01-01
 */
#ifndef CPP_SNIPPET_SRC_SINGLETON_H_
#define CPP_SNIPPET_SRC_SINGLETON_H_

#include <iostream>
#include <cstddef>
#include "nocopyable.h"

using namespace std;
namespace cpp
{
    template<typename T>
    class NewPolicy : private nocopyable
    {
    public:
        static T *getInstance();
        static void setInstance(const T *pT);
        static void destroyInstance();

    private:
        static T *m_pInstance;
    }; // class NewPolicy

    template<typename T>
    T *NewPolicy<T>::m_pInstance = NULL;

    template<typename T>
    T *NewPolicy<T>::getInstance()
    {
        if(!m_pInstance) {
            m_pInstance = new T;
        }

        return m_pInstance;
    }

    template<typename T>
    void NewPolicy<T>::setInstance(const T *pT)
    {
        assert(m_pInstance == nullptr);
        m_pInstance = const_cast<T *>(pT);
    }

    template<typename T>
    void NewPolicy<T>::destroyInstance()
    {
        if(m_pInstance) {
            delete m_pInstance;
            m_pInstance = nullptr;
        }
    }

    template<typename T>
    class NewAndDeletePolicy : public NewPolicy<T>
    {
    public:
        static T *getInstance();
    private:
        class GarbageCollectHelper : private nocopyable
        {
        public:
            ~GarbageCollectHelper()
            {
                NewPolicy<T>::destroyInstance();
            }
        }; // class GarbageCollectHelper : private nocopyable
    }; // class NewAndDeletePolicy : public NewPolicy<T>

    template<typename T>
    T *NewAndDeletePolicy<T>::getInstance()
    {
        typename NewAndDeletePolicy<T>::GarbageCollectHelper staticGc;
        return NewPolicy<T>::getInstance();
    }

    template<typename T>
    class StaticPolicy : private nocopyable
    {
    public:
        static T *getInstance();
    }; // class StaticPolicy : private nocopyable

    template<typename T>
    T *StaticPolicy<T>::getInstance()
    {
        static T staticInstance;
        return &staticInstance;
    }

    template<typename T,
             template<typename> class Policy = NewPolicy>
    class Singleton : private nocopyable
    {
    public:
        static T *getInstance();
        static void setInstance(const T *ptr);
        static void destroyInstance();

    }; // class Singleton

    template<typename T, template<typename> class Policy>
    T *Singleton<T, Policy>::getInstance()
    {
        return Policy<T>::getInstance();
    }

    template<typename T, template<typename> class Policy>
    void Singleton<T, Policy>::setInstance(const T *ptr)
    {
        Policy<T>::setInstance(ptr);
    }

    template<typename T, template<typename> class Policy>
    void Singleton<T, Policy>::destroyInstance()
    {
        Policy<T>::destroyInstance();
    }

} // namespace cpp

#endif /* CPP_SNIPPET_SRC_SINGLETON_H_ */
