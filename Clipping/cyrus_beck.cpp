#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    double xmin, xmax, ymin, ymax;

    cin >> xmin >> xmax >> ymin >> ymax;

    cout << "Input terminal coordinates : " << endl;
    double x0, y0, x1, y1;

    vector<double> t_values;

    cin >> x0 >> y0 >> x1 >> y1;

    double t1 = (x0 - xmin) / ((-1) * (x1 - x0));
    double t2 = (x0 - xmax) / ((-1) * (x1 - x0));
    double t3 = (y0 - ymin) / ((-1) * (y1 - y0));
    double t4 = (y0 - ymax) / ((-1) * (y1 - y0));

    t_values.push_back(t1);
    t_values.push_back(t2);
    t_values.push_back(t3);
    t_values.push_back(t4);

    sort(t_values.begin(), t_values.end());

    cout << t_values[1] << ' ' << t_values[2] << endl;

    cout << "Clipped points: " << endl;
    cout << x0 + (x1 - x0) * t_values[1]<<" ";
    cout << y0 + (y1 - y0) * t_values[1]<<endl ;

    cout << x0 + (x1 - x0) * t_values[2] << " ";
    cout << y0 + (y1 - y0) * t_values[2] << endl;

    return 0;
}