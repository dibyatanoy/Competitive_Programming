#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <set>
#include <map>
#include <utility>
#define eps 1e-9

using namespace std;

struct point{
    double x,y;
};

struct line{
    double slope, y_intercept;
    bool inf_slope;

    line(point i, point j){
        if(fabs(i.x-j.x)<eps) inf_slope=1;
        else{
            inf_slope=0;
            slope=(i.y-j.y)/(i.x-j.x);
            y_intercept=i.y-slope*i.x;
        }
    }

    line(double a, double b){       //overloading
        inf_slope=0;
        slope=a;
        y_intercept=b;
    }
};

int main(){

    int i,j;
    point p,q;
    scanf("%lf %lf %lf %lf",&p.x,&p.y,&q.x,&q.y);

    line l1(p,q);
    line l2(l1.slope,l1.y_intercept);

    printf("%lf %lf %lf %lf\n",l1.slope,l1.y_intercept,l2.slope,l2.y_intercept);

    return 0;
}
