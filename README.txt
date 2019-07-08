Compile string: g++ -std=c++11 testMath.cpp math.cpp vector.cpp matrix.cpp -o out

vector.cpp:
The constuctor for vector(int*, int*) did not work proporly ( error from constuctor: pointer being freed was not allocated)
so i had to fix it by instantiating the data variable by having 'data = new int[_size];' before calling assign


Ryan Wilbur
B00737901
