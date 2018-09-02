#include <iostream>
#include "matrix.h"
#include <assert.h>
#include <memory>
#include <newtuple.h>
#include <vector>

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
    /*shared_ptr<vector<int>>vec1;
    vec1.reset(new vector<int>);
    vec1->emplace_back(1);*/



    using Matrix = SubSpace<3, 3, -1, int>;
    Matrix matrix;
    auto a = matrix[1][2][1][2];

    assert(a == -1);
    assert(matrix.size()==0);

    for(int i=0;i<50;++i)
        for(int j = 0;j<50;++j)
            for(int k = 0;k<50;++k)
                for(int l=0;l<50;++l){
                    matrix[i][j][k][l]=i+j+k+l;
                }

    //matrix[1][2][1][2]=100;

    for(auto i:matrix){
        int x, y, z, a, result;
        tie(x, y, z, a, result) = i;
        cout<<x<<y<<z<<a<<result<<endl;
    }

    cout<<matrix.size()<<endl;

    //assert(matrix.size()==1);
    //matrix[1][2][1][2]=50;

    /*assert(matrix.size()==1);
    matrix[1][2][1][3]=50;
    a = matrix[1][2][1][3];

    for(auto i:matrix){
        int x, y, z, a, result;
        tie(x, y, z, a, result) = i;
        cout<<x<<y<<z<<a<<result<<endl;
    }

    assert(a == 50);
    assert(matrix.size()==2);*/
}

