#include <iostream>
#include <cmath>

using namespace std;

struct constant
{
    double kr;
    double kg;
    double kb;
};

struct intensity
{
    double r;
    double g;
    double b;
};

class Vector
{
public:
    double x, y, z;
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

struct Color
{
    double r;
    double g;
    double b;
};

class PhongModel
{
private:
    intensity Ia;
    intensity Ip;
    constant ka;
    constant kd;
    constant ks;
    Vector incident;
    Vector normal;
    Vector view;

public:
    PhongModel(intensity Ia, intensity Ip, constant ka, constant kd, constant ks, Vector incident, Vector normal, Vector view)
    {
        this->Ia = Ia;
        this->Ip = Ip;
        this->ka = ka;
        this->kd = kd;
        this->ks = ks;
        this->incident = incident;
        this->normal = normal;
        this->view = view;
    }

    intensity getIntesity(Color objectColor, int shiny)
    {
        intensity I;
        double cos_theta = incident.getAngle(normal);
        Vector reflected = incident - (normal * incident.dotProduct(normal)) * 2;
        double cos_phi = reflected.getAngle(view);

        ka.kr = ka.kr * objectColor.r;
        ka.kg = ka.kg * objectColor.g;
        ka.kb = ka.kb * objectColor.b;

        kd.kr = kd.kr * objectColor.r;
        kd.kg = kd.kg * objectColor.g;
        kd.kb = kd.kb * objectColor.b;

        I.r = Ia.r * ka.kr + Ip.r * kd.kr * cos_theta + Ip.r * ks.kr * pow(cos_phi, shiny);
        I.g = Ia.g * ka.kg + Ip.g * kd.kg * cos_theta + Ip.g * ks.kg * pow(cos_phi, shiny);
        I.b = Ia.b * ka.kb + Ip.b * kd.kb * cos_theta + Ip.b * ks.kb * pow(cos_phi, shiny);

        return I;
    }
};

int main()
{
    //choose your input and complete main to test
    //object color input demo [0.7 0.2 0.1]
    return 0;
}