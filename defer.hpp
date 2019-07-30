#ifndef LAK_DEFER_HPP
#define LAK_DEFER_HPP

namespace lak
{
    template <typename LAMBDA> struct defer_t
    {
        LAMBDA &_lambda;
        defer_t(LAMBDA &lambda) : _lambda(lambda) {}
        ~defer_t() { _lambda(); }
    };
}

#define LAK_DEFER_CONCAT_EX(s1, s2) s1##s2
#define LAK_DEFER_CONCAT(s1, s2) LAK_DEFER_CONCAT_EX(s1, s2)
#define LAK_DEFER_LAMBDA LAK_DEFER_CONCAT(_DEFER_LAMBDA_,__LINE__)
#define LAK_DEFER_OBJECT LAK_DEFER_CONCAT(_DEFER_OBJECT_,__LINE__)
#define DEFER(...) auto LAK_DEFER_LAMBDA = [&] __VA_ARGS__; lak::defer_t<decltype(LAK_DEFER_LAMBDA)> LAK_DEFER_OBJECT (LAK_DEFER_LAMBDA);

#endif // LAK_DEFER_HPP
