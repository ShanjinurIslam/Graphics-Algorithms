#include <iostream>
#include <vector>
using namespace std;

struct Color
{
    double r;
    double g;
    double b;

    Color(int r = 0, int g = 0, int b = 0)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }
};

class Polygon
{
    //polygon details needs to be implemented
public:
    Color c;
    Polygon(Color c)
    {
        this->c = c;
    }
    double getDepth(int x, int y)
    {
        //this needs to be implemented
        return -1;
    }
};

class Z_Buffer
{
private:
    int height;
    int width;
    double **depthBuffer;
    Color **framebuffer;
    vector<Polygon> polygons;

public:
    Z_Buffer(int height, int width, vector<Polygon> polygons)
    {
        this->polygons = polygons;
        this->height = height;
        this->width = width;

        *depthBuffer = new double[height];
        for (int i = 0; i < height; i++)
        {
            depthBuffer[i] = new double[width];
        }

        *framebuffer = new Color[height];
        for (int i = 0; i < height; i++)
        {
            framebuffer[i] = new Color[width];
        }
    }

    void calculateZBuffer()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                depthBuffer[i][j] = 255;
                framebuffer[i][j] = Color();
            }
        }

        for (int i = 0; i < polygons.size(); i++)
        {
            for (int x = 0; x < height; x++)
            {
                for (int y = 0; y < width; y++)
                {
                    double depth = polygons[i].getDepth(x, y);
                    if (depth < depthBuffer[x][y])
                    {
                        depthBuffer[x][y] = depth;
                        framebuffer[x][y] = polygons[i].c;
                    }
                }
            }
        }
    }
};

int main()
{
    int height, width;
    cin >> height >> width;

    return 0;
}