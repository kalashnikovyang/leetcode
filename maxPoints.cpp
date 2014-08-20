/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        if(n < 3) return n; //less than 3 points, return size
        
        int i, j;
        int max = 0;
        // traverse every point, record maximum points if including the point -> localmax
        map<double, int> slope;
        for(i=0;i<n;i++)
        {
            slope.clear(); //ensure not effected by prior points
            int localMax = 0;
            int dul = 0, vertical = 0; //duplicate points and vertical -> y cooridnate equals
            for(j=0;j<n;j++)
            {
                if(i == j) continue;
                
                double x = points[i].x - points[j].x;
                double y = points[i].y - points[j].y;
                
                if(x == 0 && y == 0)
                {
                    dul++;
                    continue;
                }
                if(x == 0)
                {
                    vertical++;
                    if(vertical > localMax) localMax = vertical;
                    continue;
                }
                
                double sl = y/x;
                slope[sl]++;
                
                if(slope[sl] > localMax) localMax = slope[sl];
            }
            int temp = localMax + dul + 1; //including same points and point itself
            if(temp > max) max = temp;
        }
        
        return max;
    }
};