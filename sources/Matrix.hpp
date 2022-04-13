#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
namespace zich{
    class Matrix{
        private:
            vector<double> vals;
            int r, c;
            double getSum() const;
            void matchingSize(const Matrix&) const;
        public:
            
            Matrix(const vector<double>&,const int,const int); //constructor

            

            //addition
            Matrix operator+(Matrix&) const; //Matrix1 + Matrix2
            Matrix &operator+=(Matrix&);
            Matrix operator+();// copy Matrix
            Matrix operator+(double);

            //m++ (first retain m value, then increment it)
            Matrix operator++(const int);

            //++m ( first increment value, then assign m)
            Matrix operator++();
            
            //substract
            Matrix operator-(); //copy matrix negative
            Matrix operator-=(Matrix&); //Matrix -= a
            Matrix operator-(Matrix&); // Matrix1 - Matrix2
            Matrix operator-(double);

            //m-- (first retain m value, then decrement it)
            Matrix operator--(int);

            //--m ( first drecrement value, then assign m)
            Matrix operator--();

            //multiplication with scalar
            Matrix &operator*=(const double); // Matrix *= a
            friend Matrix operator*(const double, Matrix&); // a* Matrix
            Matrix operator*(const double); // Matrix * a
            Matrix operator*(const Matrix&) const; // Matrix * Matrix
            
            //multiplication with another matrix
            Matrix &operator*=(const Matrix&);

            

            //print
            friend ostream& operator<<(ostream& COUT, const Matrix& mat);

            //input
            friend istream& operator>>(istream&, Matrix&);

            //comparasion
            bool operator>(const Matrix& mat) const;
            bool operator>=(const Matrix& mat) const;
            bool operator==(const Matrix& mat) const;
            bool operator<=(const Matrix& mat) const;
            bool operator<(const Matrix& mat) const;
            bool operator!=(const Matrix& mat) const;
            
            
    };

};