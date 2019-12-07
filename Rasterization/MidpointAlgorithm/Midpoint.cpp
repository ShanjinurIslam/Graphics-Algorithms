#include <iostream>
#include <cstdlib>

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

    int x = c0.x;
    int y = c0.y;

    FILE *midpoint = fopen("midpoint.dat", "w");

    while (x < c1.x)
    {
        cout << d << endl;
        if (d <= 0) //E selected
        {
            d += incrE;
            x++;
        }
        else
        {
            d += incrNE;
            x++;
            y++;
        }
        fprintf(midpoint, "%d %d \n", x, y);
    }

    fclose(midpoint);
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
    FILE *fout = fopen("input.dat", "w");
    fprintf(fout, "%d %d \n", f[0].x, f[0].y);
    fprintf(fout, "%d %d \n", f[1].x, f[1].y);
    fclose(fout);
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "set terminal jpeg\n");
    fprintf(gnuplotPipe, "set output 'output.jpeg'\n");
    fprintf(gnuplotPipe, "plot 'input.dat' pointsize 1.3 linecolor 4 with linespoint,'midpoint.dat' pointsize 1.5 linecolor 1 with linespoint\n");
    fclose(gnuplotPipe);
    return 0;
}