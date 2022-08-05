# 29. The Big Five

Default constructor
```cpp
Matrix::Matrix(): _numRows{0}, _numCols{0}, _matrix{nullptr}{}
```

Resize

```cpp
Matrix::Matrix(int numRows, int numCols){
    _numRows = numRows;
    _numCols = numCols;
    _matrix = new int*[numRows];
    for (int i = 0; i < numRows; i++){
        _matrix[i] = new int[numCols];
        for (int j = 0; j < numCols; j++){
            _matrix[i][j] = 0;
        }
    }
}
```

Destructor

```cpp
Matrix::Matrix(){
    for (int i = 0; i < _numRows; i++){
        delete[] _matrix[i];
    }

    delete [] _matrix;
}
```

Move constructor

```cpp
Matrix::Matrix(Matrix &m): _numRows{m._numRows}{...}{
    m._numRows = 0;
    ...
    m._matrix = nullptr;
}
```

Copy assignment operator

```cpp

void swap(Matrix & m){
    std::swap(_numRows, m._numRows);
    ...
}

#include <utility>
Matrix &Matrix::operator=(const Matrix &m){
    Matrix tmp{m};
    swap(tmp);
    return *this;
}
```

Iterator
``` cpp
class Iterator{
    int r;
    int c;
    Iterator(int r, int c): r{r}, c{c}{};
    public:
        int &operator*(){
            return _matrix[r][c];
        }

        Iterator &operator++(){
            this._matrix[r]++;
            //check c
        }

        bool operator==(const Iterator &other){
            return (this->_matrix == other._matrix);

        }

        bool operator!=(const Iterator &other){
            return !(*this == other);
        }
}

Iterator begin(){
    return Iterator{0,0}
}

Iterator end(){
    return Iterator{-1, -1}
}

for (auto i : m){
    std::cout << i << endl;
}
```