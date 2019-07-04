#include "matrix.h"


matrix::matrix() : _size(0){
    INFO("Object of class matrix was created using matrix() constructer");
}

matrix::matrix(const size_t size):  _size(size){
    INFO("Object of class matrix was created using matrix(size_t size) constructer");
    mat = new vector* [size];
    for (int i=0; i < size; i++){
        mat[i] = new vector[size];
    }
}

matrix::matrix(size_t sizeRow, size_t sizeCol) : _sizeCol(sizeCol), _sizeRow(sizeRow), _size(sizeRow*sizeCol){
    INFO("Object of class matrix was created using matrix(size_t sizeRow, size_t sizeCol) constructer");
}

matrix::matrix(int* data_input, size_t sizeRow, size_t sizeCol) : _sizeCol(sizeCol), _sizeRow(sizeRow), _size(sizeRow*sizeCol){
    INFO("Object of class matrix was created using matrix(int* data_input, size_t sizeRow, size_t sizeCol) constructer");
    // loop through input
}
matrix::matrix(int* data_input, size_t size): _size(size){
    INFO("Object of class matrix was created using matrix(int* data_input, size_t size) constructer");
    // loop through input
}

matrix::matrix(vector** data, size_t row, size_t col) : _sizeRow(row), _sizeCol(col), _size(row*col){
    INFO("Object of class matrix was created using matrix(vector**, size_t, size_t) constructer");
    // loop through the rows and grab each vector and put the vector in the rows
    for(int row = 0; row < _sizeRow; row++){
        mat[row] = data[row];
    }
}

matrix::~matrix(){
    delete mat;
    _size = 0;
    _sizeRow = 0;
    _sizeCol = 0;
    INFO("Object Matrix Deleted");
}

vector& matrix::operator[](size_t index){
    return *(mat[index]);
}

size_t matrix::get_size()const { return _size; }
size_t matrix::get_sizeRow()const { return _sizeRow; }
size_t matrix::get_sizeCol()const { return _sizeCol; }

void matrix::assign(int* data_input, size_t sizeRow, size_t sizeCol){
    // make loop
}

void matrix::resize(size_t newSizeRow, size_t newSizeCol){
    _sizeRow = newSizeRow;
    _sizeCol = newSizeCol;
    _size = _sizeCol * _sizeRow;
}

// I am assuming that the passed in
matrix matrix::add(const matrix& nextObject ) const{
    vector** data;
    for(int row = 0; row < _sizeRow; row++){
        for (int col = 0; col < _sizeCol; col++){
            data[row][col] = mat[row][col] + nextObject.mat[row][col];
        }
    }
    return matrix(data, _sizeRow, _sizeCol);
}
matrix matrix::operator +(const matrix & nextObject) const{
    return this->add(nextObject);
}

std::string matrix::print() const{
    std::string print = "Matrix: size(" + std::to_string(_size) + ")\n";
    for(int row = 0; row < _sizeRow; row++){
        print += "[";
        for (int col = 0; col < _sizeCol; col++){
            if (col != 0) print += ", "; // add comma if not printing the first item
            print += mat[row]->data[col];
        }
        print += "]";
    }
    return print;
}

// overload the << for stream output ( non member function )
std::ostream& operator<<(std::ostream& stream, const matrix& m){
    stream << m.print();
    return stream;
}
