#include <iostream>
#include <vector>

using namespace std;

struct coord
{
    double x;
    double y;
};

int main()
{
    vector<coord> vertices;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;

        coord c;
        c.x = x;
        c.y = y;
        vertices.push_back(c);
    }

    cout << "Enter clip edges" << endl;

    double xmin, xmax, ymin, ymax;
    cin >> xmin >> xmax >> ymin >> ymax;

    vector<coord> output;
    coord s, p;

    s = vertices[n - 1];
    p = vertices[0];
    int j = 0;
    while (j < n)
    {
        if (s.x >= xmin && p.x >= xmin)
        {
            output.push_back(p);
        }
        else if (s.x < xmin && p.x >= xmin)
        {
            coord in;
            in.x = xmin;
            in.y = s.y + ((s.y - p.y) / (s.x - p.x)) * (xmin - s.x);
            output.push_back(in);
            output.push_back(p);
        }

        else if (s.x >= xmin && p.x < xmin)
        {
            coord in;
            in.x = xmin;
            in.y = s.y + ((s.y - p.y) / (s.x - p.x)) * (xmin - s.x);
            output.push_back(in);
        }
        else
        {
            //
        }
        s = vertices[j];
        p = vertices[j + 1];
        j++;
    }

    vertices = output;
    output.clear();

    s = vertices[n - 1];
    p = vertices[0];
    j = 0;
    while (j < n)
    {
        if (s.x <= xmax && p.x <= xmax)
        {
            output.push_back(p);
        }
        else if (s.x > xmax && p.x <= xmax)
        {
            coord in;
            in.x = xmax;
            in.y = s.y + ((s.y - p.y) / (s.x - p.x)) * (xmax - s.x);
            output.push_back(in);
            output.push_back(p);
        }

        else if (s.x <= xmax && p.x > xmax)
        {
            coord in;
            in.x = xmax;
            in.y = s.y + ((s.y - p.y) / (s.x - p.x)) * (xmax - s.x);
            output.push_back(in);
        }
        else
        {
            //
        }
        s = vertices[j];
        p = vertices[j + 1];
        j++;
    }

    s = vertices[n - 1];
    p = vertices[0];
    j = 0;
    while (j < n)
    {
        if (s.y >= ymin && p.y >= ymin)
        {
            output.push_back(p);
        }
        else if (s.y < ymin && p.y >= ymin)
        {
            coord in;
            in.y = ymin;
            in.x = s.x + ((s.x - p.x) / (s.y - p.y)) * (ymin - s.y);
            output.push_back(in);
            output.push_back(p);
        }

        else if (s.y >= ymin && p.x < ymin)
        {
            coord in;
            in.y = ymin;
            in.x = s.x + ((s.x - p.x) / (s.y - p.y)) * (ymin - s.y);
            output.push_back(in);
        }
        else
        {
            //
        }
        s = vertices[j];
        p = vertices[j + 1];
        j++;
    }

    vertices = output;
    output.clear();

    s = vertices[n - 1];
    p = vertices[0];
    j = 0;
    while (j < n)
    {
        if (s.y <= ymax && p.y <= ymax)
        {
            output.push_back(p);
        }
        else if (s.y > xmax && p.y <= xmax)
        {
            coord in;
            in.y = ymax;
            in.x = s.x + ((s.x - p.x) / (s.y - p.y)) * (ymin - s.y);
            output.push_back(in);
            output.push_back(p);
        }

        else if (s.y <= ymax && p.y > ymax)
        {
            coord in;
            in.y = ymax;
            in.x = s.x + ((s.x - p.x) / (s.y - p.y)) * (ymin - s.y);
            output.push_back(in);
        }
        else
        {
            //
        }
        s = vertices[j];
        p = vertices[j + 1];
        j++;
    }


    //output is the result 

    return 0;
}