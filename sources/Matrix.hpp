#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
namespace zich{

    class Matrix{
        private:
            vector<double> vals;
            int r, c;
        public:
            
            Matrix(const vector<double>&,const int,const int); //constructor

            void matchingSize(Matrix&) const;

            //addition
            Matrix operator+(Matrix&); //Matrix1 + Matrix2
            Matrix operator+=(Matrix&);
            Matrix operator+();// copy Matrix
            Matrix operator+=(double);
            Matrix operator+(int);
            Matrix operator+(double);
            Matrix operator++(int);
            Matrix operator++();
            
            //substract
            Matrix operator-(); //copy matrix negative
            Matrix operator-=(Matrix&); //Matrix -= a
            Matrix operator-(Matrix&); // Matrix1 - Matrix2
            Matrix operator-(int);
            Matrix operator-(double);
            Matrix operator--(int);
            Matrix operator--();

            //multiplication with scalar
            Matrix operator*=(const double); // Marix *= a
            friend Matrix& operator*(const double, Matrix&); // a* Matrix
            Matrix operator*(const double); // Matrix * a
            Matrix operator*(const int); // Matrix * a
            Matrix operator*(Matrix&); // Matrix * Matrix
            
            //multiplication with another matrix
            Matrix operator*=(Matrix&);

            

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
            double getSum() const;
            
    };

};