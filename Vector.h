//VECTOR.H

#ifndef Vector_h
#define Vector_h

class Vector {

public:

	//Constructors

	Vector();
	Vector(double x, double y, double z);
    Vector(const Vector& vector);

	//Destructor

	~Vector();

	//-------------------------------------------------------

	//getters

	double x() const { return x_; }
	double y() const { return y_; }
	double z() const { return z_; }

	//setters

	void setx(double x) { x_ = x; }
	void sety(double y) { y_ = y; }
	void setz(double z) { z_ = z; }


	//-------------------------------------------------------

    //Function: MAGNITUDE

	double mag() const;

	//Function: THETA

	double theta() const;

	//Function: PHI

	double phi() const;

	//Function: SCALAR RPODUCT

	double scalarProduct() const;

	//Function: VECTOR PRODUCT

	double vectorProduct() const;

	//Function: ANGLE

	double angle() const;

	//-------------------------------------------------------

	//Operator + (Vector+Vector)

	Vector operator+(const Vector& vect) const;

	//Operator - (Vector-Vector)

	Vector operator-(const Vector& vect) const;

	//Operator * (Vector*double) 
	
	Vector operator*(const double& vect) const;

	//Operator / (Vector/double)

	Vector operator/(const double& vect) const;

	//Operator =

	const Vector& operator=(const Vector& vect);



private:

	double x_;
	double y_;
	double z_;







};


#endif