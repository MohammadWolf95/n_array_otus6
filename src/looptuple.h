#ifndef LOOPTUPLE_H
#define LOOPTUPLE_H

#include <cstddef>
#include <tuple>
#include <utility>

using namespace std;

template <typename Tuple, typename F, std::size_t ...Indices>
static void for_each_impl(Tuple&&tuple, F&&f, index_sequence<Indices...>){
    using swallow = int[];
    (void)swallow{1,
                  (f(get<Indices>(forward<Tuple>(tuple))), void(), int{})...
                 };
}

template<typename Tuple, typename F>
static void for_each(Tuple&&tuple, F&&f){
    constexpr size_t N = tuple_size<remove_reference_t<Tuple>>::value;
    for_each_impl(forward<Tuple>(tuple), forward<F>(f), make_index_sequence<N>{});
}

#endif // LOOPTUPLE_H
