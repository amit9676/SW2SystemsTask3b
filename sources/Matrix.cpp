#include "Matrix.hpp"
using namespace zich;


Matrix::Matrix(const vector<double>& vals,const int r,const int c){
    if(c <= 0 || r <= 0){
        throw runtime_error("invalid matrix size");
    }
    if((size_t)vals.size() != r*c){
        throw runtime_error("dimentions dont fit to verctor size");
    }
    this->vals = vals;
    this->r = r;
    this-> c = c;
}


//aid functions
void Matrix::matchingSize(Matrix& mat) const{
    if(this->r != mat.r || this->c != mat.c){
        throw runtime_error("matrixes size dont match");
    }
}

double Matrix::getSum() const{
    double result = 0;
    for(size_t i = 0; i < (size_t)this->vals.size(); i++){
        result += this->vals[i];
    }
    return result;
}

Matrix Matrix::operator+(Matrix& mat1){
    matchingSize(mat1);
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] + mat1.vals[i];
    }
    return Matrix(newVals,r,c);
}

// Matrix Matrix::operator+(Matrix& mat1){
//     matchingSize(mat1);

//     vector<double> newVals(0,r*c);
//     for(size_t i = 0; i< r*c; i++){
//         newVals[i] = this->vals[i] + mat1.vals[i];
//     }
//     return Matrix(newVals,r,c);
// }

Matrix Matrix::operator+=(Matrix& mat1){
    matchingSize(mat1);

    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] + mat1.vals[i];
    }
    return Matrix(newVals,r,c);
}

Matrix Matrix::operator+(){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i];
    }
    return Matrix(newVals,r,c);
}

Matrix Matrix::operator+(int value){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] + value;
    }
    return Matrix(newVals,r,c);
}
Matrix Matrix::operator+(double value){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] + value;
    }
    return Matrix(newVals,r,c);
}
//consider changing return Matrix& to void
Matrix Matrix::operator+=(double a){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[(unsigned int)i] = this->vals[i] + a;
    }
    return Matrix(newVals,r,c);
}


Matrix Matrix::operator++(int a)
{
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] + 1;
    }
    return Matrix(newVals,r,c);
}

Matrix Matrix::operator++()
{
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] + 1;
    }
    return Matrix(newVals,r,c);
}

//substract
Matrix Matrix::operator-(){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] * -1;
    }
    return Matrix(newVals,r,c);
} //copy matrix negative


Matrix Matrix::operator-=(Matrix &mat){
    matchingSize(mat);
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] - mat.vals[i];
    }
    return Matrix(newVals,r,c);
} //Matrix -= a
Matrix Matrix::operator-(Matrix &mat){
    matchingSize(mat);
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] - mat.vals[i];
    }
    return Matrix(newVals,r,c);
} // Matrix1 - Matrix2

Matrix Matrix::operator-(int value){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] - value;
    }
    return Matrix(newVals,r,c);
}
Matrix Matrix::operator-(double value){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] - value;
    }
    return Matrix(newVals,r,c);
}
Matrix Matrix::operator--(int v){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] - 1;
    }
    return Matrix(newVals,r,c);
}

Matrix Matrix::operator--(){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] - 1;
    }
    return Matrix(newVals,r,c);
}

//multiplication
Matrix Matrix::operator*=(const double scalar){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] * scalar;
    }
    return Matrix(newVals,r,c);
} // Marix *= a
Matrix& zich::operator*(const double scalar, Matrix& mat){
    return mat;
}

Matrix Matrix::operator*(const double scalar){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] * scalar;
    }
    return Matrix(newVals,r,c);
} // Matrix * a

Matrix Matrix::operator*(const int scalar){
    vector<double> newVals(0,r*c);
    for(size_t i = 0; i< r*c; i++){
        newVals[i] = this->vals[i] * scalar;
    }
    return Matrix(newVals,r,c);}  // Matrix * a

Matrix Matrix::operator*(Matrix& mat){
    if(this->c != mat.r){
        throw runtime_error("invalid sizes for matrix multiplication");
    }
    vector<double> newVals(0,this->r*mat.c);
    int k = 0;
    for(size_t i = 0; i< this->r; i++){
        for(size_t j = 0; j < mat.c; j++){
            for(size_t l = 0; l < mat.r; l++){
                newVals[(size_t)k] += this->vals[((size_t)this->c*i) + l] * mat.vals[j + (l*(size_t)mat.c)]; 
            }
            
            k++;
        }

    }
    return Matrix(newVals,this->r,mat.c);

}

Matrix Matrix::operator*=(Matrix& mat){
    return *this * mat;
}



//print
ostream& zich::operator<<(ostream& COUT, const Matrix& mat){
    for(size_t i = 0; i < mat.r; i++){
        COUT << "[";
        for(size_t j = 0; j < mat.c; j++){
            COUT << mat.vals[(i*(size_t)mat.c) + j];
            if(j < mat.c - 1){
                COUT << " ";
            }
            else{
                COUT << "]\n";
            }
        }
    }
    return COUT;
}

//input

// string strinify(istream& CIN){
//     string result = "";
//     char ch = 0;
//     while(ch != '\n'){
//         ch = CIN.get();
//         result += ch;
//     }

// }

istream& zich::operator>>(istream& CIN, Matrix& mat){
    int rows = 0;
    int columns = 0;
    int currentCols = 0;
    bool initialColCounter = true;
    vector<double> vals;
    char ch = 0;
    string currentStringToDoubleParse;
    while(ch != '\n'){
        ch = CIN.get();
        if(ch == '['){
            rows++;
        }
        else if(ch == ']'){
            initialColCounter = false;
            if(columns != currentCols){
                throw runtime_error("rows with different size, cant build matrix!");
            }
        }
        else if(ch == ','){
            
            ch = CIN.get(); //skip the following space
        }
        else if(ch == ' '){
            try{
                auto si = vals.end();
                vals.insert(si+1,stod(currentStringToDoubleParse));
                if(initialColCounter){
                    columns++;
                }
                
                currentCols ++;
            }
            catch(const std::exception e){
                throw runtime_error("parse failed, it means input was invalid");

            }
            currentStringToDoubleParse = "";
        }
        else{
            currentStringToDoubleParse+=ch;
        }
    }

    mat = Matrix(vals,rows,columns);
    return CIN;

}

//comparasion
bool Matrix::operator>(const Matrix& mat) const{
    return this->getSum() > mat.getSum();
}
bool Matrix::operator>=(const Matrix& mat) const{
    return this->getSum() >= mat.getSum();
}
bool Matrix::operator==(const Matrix& mat) const{
    return this->getSum() == mat.getSum();
}
bool Matrix::operator<=(const Matrix& mat) const{
    return this->getSum() <= mat.getSum();
}
bool Matrix::operator<(const Matrix& mat) const{
    return this->getSum() < mat.getSum();
}
bool Matrix::operator!=(const Matrix& mat) const{
    return this->getSum() != mat.getSum();
}



