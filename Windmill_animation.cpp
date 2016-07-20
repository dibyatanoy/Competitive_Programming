#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <utility>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define all(v) v.begin(),v.end()
#define INF 1e8
#define eps 1e-9
#define MAXX 105
#define pi 2*acos(0.0)

using namespace std;

struct point{
    int idx;
    double x,y;
};

struct pt_angle{
    int idx;
    double x,y,theta;

    bool operator <(const pt_angle &p)const{
        return theta<p.theta;
    }
};

int M,S,I;
double init_angle;
vector <point> pts;

vector<pt_angle> sort_by_angle(vector<point> pts, int curr){

    int i,j,k;

    pt_angle tmp;
    vector<pt_angle>ret;

    for(i=0;i<M;i++){

        if(i==curr) continue;

        tmp.idx=pts[i].idx;tmp.x=pts[i].x;tmp.y=pts[i].y;
        double dx=tmp.x-pts[curr].x;
        double dy=tmp.y-pts[curr].y;

        if(fabs(dx-0.0000)<eps) tmp.theta=pi/2;
        else if((dy<0.00 && dx>0.00) || (dy>0.00 && dx<0.00)) tmp.theta=atan(dy/dx)+pi;
        else tmp.theta=atan(dy/dx);

        ret.pb(tmp);

    }
    //for(i=0;i<ret.size();i++) printf("%d %lf %lf %lf\n",ret[i].idx,ret[i].x,ret[i].y,ret[i].theta);
    sort(all(ret));

    return ret;
}

int main(){

    int i,j,k;
    int p;

    cin>>p;

    while(p--){
        scanf("%d %d %d %d %lf",&k,&M,&S,&I,&init_angle);


        pts.clear();
        I--;

        double curr_theta=init_angle*pi/180.0;
        vector<pt_angle> sorted_pt;

        sorted_pt.clear();

        for(i=0;i<M;i++){
            point tmp;
            int ti;
            double tx,ty;

            scanf("%d %lf %lf",&ti,&tx,&ty);

            tmp.x=tx;tmp.y=ty;tmp.idx=ti;
            pts.pb(tmp);

            //cout<<"! "<<i<<" "<<M<<endl;
        }

        int curr_pt=I;

        cout<<k;

        while(S--){

            sorted_pt=sort_by_angle(pts,curr_pt);
            bool fnd=false;
            for(i=0;i<M-1;i++){

                if((sorted_pt[i].theta-curr_theta)>eps){
                    cout<<" "<<sorted_pt[i].idx;
                    curr_pt=sorted_pt[i].idx-1;
                    curr_theta=sorted_pt[i].theta;
                    fnd=true;
                    break;
                }
            }
            if(!fnd){
                curr_theta-=pi;
                for(i=0;i<M-1;i++){

                    if((sorted_pt[i].theta-curr_theta)>eps){
                        cout<<" "<<sorted_pt[i].idx;
                        curr_pt=sorted_pt[i].idx-1;
                        curr_theta=sorted_pt[i].theta;
                        fnd=true;
                        break;
                    }
                }
            }
        }
        cout<<endl;
    }

    return 0;
}

/** AC!!! **/
