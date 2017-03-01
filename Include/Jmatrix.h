// Matrices for rotations in OpenGL

#ifndef __JMATRIX_H__
#define __JMATRIX_H__

typedef double JMatrix[16];
 
void JCopy(JMatrix a, JMatrix b);
void JPrint(JMatrix c, int precision = 1);
void JFastMult(JMatrix c, JMatrix a, JMatrix b);
void JMult(JMatrix c, JMatrix a, JMatrix b);
void JIdentity(JMatrix R);
bool JIsIdentity(const JMatrix &R);
void JMakeRotationX(JMatrix R, double alpha);
void JMakeRotationY(JMatrix R, double alpha);
void JMakeRotationZ(JMatrix R, double alpha);
void JMakeRotation(JMatrix R, double alpha, double u1, double u2, double u3);
void JRotateX(JMatrix R, double alpha);
void JRotateY(JMatrix R, double alpha);
void JRotateZ(JMatrix R, double alpha);
void JRotate(JMatrix R, double alpha, double u1, double u2, double u3);
void JPreRotateX(JMatrix R, double alpha);
void JPreRotateY(JMatrix R, double alpha);
void JPreRotateZ(JMatrix R, double alpha);
void JPreRotate(JMatrix R, double alpha, double u1, double u2, double u3);
void JMakeTranslation(JMatrix R, double x, double y, double z);
void JTranslate(JMatrix R, double x, double y, double z);
void JPreTranslate(JMatrix R, double x, double y, double z);
void JMakeScale(JMatrix R, double sx, double sy, double sz);
void JScale(JMatrix R, double sx, double sy, double sz);
void JPreScale(JMatrix R, double sx, double sy, double sz);
void JEvaluate3(JMatrix R, double *x, double *rx);
void JEvaluate4(JMatrix R, double *x, double *rx);
void JEvaluate(JMatrix R, double x, double y, double z,
               double &rx, double &ry, double &rz);
void JEvaluate(JMatrix R, double x, double y, double &rx, double &ry);

#endif