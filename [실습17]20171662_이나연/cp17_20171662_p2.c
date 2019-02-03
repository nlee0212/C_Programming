#include <stdio.h>
#include <math.h>

typedef struct {
	double x;
	double y;
	double z;
	double r;
} sphere;

double Distance(sphere, sphere);
double CrossSectionArea(sphere, sphere);
double SurfaceArea(sphere, sphere);
double Volume(sphere, sphere);

int main(void)
{
	sphere ball1, ball2;
	
	printf("Type First Sphere Coordinate : ");
	scanf("%lf %lf %lf", &ball1.x, &ball1.y, &ball1.z);

	printf("Type First Sphere Radius : ");
	scanf("%lf", &ball1.r);

	printf("Type Second Sphere Coordinate : ");
	scanf("%lf %lf %lf", &ball2.x, &ball2.y, &ball2.z);

	printf("Type Second Sphere Radius : ");
	scanf("%lf", &ball2.r);

	if (Distance(ball1, ball2) > ball1.r + ball2.r)
	{
		printf("Sum of Cross Section Area : %.2lf\n", CrossSectionArea(ball1, ball2));
	}

	if (Distance(ball1, ball2) == ball1.r + ball2.r)
	{
		printf("Sum of Surface Area : %.2lf\n", SurfaceArea(ball1, ball2));
	}

	if (Distance(ball1, ball2) < ball1.r + ball2.r)
	{
		printf("Sum of Volume : %.2lf\n", Volume(ball1, ball2));
	}

	return 0;
}

double Distance(sphere a, sphere b)
{
	double dis;

	dis = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));

	return dis;
}

double CrossSectionArea(sphere a, sphere b)
{
	double area1, area2;

	area1 = 3.14*a.r*a.r;
	area2 = 3.14*b.r*b.r;

	return area1 + area2;
}

double SurfaceArea(sphere  a, sphere b)
{
	double area1, area2;

	area1 = 4 * 3.14*a.r*a.r;
	area2 = 4 * 3.14*b.r*b.r;

	return area1 + area2;
}

double Volume(sphere a, sphere b)
{
	double v1, v2;

	v1 = (4.0 / 3.0) * 3.14*a.r*a.r*a.r;
	v2 = (4.0 / 3.0) * 3.14*b.r*b.r*b.r;

	return v1 + v2;
}
