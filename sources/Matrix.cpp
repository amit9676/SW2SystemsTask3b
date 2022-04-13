#include "Matrix.hpp"

namespace zich{

    //constructor
    Matrix::Matrix(const vector<double>& vals,const int r,const int c){
        if(c <= 0 || r <= 0){
            //checking condition one - make sure matrix dimentions are positive
            throw runtime_error("invalid matrix size");
        }
        if((size_t)vals.size() != r*c){
            //checking condition two - make sure matrix dimentions match the vector
            throw runtime_error("dimentions dont fit to verctor size");
        }
        this->vals = vals;
        this->r = r;
        this-> c = c;
    }


    //aid functions
    void Matrix::matchingSize(const Matrix& mat) const{
        /* 
            aid function which purpose is to compare matrices dimentions.
            because it is used in many methods - it is best to put it as a seperate function
            if matrices dimentions do not match, it means it is impossible to peform add ot substruct action
            between two matrices
        */
        if(this->r != mat.r || this->c != mat.c){
            throw runtime_error("matrixes size dont match");
        }
    }

    double Matrix::getSum() const{
        /*
            aid function which purpose is to get the sum of all values in the matrix.
            it is used for many comparasion operators (==, =>, <=, <, >, !=)
        */
        double result = 0;
        for(size_t i = 0; i < (size_t)this->vals.size(); i++){
            result += this->vals[i];
        }
        return result;
    }


    //add
    Matrix Matrix::operator+(Matrix& mat1) const{
        /*
            add the values of two matrices in every cell, and put the results in a new matrix
        */
        matchingSize(mat1);
        vector<double> newVals((size_t)r*(size_t)c,0);
        for(size_t i = 0; i< r*c; i++){
            newVals[i] = this->vals[i] + mat1.vals[i];
        }
        return Matrix(newVals,r,c);
    }

    Matrix &Matrix::operator+=(Matrix& mat1){

        /*
            the original adding was done in the operator above,
            so no need to rewrite it here, however here we re-point
            the original matrix to the result matrix.
        */

        *this = *this + mat1;
        return *this;
    }

    Matrix Matrix::operator+(){
        /*
            this operator makes a new copy of the given matrix, and returns it.
        */
        vector<double> newVals((size_t)r*(size_t)c,0);
        for(size_t i = 0; i< r*c; i++){
            newVals[i] = this->vals[i];
        }
        return Matrix(newVals,r,c);
    }

    Matrix Matrix::operator+(double value){
        /*
            add fixed value to every cell in the matrix
        */
        vector<double> newVals((size_t)r*(size_t)c,0);
        for(size_t i = 0; i< r*c; i++){
            newVals[i] = this->vals[i] + value;
        }
        return Matrix(newVals,r,c);
    }

    Matrix Matrix::operator++(const int a)
    {
        /*
            the calculation itself was made with the operator +,
            no need to recalculate!
            here it was needed to repoint the matrix to the result matrix.
            because this operation is m++, we need to keep the original input, 
            so we make a copy of the original matrix, repoint the original to the result value.
            then we return the copy, which is unaffected by the changes
        */
        Matrix preInc = *this;
        *this = *this+1;
        return preInc;
    }

    Matrix Matrix::operator++()
    {
        /*
            like the method above - the calcaultion themselves were made with the operator +
            however here we return the modified matrix instead the original (++m), so no need for a copy
            here.
        */
        *this = *this + 1;
        return *this;
    }



    //substract
    Matrix Matrix::operator-(){
        /*take every cell in the matrix, multiply it with -1 to get the negative value, return it.

            the calculation the,selves were done in with the * operator, no need to repeat it here.
        */

        return *this * (-1);
    } 

    Matrix Matrix::operator-(Matrix &mat){

        /*
            first we check if the dimentions are match, if it does - we go through every cell and substract
            the relative cell in the matrices.
        */
        
        matchingSize(mat);
        vector<double> newVals((size_t)r*(size_t)c,0);
        for(size_t i = 0; i< r*c; i++){
            newVals[i] = this->vals[i] - mat.vals[i];
        }
        return Matrix(newVals,r,c);
    } // Matrix1 - Matrix2

    Matrix Matrix::operator-=(Matrix &mat){
        /*
        just like the addition - no need to repeat actions, just to repoint and use the - operator
        */
        *this = *this - mat;
        return *this;
    } //Matrix -= a

    Matrix Matrix::operator-(double value){

        /*
            first we multiply the value with -1 to get the negative, then we can use the + operator
            to add the value to the matrix.
            no need to repeat actions
        */
        return *this + (value * -1);
    }
    Matrix Matrix::operator--(int v){
        /*
            just like the m++, but with m--.
            we get copy, and repoint
        */
        Matrix preDec = *this;
        *this = *this-1;
        return preDec;
    }

    Matrix Matrix::operator--(){
        /*
            just like the ++m, but with --m.
            repoint and return
        */
        *this = *this - 1;
        return *this;
    }


    //multiplication
    Matrix &Matrix::operator*=(const double scalar){
        /*
            the multiplication calculation itself was used with * operatior, here we only need
            to repoint the original matrix
        */
        
        *this = *this * scalar;
        return *this;
    } // Marix *= a

    Matrix operator*(const double scalar, Matrix& mat){
        /*
            the multiplication calculation itself was used with * operatior
        */
        return mat * scalar;
    }

    Matrix Matrix::operator*(const double scalar){
        /*
            multiply every cell in the matrix with given scalar
        */
        vector<double> newVals((size_t)r*(size_t)c,0);
        for(size_t i = 0; i< r*c; i++){
            newVals[i] = this->vals[i] * scalar;
        }
        return Matrix(newVals,r,c);
    } // Matrix * a

    Matrix Matrix::operator*(const Matrix& mat) const{
        //multiply two matrices
        if(this->c != mat.r){
            /*
                first we check if the given matrixes can actually be multiplied
                if they dont - throw error.
            */
            throw runtime_error("invalid sizes for matrix multiplication");
        }

        /*
            general calculation method - create the result matrix
            go through every cell in the result matrix, and peform the calculcation based on the method
            learn in liniar algebra course
         */
        vector<double> newVals((size_t)this->r*(size_t)mat.c,0);
        size_t k = 0;
        
        for(size_t i = 0; i< this->r; i++){
            
            for(size_t j = 0; j < mat.c; j++){
                for(size_t l = 0; l < mat.r; l++){
                    newVals[k] += this->vals[((size_t)this->c*i) + l] * mat.vals[j + (l*(size_t)mat.c)];                    
                }
                k++;
            }
        }
        return Matrix(newVals,this->r,mat.c);

    }

    Matrix &Matrix::operator*=(const Matrix& mat){
        /*
            just like the multiplication with the scalar - we already used the * operator.
            no need to recalculate.
        */
        *this = (*this) * mat;
        return *this;
    }



    //print
    ostream& operator<<(ostream& COUT, const Matrix& mat){
        for(size_t i = 0; i < mat.r; i++){
            COUT << "["; // first - we print the '[' character
            /*
                then we go through every line, and we print it out
            */
            for(size_t j = 0; j < mat.c; j++){
                /*
                    the inner loop prints the elements in the line itself,
                    they can be reached in the vector, by multiplying the current 
                    number of the line to be printed (starting with 0),
                    with the number of columns.
                    it gives us the offset.

                */
                COUT << mat.vals[(i*(size_t)mat.c) + j];//and the j is the number of element in the line itself
                //to be printed

                if(j < mat.c - 1){
                    //if there are more elements in the line ahead - also print space
                    COUT << " ";
                }
                else{
                    //here we reached the last element in the line, so we print the closing ']'
                    if(i < mat.r -1){
                        //if its also the last row - print \n too
                        COUT << "]\n";
                    }
                    else{
                        COUT << "]";
                    }
                    
                }
            }
        }
        return COUT;
    }

    //input
    istream& operator>>(istream& CIN, Matrix& mat){
        /*
            general input recieving method - we go through the input - for every '['
            we get - we know its another row.
            when we get ']' - we need to check the number of elements in the row, compare it to other rows.
            after all all rows must have equal number of elements.
            and in the middle, between spaces and commas,
            when we recieve numbers - we parse them and insert them to vectors
        */

        //initilization
        int rows = 0; //number of rows to count
        int columns = 0; //number of column
        int currentCols = 0; //another column counter, to make sure number of elements are equal
        //in all rows

        bool initialColCounter = true; //used with the currentCols

        vector<double> vals(0,0); //initilize vector
        char ch = 0;
        string currentStringToDoubleParse;//holds at any moment the string value to parse to double
        //if it fails, then the input is invlalid and error is thrown


        ch = CIN.get(); //begin to recieve input
        while(ch != '\n'){
            //while we have not reached \n - continue

            if(ch == '['){
                rows++;
            }
            else if(ch == ']'){
                try{
                    auto si = vals.end();
                    vals.insert(si,stod(currentStringToDoubleParse));
                    currentStringToDoubleParse = "";
                    //parse the current string velue to number, and reset it to the next characters

                    if(initialColCounter){
                        columns++;
                    }
                    
                    currentCols ++;
                }
                catch(const std::exception e){
                    throw runtime_error("parse failed, it means input was invalid");

                }
                
                initialColCounter = false; // this line is to know when we have the initial number of
                // elements in row.
                //now that we have it, we set it to false


                //dealing with some bad input that may arise
                if(currentCols == 0){
                    throw runtime_error("number of columns cant be 0");
                }
                if(columns != currentCols){
                    //this is why we use the currentCols
                    throw runtime_error("rows with different size, cant build matrix!");
                }
                currentCols = 0;
            }
            else if(ch == ','){
                //start new row!
                ch = CIN.get(); //skip the following space
                if(ch != ' '){
                    throw runtime_error("input format is invalid");
                }
            }
            else if(ch == ' '){
                //the space between values, parse the value, add it to matrix and move on!
                try{
                    auto si = vals.end();
                    vals.insert(si,stod(currentStringToDoubleParse));
                    currentStringToDoubleParse = "";
                    if(initialColCounter){
                        columns++;
                    }
                    
                    currentCols ++;
                }
                catch(const std::exception e){
                    throw runtime_error("parse failed, it means input was invalid");

                }
                
            }
            else{
                //we got char which is a number, or peroid for decimals.
                //(if its something else, the parse will result in error, it means bad input)
                //add it to the current string and move to the next char
                currentStringToDoubleParse+=ch;
            }
            ch = CIN.get();//read next char
        }
        if(rows == 0){
            //number of rows must be positive
            throw runtime_error("number of rows cant be 0");
        }

        //when finished, insert values to the matrix
        mat = Matrix(vals,rows,columns);
        return CIN;

    }

    //comparasion
    //in all comparasion - we use the matching size to make sure we actually can compare the matrices
    //if it is not match - aport.
    //else we use the sum caculcator to determine who has greater value.
    bool Matrix::operator>(const Matrix& mat) const{
        matchingSize(mat);
        return this->getSum() > mat.getSum();
    }
    bool Matrix::operator>=(const Matrix& mat) const{
        matchingSize(mat);
        return this->getSum() >= mat.getSum();
    }
    bool Matrix::operator==(const Matrix& mat) const{
        //in ==, we need to make sure every cell in the 2 matrices is equal
        matchingSize(mat);
        for(size_t i = 0; i <mat.r; i++){
            if(mat.vals[i] != this->vals[i]){
                return false;
            }
        }
        return true;
    }
    bool Matrix::operator<=(const Matrix& mat) const{
        matchingSize(mat);
        return this->getSum() <= mat.getSum();
    }
    bool Matrix::operator<(const Matrix& mat) const{
        matchingSize(mat);
        return this->getSum() < mat.getSum();
    }
    bool Matrix::operator!=(const Matrix& mat) const{
        matchingSize(mat);
        //!= is the opposite of ==, no need to recalculcate
        return !(*this == mat );
    }

}

