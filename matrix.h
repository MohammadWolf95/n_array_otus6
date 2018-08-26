#ifndef MATRIX_H
#define MATRIX_H

#include <tuple>
#include <iterator>
#include <iostream>
#include <map>
#include <vector>
#include <printtuple.h>
#include <looptuple.h>
#include <memory>

using namespace std;

template <size_t Depth, int defaultvalue, typename T=int, typename ...Args>
class SubSpace;

template <int defaultvalue, typename T, typename...Args>
class SubSpace<0, defaultvalue, T, Args...> {
public:
    using Nested = SubSpace<0, defaultvalue, T, Args...>;
    SubSpace():
    value(-1), firstInit(false){}
    std::map<int, Nested> m;
    tuple<size_t,Args...>tup;
    Nested& operator[] (size_t i) {
        if(m.find(i)==m.end()){
            Nested newElement(sizeMatrix.get());
            m.insert(make_pair(i, newElement));
            get<sizeof...(Args)>(tup)=i;
            vector<int>vec;
            for_each(tup, [&vec](auto x){
                vec.emplace_back(x);
            });
            tuple_print::print(tup);
        }
        return m.find(i)->second;
    }

    void operator=(const T&other){
        if(!firstInit){
            firstInit=true;
            ++(*sizeMatrix);
        }
        value = other;
    }

    Nested const& operator[] (size_t i) const {
        return m.find(i)->second;
    }

    int const&getValue() const{
        return value;
    }

private:
    T value;
    //vector<int>vec;
    bool firstInit;
    shared_ptr<int>sizeMatrix;

    template<size_t Depth1, int defaultvalue1, typename U, typename ...Args1>
    friend class SubSpace;

    SubSpace(int*ptr):
        value(-1), firstInit(false){
        sizeMatrix.reset(ptr);
    }
};

template <size_t Depth, int defaultvalue, typename T, typename ...Args>
class SubSpace{
public:
    using Nested = SubSpace<Depth-1, defaultvalue, T, Args..., size_t>;
    std::map<int, Nested> m;
    tuple<size_t, Args...>tup;
    SubSpace();

    //vector<SubSpace<>>tupleLastInd;

    Nested& operator[] (size_t i) {
        if(m.find(i)==m.end()){
            Nested newElement(sizeMatrix.get());
            get<sizeof...(Args)>(tup)=i;
            newElement.tup = tuple_cat(tup, tie(i));

            /*for_each(tup, [this](auto x){
                vec.emplace_back(x);
            });*/
            m.insert(make_pair(i,newElement));
        }
        return m.find(i)->second;
    }
    Nested const& operator[] (size_t i) const {
        return m.find(i)->second;
    }

    int size();

private:
    //vector<int>vec;
    shared_ptr<int>sizeMatrix;
    template<size_t Depth1, int defaultvalue1, typename U, typename ...Args1>
    friend class SubSpace;
    SubSpace(int*ptr){
        sizeMatrix.reset(ptr);
    }
};

template <size_t Depth, int defaultvalue, typename T, typename ...Args>
SubSpace<Depth, defaultvalue, T, Args...>::SubSpace(){
    if(!sizeMatrix){
        sizeMatrix.reset(new int);
        *sizeMatrix = 0;
    }
}

template <size_t Depth, int defaultvalue, typename T, typename ...Args>
int SubSpace<Depth, defaultvalue, T, Args...>::size(){
    return *sizeMatrix;
}

template <int defaultvalue, typename T, typename...Args>
inline bool operator==
    (const SubSpace<0, defaultvalue, T, Args...>& lhs,
     const int& rhs)
{
    return lhs.getValue()==rhs;
}

#endif // MATRIX_H
