#ifndef _RGB_TRANSFORM_H
#define _RGB_TRANSFORM_H

#define _USE_MATH_DEFINES
#include <stdlib.h>
#include <math.h>
#include <string>
#include <GL/glut.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include "Drawer.h"
using namespace std;

class Vec3;
class RGBTransform;

//f[^^
struct WaveData{
	int wave_length;	//gˇ
	double refrect;		//˝ËŚ
}typedef WaveData;

class Vec3{
public:
	double x,y,z;
	Vec3():x(0), y(0), z(0){};
	Vec3(double _x, double _y, double _z):x(_x), y(_y), z(_z){};

};

Vec3 operator+(const Vec3 &a, const Vec3 &b);

Vec3 operator*(const double &c, const Vec3 &a);

class Vec4{
public:
	double x,y,z,s;
	Vec4():x(0), y(0), z(0), s(0){};
	Vec4(double _x, double _y, double _z, double _s):x(_x), y(_y), z(_z), s(_s){};
};

class RGBTransform: public Drawer{
	map<int, Vec4 >XYZTable;	//gˇŠçxyzĚĎˇ\
	double K;					//łKťč
	vector<WaveData> data;		//gˇĆ˝ËŚĚf[^
	MyColor RGB;	//FóÔ
	Vec3 XYZ;	//3hl
	double d_lambda;	//dÉ ĎŞvf
public:
	//RGBTransform(string name);
	RGBTransform();
	Vec3 getXYZ();
	MyColor CIE_RGB(Vec3 XYZ);
	MyColor D65_RGB(Vec3 XYZ);

	Vec3 getXYZ(int length, double refrect){
		double _x,_y,_z;
		_x = (XYZTable[length]).x * (XYZTable[length]).s * refrect*d_lambda;	//x(É)*s(É)*R(É)
		_y = (XYZTable[length]).y * (XYZTable[length]).s * refrect*d_lambda;	//y(É)*s(É)*R(É)
		_z = (XYZTable[length]).z * (XYZTable[length]).s * refrect*d_lambda;	//z(É)*s(É)*R(É)
		return Vec3(K*_x, K*_y, K*_z);
	}

	void draw();
};

#endif //_RGB_TRANSFORM_H