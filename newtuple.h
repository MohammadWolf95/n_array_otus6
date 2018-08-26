#ifndef NEWTUPLE_H
#define NEWTUPLE_H
#include <iostream>
#include <tuple>

using namespace std;

template<size_t number, typename T=int,typename...Args>
class NewTuple;

template<typename T, typename...Args>
class NewTuple<0, T, Args...>{
public:
    operator tuple<Args..., T>(){
        tuple<Args..., T>tup;
        get<0>(tup)=0;
        //get<1>(tup)=1;
        //get<2>(tup)=2;
        //get<3>(tup)=3;
        return tup;
    }
};

template<size_t number, typename T, typename...Args>
class NewTuple{
public:
    using InsideTuple = NewTuple<number - 1, T, Args..., size_t>;
    InsideTuple obj;
    operator auto(){
        return obj;
    }
};

#endif // NEWTUPLE_H
