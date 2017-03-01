// For the Foruth example, we add a Label control to the 
// bottom of the window which displays the position of the
// Sphere

#include "win.h"
#include "point.h"
#include "matrix.h"
#include "OpenGLUtil.h"
#include "Quat.h"

void TestMatrices(void)
{
	//
	//    test data for exercising matrix methods
	//
	double m1Data[] = { 2, -1,  0, 
					    1,  3,  5,
					   -4,  2,  1 };
	double m2Data[] = {-4,  2,  1,
						2,  0,  2, 
						0,  0,  1 };
	double sumData[] = {-2,  1,  1,
						 3,  3,  7,
						-4,  2,  2 };
	double differenceData[] = { 6, -3, -1,
							   -1,  3,  3,
							   -4,  2,  0 };
	double productData[] = {-10,  4,  0,
							  2,  2, 12,
							 20, -8,  1 };
	double xRotData[] = { 1.0,	         0,             0.0, 0.0,
						  0.0, sqrt(3.0)/2.0,          -0.5, 0.0,
						  0.0,           0.5, sqrt(3.0)/2.0, 0.0, 
						  0.0,           0.0,           0.0, 1.0 };
	double yRotData[] = { sqrt(3.0)/2.0, 0.0,           0.5, 0.0,
					  	            0.0, 1.0,           0.0, 0.0,
								   -0.5, 0.0, sqrt(3.0)/2.0, 0.0,
								    0.0, 0.0,           0.0, 1.0 };
	double zRotData[] = { sqrt(3.0)/2.0,		  -0.5, 0.0, 0.0,
								    0.5, sqrt(3.0)/2.0, 0.0, 0.0,
								    0.0,           0.0, 1.0, 0.0,
								    0.0,		   0.0, 0.0, 1.0 };
	double scaleData[] = { 5,  0, 0, 0,
						   0, -2, 0, 0,
						   0,  0, 4, 0, 
						   0,  0, 0, 1 };
	double translationData[] = { 1, 0, 0, -4,
								 0, 1, 0, -2,
								 0, 0, 1,  6, 
								 0, 0, 0,  1 };
	double arbAxisData[] = { 0, 0, 1, 0,
							 1, 0, 0, 0,
							 0, 1, 0, 0, 
							 0, 0, 0, 1 };
	double transposeData[] = { 2,  1, -4, 
							  -1,  3,  2,
							   0,  5,  1 };
	double inverseData[] = { sqrt(3.0)/2.0, 0.0,          -0.5, 0.0,
									   0.0, 1.0,           0.0, 0.0,
									   0.5, 0.0, sqrt(3.0)/2.0, 0.0,
									   0.0, 0.0,           0.0, 1.0 };
	double mNonSquare[] = { 1, 3, 4, -2,
							3, 2, 1, 3 };
	double nNonSquare[] = { 5, 0, 2,
						   -4, 1, 1,
							2,-1, 0,
							0, 0, 1 };
	double resNonSquare[] = { 1, -1, 3,
							  9,  1, 11 };

	point A(2, 3, -1);
	vector u(4, 2, 1);
	matrix m1(3, 3, m1Data);
	matrix m2(3, 3, m2Data);
	matrix mNS(2, 4, mNonSquare);
	matrix nNS(4, 3, nNonSquare);

	cout << "IsEqual test-----------------------------------\n";
	cout << (IsEqual(m1,m1) ? "Correct" : "Incorrect") << endl << endl;	
	
	cout << "Matrix Product\n-----------------------------------------------\n";
	matrix product = m1 * m2;
	cout << "M1 * M2 = \n";
	product.Print();
	cout << (IsEqual(product, matrix(3, 3, productData)) ? "Correct" : "Incorrect") << endl << endl;

	cout << "NonSquare Matrix Multiply\n------------------------------------------\n";
	matrix NSProd = mNS * nNS;
	cout << "mNonSquare * nNonSquare = \n";
	NSProd.Print();
	cout << (IsEqual(NSProd, matrix(2, 3, resNonSquare)) ? "Correct" : "Incorrect") << endl << endl;

	cout << "Scale\n-----------------------------------------------\n";
	matrix scale = matrix::Scale(5, -2, 4);
	cout << "Scale(5, -2, 4) = \n";
	scale.Print();
	cout << (IsEqual(scale, matrix(4, 4, scaleData)) ? "Correct" : "Incorrect") << endl << endl;

	cout << "X-Rotation\n-----------------------------------------------\n";
	matrix xRot = matrix::RotationX(30);
	cout << "Rot_x(30) = \n";
	xRot.Print();
	cout << (IsEqual(xRot, matrix(4, 4, xRotData)) ? "Correct" : "Incorrect") << endl << endl;

	cout << "Y-Rotation\n-----------------------------------------------\n";
	matrix yRot = matrix::RotationY(30);
	cout << "Rot_y(30) = \n";
	yRot.Print();
	cout << (IsEqual(yRot, matrix(4, 4, yRotData)) ? "Correct" : "Incorrect") << endl << endl;

	cout << "Z-Rotation\n-----------------------------------------------\n";
	matrix zRot = matrix::RotationZ(30);
	cout << "Rot_z(30) = \n";
	zRot.Print();
	cout << (IsEqual(zRot, matrix(4, 4, zRotData)) ? "Correct" : "Incorrect") << endl << endl;

	cout << "Translation\n-----------------------------------------------\n";
	matrix translation = matrix::Translation(-4, -2, 6);
	cout << "Translation(-4, -2, 6) = \n";
	translation.Print();
	cout << (IsEqual(translation, matrix(4, 4, translationData)) ? "Correct" : "Incorrect") << endl << endl;
	
	cout << "Matrix * Point\n------------------------------------------------\n";
	point pointProd = m2 * A;
	cout << "m2 * A = " << pointProd << endl;
	cout << (IsEqual(pointProd, point(-3, 2, -1)) ? "Correct" : "Incorrect") << endl << endl;
	
	cout << "Matrix * Vector\n------------------------------------------------\n";
	vector vectorProd = m2 * u;
	cout << "m2 * u = " << vectorProd << endl;
	cout << (IsEqual(vectorProd, vector(-11, 10, 1)) ? "Correct" : "Incorrect") << endl << endl;
	
	cout << "Matrix Transpose\n------------------------------------------------\n";
	matrix m1Transpose = m1.Transpose();
	cout << "m1.Transpose = \n";
	m1Transpose.Print();
	cout << (IsEqual(m1Transpose, matrix(3, 3, transposeData)) ? "Correct" : "Incorrect") << endl << endl;

	cout << "////////////////////////////////////////////////////////////////\n";
	cout << "// Advanced Operations\n";
	cout << "////////////////////////////////////////////////////////////////\n\n";
	
	cout << "Arbitrary Rotation\n-----------------------------------------------\n";
	matrix arbRot = matrix::Rotation(120, vector(1, 1, 1));
	cout << "Rot(120, <1, 1, 1>) = \n";
	arbRot.Print();
	cout << (IsEqual(arbRot, matrix(4, 4, arbAxisData)) ? "Correct" : "Incorrect") << endl << endl;

	cout << "Matrix Sum\n-----------------------------------------------\n";
	matrix sum = m1 + m2;
	cout << "M1 + M2 = \n";
	sum.Print();
	cout << (IsEqual(sum, matrix(3, 3, sumData)) ? "Correct" : "Incorrect") << endl << endl;

	cout << "Matrix Difference\n-----------------------------------------------\n";
	matrix difference = m1 - m2;
	cout << "M1 - M2 = \n";
	difference.Print();
	cout << (IsEqual(difference, matrix(3, 3, differenceData)) ? "Correct" : "Incorrect") << endl << endl;

	cout << "Matrix Inverse\n------------------------------------------------\n";
	matrix inverse;
	yRot.Inverse(inverse);
	cout << "yRot.Inverse = \n";
	inverse.Print();
	cout << (IsEqual(inverse, matrix(4, 4, inverseData)) ? "Correct" : "Incorrect") << endl << endl;

	cout <<"test mult quaternion question2a"<<endl;
	quat a(2,0,3,-4),b(0,2,-3,0);
	cout <<"result"<<endl;
	cout<< a*b<<endl;

	cout <<"test mult quaternion question2b"<<endl;
	quat a2(1,-1,0,0),b2(1,1,0,0);
	cout <<"result"<<endl;
	cout<< a2*b2<<endl;

	cout <<"test mult quaternion question2c"<<endl;
	quat a3(3,4,2,-1),b3(-2,4,-2,1);
	cout <<"result"<<endl;
	cout<< a3*b3<<endl;
}


void main()
{
	TestMatrices();

	EventLoop();
}

