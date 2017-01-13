#ifndef CPP_SNIPPET_SRC_NOCOPYABLE_H_
#define CPP_SNIPPET_SRC_NOCOPYABLE_H_
namespace cpp
{
    class nocopyable
    {
    protected:
        nocopyable() {};
        ~nocopyable() {};

    private:
        nocopyable(const nocopyable &);
        nocopyable &operator= (const nocopyable &);
    }; // class nocopyable

} // namespace cpp


#endif /* CPP_SNIPPET_SRC_NOCOPYABLE_H_ */
