#include "matrix.h"
#include <vector>


matrix::matrix() : _size(0){
    INFO("Object of class matrix was created using matrix() constructer");
}

matrix::matrix(const size_t size):  _size(size){
    INFO("Object of class matrix was created using matrix(size_t) constructer");
}

matrix::matrix(size_t sizeRow, size_t sizeCol) : _sizeCol(sizeCol), _sizeRow(sizeRow), _size(sizeRow*sizeCol){
    INFO("Object of class matrix was created using matrix(size_t, size_t) constructer");
    mat = new vector* [sizeRow];
    for (int i=0; i < sizeRow; i++){
        mat[i] = new vector(sizeCol);
    }
}

matrix::matrix(int* data_input, size_t sizeRow, size_t sizeCol) : _sizeCol(sizeCol), _sizeRow(sizeRow), _size(sizeRow*sizeCol){
    INFO("Object of class matrix was created using matrix(int*, size_t, size_t) constructer");
    this->assign(data_input, sizeRow, sizeCol);
}
matrix::matrix(int* data_input, size_t size): _size(size){
    INFO("Object of class matrix was created using matrix(int*, size_t) constructer");
    // loop through input (how to know size of each vector)
}

matrix::matrix(vector** data, size_t row, size_t col) : _sizeRow(row), _sizeCol(col), _size(row*col){
    INFO("Object of class matrix was created using matrix(vector**, size_t, size_t) constructer");
    // loop through the rows and grab each vector and put the vector in the rows
    mat = new vector* [row];
    for(int row = 0; row < _sizeRow; row++){
        vector* newVec = new vector(*data[row]);
        mat[row] = newVec;
    }
}

matrix::~matrix(){
    INFO("Object of class matrix deleted");
    for(int i = 0; i < _sizeRow; i++){
        delete mat[i];
    }
    delete mat;
    _size = 0;
    _sizeRow = 0;
    _sizeCol = 0;
}

vector& matrix::operator[](size_t index){
    return *(mat[index]);
}

size_t matrix::get_size()const { return _size; }
size_t matrix::get_sizeRow()const { return _sizeRow; }
size_t matrix::get_sizeCol()const { return _sizeCol; }

void matrix::assign(int* data_input, size_t sizeRow, size_t sizeCol){
    _size = sizeRow * sizeCol;
    _sizeRow = sizeRow;
    _sizeCol = sizeCol;
    mat = new vector* [sizeCol];
    int* startOfVec = data_input;
    int* endOfVec = data_input+sizeCol;
    for (int i=0; i < sizeRow; i++){
        mat[i] = new vector(startOfVec, endOfVec);
        startOfVec = endOfVec;
        endOfVec = startOfVec + sizeCol;
    }
}

void matrix::resize(size_t newSizeRow, size_t newSizeCol){
    if (newSizeRow > _sizeRow){
        vector** newMat = new vector*[newSizeRow];
        for(int rows=0;rows < _sizeRow; rows++){
            newMat[rows] = mat[rows];
        }
        newMat[newSizeRow-1] = new vector(newSizeCol);
        mat = newMat;
    }
    _sizeRow = newSizeRow;

    //new collumn
    if(newSizeCol > _sizeCol){
        for(int rows=0;rows < _sizeRow; rows++){
            //save values of old vector
            std::vector<int> oldVal;
            for(int i=0;i < _sizeCol; i++){
                oldVal.push_back(mat[rows][0][i]);
            }

            // reassigning the old values
            mat[rows]->resize(newSizeCol);
            for(int col=0; col<_sizeCol; col++){
                mat[rows][0][col] = oldVal[col];
            }
        }
    }
    _sizeCol = newSizeCol;
    _size = _sizeCol * _sizeRow;
}

// I am assuming that the passed in object is correct 
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
        for (int col = 0; col < _sizeCol; col++){
            // data[2][4] = 1
            print += "data[" + std::to_string(row) + "][" + std::to_string(col) +"] = " + std::to_string(mat[row]->data[col]) + "\n";
        }
    }
    return print;
}

// overload the << for stream output ( non member function )
std::ostream& operator<<(std::ostream& stream, const matrix& m){
    stream << m.print();
    return stream;
}
