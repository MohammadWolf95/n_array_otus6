#ifndef MATRIX_H
#define MATRIX_H

#include <tuple>
#include <iterator>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <size_t Depth, typename T=int>
class SubSpace;

template <typename T>
class SubSpace<0, T> {
public:
    std::map<int, int> m;

    T& operator[] (size_t i) {
        if(m.find(i)==m.end()){
            m.insert(make_pair(i,i));
        }
        return m.find(i)->second;
    }
    T const& operator[] (size_t i) const {

        return m.find(i)->second;
    }
};

template <size_t Depth, typename T>
class SubSpace {
public:
    using Nested = SubSpace<Depth-1, T>;
    std::map<int, Nested> m;
    tuple<int>tup;
    Nested& operator[] (size_t i) {
        if(m.find(i)==m.end()){
            vec.push_back(i);
            Nested d;
            m.insert(make_pair(i,d));
        }
        return m.find(i)->second;
    }
    Nested const& operator[] (size_t i) const {
        return m.find(i)->second;
    }
private:
    vector<int>vec;
};

using NSpaceVector = SubSpace<3>;
#endif // MATRIX_H
