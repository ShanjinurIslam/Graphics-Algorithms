#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point
{
    double x, y, z;
};

class Vector
{
public:
    double x, y, z;

    Vector(Point p1, Point p2)
    {
        this->x = p2.x - p1.x;
        this->y = p2.y - p1.y;
        this->z = p2.z - p1.z;
    }

    Vector(int x = 0, int y = 0, int z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector operator*(double a)
    {
        Vector v;
        v.x = this->x * a;
        v.y = this->y * a;
        v.z = this->z * a;

        return v;
    }

    Vector operator-(Vector a)
    {
        Vector v;
        v.x = this->x - a.x;
        v.y = this->y - a.y;
        v.z = this->z - a.z;

        return v;
    }

    double abs()
    {
        return sqrt(x * x + y * y + z * z);
    }

    double dotProduct(Vector a)
    {
        return a.x * this->x + a.y * this->y + a.z * this->z;
    }

    double getAngle(Vector a)
    {
        return this->dotProduct(a) / (this->abs() * a.abs);
    }
};

class BackfaceCulling
{
public:
    Point COP ;
    vector<Point> pointOnPlane;
    vector<Vector> normalVectors;

    BackfaceCulling(Point COP,vector<Point> pointOnPlane, vector<Vector> normalVectors)
    {
        this->COP = COP ;
        this->pointOnPlane = pointOnPlane ;
        this->normalVectors = normalVectors;
    }

    vector<bool> drawable()
    {
        vector<bool> d;
        for (int i = 0; i < normalVectors.size(); i++)
        {
            Vector direction(pointOnPlane[i],COP);
            double cos_theta = direction.dotProduct(normalVectors[i]);
            if (cos_theta < 0)
            {
                d.push_back(true);
            }
            else
            {
                d.push_back(false);
            }
        }
        return d;
    }
};

int main()
{
    //complete main to test
    return 0;
}