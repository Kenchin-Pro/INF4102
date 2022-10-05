#include "vector.hh"
#include <iostream>
#include <cmath>

using namespace std;

bool operator == (const Vector& a, const& b)
{
	Vector t = a - b;
	float epsilon = 0.001f;
	return t.norm() < epsilon;
}

Vector operator + ( const Vector & a, const Vector & b)
{
	int t1 = sizeof(a.coor);
	int t2 = sizeof(b.coor);
	value[] retT = new value[NDIM];
	for (int i = 0, i < t1, i++)
	{
		retT[i] = a.coor[i] + b.coor[i];
	}
	return retT;
}

Vector operator - (const Vector& a, const Vector& b)
{
	int t1 = sizeof(a.coor);
	int t2 = sizeof(b.coor);
	value[] retT = new value[NDIM];
	for (int i = 0, i < t1, i++)
	{
		retT[i] = a.coor[i] - b.coor[i];
	}
	return retT;
}

Vector operator * (float a, const Vector& b)
{
	int t1 = sizeof(b.coor);
	value[] retT = new value[NDIM];
	for (int i = 0, i < t1, i++)
	{
		retT[i] = a * b.coor[i];
	}
	return retT;
}

Vector operator * (const Vector & a, float b)
{
	int t1 = sizeof(a.coor);
	value[] retT = new value[NDIM];
	for (int i = 0, i < t1, i++)
	{
		retT[i] = a.coor[i] * b;
	}
	return retT;
}

float operator * (const Vector& a, const Vector& b)
{
	float retF = 0.0f;
	int t1 = sizeof(a.coor);
	for (int i = 0; i < t1; i++)
	{
		retF = a.coor[i] * b.coor[i];
	}
	return retF;
}

/*std::ostream& operator << (std::ostream& os, Vector& a)
{
	string retS;
	int t1 = sizeof(a.coor);
	for (int i = 0; i < t1; i++)
	{
		retS = a.coor[i];
	}
}*/