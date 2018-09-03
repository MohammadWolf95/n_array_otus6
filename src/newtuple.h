#ifndef NEWTUPLE_H
#define NEWTUPLE_H
#include <iostream>
#include <tuple>

using namespace std;

template<typename T, typename K, size_t N, typename... REST>
struct generate_tuple_type
{
 typedef typename generate_tuple_type<T, K, N-1, T, REST...>::type type;
};

template<typename T, typename K, typename... REST>
struct generate_tuple_type<T, K, 0, REST...>
{
  typedef std::tuple<REST..., K&> type;
};

#endif // NEWTUPLE_H
