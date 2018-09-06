#ifndef MATRIX_H
#define MATRIX_H

#include <tuple>
#include <iterator>
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include "newtuple.h"

using namespace std;

template <size_t Depth, size_t cloneDepth, int defaultvalue, typename T=int, typename ...Args>
class SubSpace;

template <size_t cloneDepth, int defaultvalue, typename T, typename...Args>
class SubSpace<0, cloneDepth, defaultvalue, T, Args...> {
public:
    using mytuple = typename generate_tuple_type<size_t, T, cloneDepth+1>::type;

    using Nested = SubSpace<0, cloneDepth, defaultvalue, T, Args...>;
    SubSpace():
    value(-1), firstInit(false){}
    std::map<int, Nested> m;
    tuple<size_t,Args...>tup;
    Nested& operator[] (size_t i) {
        if(m.find(i)==m.end()){
            Nested newElement(sizeMatrix, vectorTuples);
            get<sizeof...(Args)>(tup)=i;
            newElement.tup = tup;
            m.insert(make_pair(i, newElement));

            /*vector<int>vec;
            for_each(tup, [&vec](auto x){
                vec.emplace_back(x);
            });
            tuple_print::print(tup);*/
        }
        return m.find(i)->second;
    }

    void operator=(const T&other){
        if(!firstInit){
            firstInit=true;
            ++(*sizeMatrix);
            //tuple_print::print(tup);
            auto t = tuple_cat(tup,tie(value));

            vectorTuples->push_back(t);
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
    bool firstInit;
    shared_ptr<int>sizeMatrix;
    shared_ptr<vector<mytuple>>vectorTuples;
    template<size_t Depth1, size_t cloneDepth1, int defaultvalue1, typename U, typename ...Args1>
    friend class SubSpace;

    SubSpace(shared_ptr<int> &ptr, shared_ptr<vector<mytuple>> &ptr_vec):
        value(-1), firstInit(false){
        sizeMatrix = ptr;
        vectorTuples = ptr_vec;
    }
};

template <size_t Depth, size_t cloneDepth, int defaultvalue, typename T, typename ...Args>
class SubSpace{
public:
    using mytuple = typename generate_tuple_type<size_t, T, cloneDepth+1>::type;
    shared_ptr<vector<mytuple>>vectorTuples;
    using iterator = typename vector<mytuple>::iterator;

    iterator begin();
    iterator end();

    using Nested = SubSpace<Depth-1, cloneDepth, defaultvalue, T, Args..., size_t>;
    std::map<int, Nested> m;
    tuple<size_t, Args...>tup;
    SubSpace();

    Nested& operator[] (size_t i) {
        if(m.find(i)==m.end()){
            Nested newElement(sizeMatrix, vectorTuples);
            get<sizeof...(Args)>(tup)=i;
            newElement.tup = tuple_cat(tup, make_tuple(0));
            m.insert(make_pair(i,newElement));
        }
        return m.find(i)->second;
    }
    Nested const& operator[] (size_t i) const {
        return m.find(i)->second;
    }

    int size();

private:
    shared_ptr<int>sizeMatrix;
    template<size_t Depth1, size_t cloneDepth1, int defaultvalue1, typename U, typename ...Args1>
    friend class SubSpace;

    SubSpace(shared_ptr<int> &ptr, shared_ptr<vector<mytuple>> &ptr_vec)
    {
        sizeMatrix = ptr;
        vectorTuples = ptr_vec;
        //cout<<"sizeMatrix = "<<sizeMatrix<<endl;
    }
};

template <size_t Depth,size_t cloneDepth, int defaultvalue, typename T, typename ...Args>
SubSpace<Depth,cloneDepth, defaultvalue, T, Args...>::SubSpace(){
        sizeMatrix.reset(new int);
        *sizeMatrix = 0;
        vectorTuples.reset(new vector<mytuple>);
}

template <size_t Depth, size_t cloneDepth, int defaultvalue, typename T, typename ...Args>
int SubSpace<Depth, cloneDepth, defaultvalue, T, Args...>::size(){
    return *sizeMatrix;
}

template <size_t Depth, size_t cloneDepth, int defaultvalue, typename T, typename ...Args>
typename SubSpace<Depth, cloneDepth, defaultvalue, T, Args...>::iterator SubSpace<Depth, cloneDepth, defaultvalue, T, Args...>::begin(){
    auto &vec = *vectorTuples;
    return vec.begin();
}

template <size_t Depth, size_t cloneDepth, int defaultvalue, typename T, typename ...Args>
typename SubSpace<Depth, cloneDepth, defaultvalue, T, Args...>::iterator SubSpace<Depth, cloneDepth, defaultvalue, T, Args...>::end(){
    auto &vec = *vectorTuples;
    return vec.end();
}

template <size_t cloneDepth,int defaultvalue, typename T, typename...Args>
inline bool operator==
    (const SubSpace<0,cloneDepth, defaultvalue, T, Args...>& lhs,
     const int& rhs)
{
    return lhs.getValue()==rhs;
}

#endif // MATRIX_H
