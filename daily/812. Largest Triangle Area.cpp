#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm> // for std::max

using namespace std;

double CalcDistance(vector<int> &a, vector<int> &b)
{
    return sqrt(pow(a[0] - a[1], 2) + pow(b[0] - b[1], 2));
}
double calcArea(double a, double b) { return 0.5 * a * b; }

double largestTriangleArea(vector<vector<int>> &points)
{
    double maxNumber = 0;
    int index = 0;
    for (int k = 0; k < points.size(); k++)
    {
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                if (i != j && j != k && k != i)
                {
                    vector<int> a = points[k];
                    vector<int> b = points[i];
                    vector<int> c = points[j];
                    double area = 0.5 * abs(
                                            a[0] * (b[1] - c[1]) +
                                            b[0] * (c[1] - a[1]) +
                                            c[0] * (a[1] - b[1]));
                    maxNumber = max(area, maxNumber);
                }
            }
        }
    }

    return maxNumber;
}
int main()
{
    vector<vector<int>> nums{{4, 6}, {6, 5}, {3, 1}};
    cout
        << largestTriangleArea(nums);
}