#include <bits/stdc++.h>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define all(v) v.begin(),v.end()
#define MAXX 110

using namespace std;

struct data{
    int x,y,time;
};

char grid[MAXX][MAXX];
bool is_laser[MAXX][MAXX][4];
bool vis[MAXX][MAXX][4];
int M,N,end_x,end_y,dist[MAXX][MAXX][4];
int x[]={0,1,0,-1};
int y[]={-1,0,1,0};

void mark(int r,int c,int dir){

    int rot,i,j,k;
    int new_x,new_y;

    for(rot=0;rot<4;rot++){
        for(i=1;;i++){
            new_x=c+i*x[(dir+rot)%4];
            new_y=r+i*y[(dir+rot)%4];

            if(new_x>=0 && new_x<N && new_y>=0 && new_y<M && grid[new_y][new_x]!='#' && grid[new_y][new_x]!='^' && grid[new_y][new_x]!='>' && grid[new_y][new_x]!='v' && grid[new_y][new_x]!='<'){
                is_laser[new_y][new_x][rot]=1;
            }else break;
        }
    }
    return;
}

bool valid(int new_x,int new_y){
    if(new_x>=0 && new_x<N && new_y>=0 && new_y<M && grid[new_y][new_x]!='#' && grid[new_y][new_x]!='^' && grid[new_y][new_x]!='>' && grid[new_y][new_x]!='v' && grid[new_y][new_x]!='<')
        return 1;
    else return 0;
}

int bfs(int st_x,int st_y){
    queue<data> Q;

    //if(is_laser[st_y][st_x][0]==1) return 0;

    vis[st_x][st_y][0]=1;
    dist[st_x][st_y][0]=0;
    data tmp;
    tmp.x=st_x;tmp.y=st_y;tmp.time=0;
    Q.push(tmp);

    int i,j,k;

    while(!Q.empty()){
        data u=Q.front();Q.pop();

        if(u.x==end_x && u.y==end_y) return dist[u.y][u.x][u.time];

        for(i=0;i<4;i++){
            int new_x=u.x+x[i];
            int new_y=u.y+y[i];

            if(valid(new_x,new_y) && !vis[new_y][new_x][(u.time+1)%4] && !is_laser[new_y][new_x][(u.time+1)%4]){
                vis[new_y][new_x][(u.time+1)%4]=1;
                dist[new_y][new_x][(u.time+1)%4]=1+dist[u.y][u.x][u.time];
                tmp.x=new_x;
                tmp.y=new_y;
                tmp.time=(u.time+1)%4;
                Q.push(tmp);
            }
        }
    }

    return -1;
}

int main(){

    int i,j,k;
    int kases,t;

    freopen("laser_maze.txt","r",stdin);
    freopen("Laser_Maze_out.txt","w",stdout);

    scanf("%d",&kases);

    for(t=1;t<=kases;t++){
        scanf("%d %d",&M,&N);
        for(i=0;i<M;i++) scanf("%s",grid[i]);

        CLR(is_laser);CLR(vis);CLR(dist);

        int s_x,s_y;

        for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                if(grid[i][j]=='^'){
                    mark(i,j,0);

                }else if(grid[i][j]=='>'){
                    mark(i,j,1);
                }else if(grid[i][j]=='v'){
                    mark(i,j,2);
                }else if(grid[i][j]=='<'){
                    mark(i,j,3);
                }else if(grid[i][j]=='G'){
                    end_x=j;
                    end_y=i;
                }else if(grid[i][j]=='S'){
                    s_x=j;
                    s_y=i;
                }
            }
        }

        /*for(i=0;i<M;i++){
            for(j=0;j<N;j++){
                if(is_laser[i][j][0]) printf("0 ");
                else if(is_laser[i][j][1]) printf("1 ");
                else if(is_laser[i][j][2]) printf("2 ");
                else if(is_laser[i][j][3]) printf("3 ");
                else printf("-1 ");
            }
            printf("\n");
        }*/

        int ans=bfs(s_x,s_y);
        if(ans>=0) printf("Case #%d: %d\n",t,ans);
        else printf("Case #%d: impossible\n",t);
    }

    return 0;
}
