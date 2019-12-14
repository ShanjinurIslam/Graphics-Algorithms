#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

struct coord
{
    int x;
    int y;
};

void MidpointAlgorithm(coord c0, coord c1)
{
    int dx = c1.x - c0.x;
    int dy = c1.y - c0.y;
    int d = 2 * dy - dx;
    int incrE = 2 * dy;
    int incrNE = 2 * (dy - dx);
    double D, Dup, Ddown;

    int x = c0.x;
    int y = c0.y;

    FILE *sample = fopen("WeightedAreaSampling.dat", "w");

    while (x < c1.x)
    {
        if (d <= 0) //E selected
        {
            x++;

            D = (d + dx) / (2*sqrt(dx * dx + dy * dy));
            Ddown = (d - dx) / (2 * sqrt(dx * dx + dy * dy));
            Dup = (d + 3 * dx) / (2 * sqrt(dx * dx + dy * dy));

            d += incrE;
        }
        else
        {
            x++;
            y++;

            D = (d - dx) / sqrt(dx * dx + dy * dy);
            Ddown = (d - 3*dx) / sqrt(dx * dx + dy * dy);
            Dup = (d + dx) / sqrt(dx * dx + dy * dy);
            //calculation of WeightedAreaSampling would be here
            d += incrNE;
        }

        fprintf(sample, "%lf %lf %lf\n", D,Ddown,Dup);
    }

    fclose(sample);
}

int main()
{
    coord f[2];
    for (int i = 0; i < 2; i++)
    {
        int x, y;
        cin >> x >> y;
        f[i].x = x;
        f[i].y = y;
    }
    MidpointAlgorithm(f[0], f[1]);
    return 0;
}