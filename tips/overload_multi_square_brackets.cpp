template <size_t Width, size_t Depth, typename T=int>
struct SubSpace;

template <size_t Width, typename T>
struct SubSpace<Width,0,T> {
    std::array<T, Width> array;

    T& operator[] (size_t i) { return array[i]; }
    T const& operator[] (size_t i) const { return array[i]; }
};

template <size_t Width, size_t Depth, typename T>
struct SubSpace {
    using Nested = SubSpace<Width, Depth-1, T>;
    std::array<Nested, Width> array;

    Nested& operator[] (size_t i) { return array[i]; }
    Nested const& operator[] (size_t i) const { return array[i]; }
};


using NSpaceVector = SubSpace<8,6>;

int main()
{
    NSpaceVector nsv;
    nsv[2][4][7][4][0][7][6] = 2;
    cout << nsv[2][4][7][4][0][7][6] << endl; //-> 2
} 
