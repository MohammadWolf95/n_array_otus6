#include <iostream>
#include "matrix.h"
#include <assert.h>
#include <memory>
#include <newtuple.h>

using namespace std;

/*class Test{
public:
    int fl = 5;
    operator auto(){
        return fl;
    }
};*/

int main(int argc, char *argv[])
{
    //NewTuple<1, size_t> newTup;
    //NewTuple<0, size_t, size_t>t=newTup;
    //vector<int>vec;
    //Test obj;
    //vec.push_back((int)obj);
    using Matrix = SubSpace<3, -1, int>;
    Matrix matrix;
    auto a = matrix[1][2][1][2];
    assert(a == -1);
    assert(matrix.size()==0);
    matrix[1][2][1][2]=100;
    assert(matrix.size()==1);
    matrix[1][2][1][2]=50;
    assert(matrix.size()==1);
    matrix[1][2][1][3]=50;
    a = matrix[1][2][1][3];
    assert(a == 50);
    assert(matrix.size()==2);
}

