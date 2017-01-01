/**
 * @File : Singleton.h
 * @Brief : Singleton template
 * @Author : Name:AlexDu Email:duzhichaomail@gmail.com
 * @Version : 1.0.0
 * @Date : 2017-01-01
 */
#ifndef CPP_SNIPPET_SRC_SINGLETON_H_
#define CPP_SNIPPET_SRC_SINGLETON_H_

#include "nocopyable.h"

namespace cpp
{
    template<typename T>
    class Singleton : private nocopyable
    {
        private:
            static T* m_pInstance;
        public:
            static T* getInstance();
            static void setInstance(const T* ptr);
            static void destroyInstance();

    }; // class Singleton

    template<typename T>
    T* Singleton<T>::m_pInstance = NULL;

    template<typename T>
    T* Singleton<T>::getInstance()
    {
        if(m_pInstance == NULL){
            m_pInstance = new T;
        }
        return m_pInstance;
    }

    template<typename T>
    void Singleton<T>::setInstance(const T* ptr)
    {
        m_pInstance = const_cast<T*>(ptr);
    }

    template<typename T>
    void Singleton<T>::destroyInstance()
    {
        if(m_pInstance != NULL){
            delete m_pInstance;
            m_pInstance = NULL;
        }
    }

} // namespace cpp

#endif /* CPP_SNIPPET_SRC_SINGLETON_H_ */
