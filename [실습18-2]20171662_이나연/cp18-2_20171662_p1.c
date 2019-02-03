#include <stdio.h>
#include <math.h>
#include <string.h>

typedef float* Vector_Comp;
typedef float Comp;

typedef struct {
	Vector_Comp comps;
	int vec_size;
}Vector;

typedef float Distance;
typedef float Scalar;
typedef float Size;

Distance DistVector(Vector v1, Vector v2);
Scalar innerProduct(Vector v1, Vector v2);
Size vectorSize(Vector v);


int main(void)
{
	Vector v1, v2;
	int i;

	scanf("%d", &v1.vec_size);

	v1.comps = (Vector_Comp)malloc(sizeof(Comp)*v1.vec_size);

	for (i = 0;i < v1.vec_size;i++)
	{
		scanf("%f", &v1.comps[i]);
	}

	scanf("%d", &v2.vec_size);

	v2.comps = (Vector_Comp)malloc(sizeof(Comp)*v2.vec_size);

	for (i = 0;i < v2.vec_size;i++)
	{
		scanf("%f", &v2.comps[i]);
	}

	printf("%.2f\n", vectorSize(v1));
	printf("%.2f\n", vectorSize(v2));

	if (v1.vec_size == v2.vec_size)
	{
		printf("%.3f\n", DistVector(v1,v2));
		printf("%f\n", innerProduct(v1,v2));
	}

	return 0;
}

Distance DistVector(Vector v1, Vector v2)
{
	int i;
	float bdist=0, temp=0;

	for (i = 0;i < v1.vec_size;i++)
	{
		temp = v2.comps[i] - v1.comps[i];
		temp *= temp;
		bdist += temp;
	}

	return sqrt(bdist);
}

Scalar innerProduct(Vector v1, Vector v2)
{
	int i;
	float temp=0, prod=0;

	for (i = 0;i < v1.vec_size;i++)
	{
		temp = v1.comps[i] * v2.comps[i];
		prod += temp;
	}

	return prod;
}

Size vectorSize(Vector v)
{
	float bsize=0, temp=0;
	int i;

	for (i = 0;i < v.vec_size;i++)
	{
		temp = v.comps[i] * v.comps[i];
		bsize += temp;
	}

	return sqrt(bsize);
}