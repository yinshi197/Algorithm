#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int px[5],py[5];
int n,m,q;
int a[maxn][maxn],p[maxn][maxn];
void dfs(int x,int y,int color){
    p[x][y]=color;
    for(int i=0;i<4;i++){
        int nx=x+px[i],ny=y+py[i];
        if(nx<n&&nx>0&&ny<m&&ny>0&&!p[nx][ny]){
            if(a[x][y]!=a[nx][ny])
                dfs(nx,ny,color);
        }
    }
}
int main(){
    px[0]=0;px[1]=0;px[2]=1;px[3]=-1;
    py[0]=1;py[1]=-1;py[2]=0;py[3]=0;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    int color=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!p[i][j])dfs(i,j,++color);
        }
    }
    
    for(int x1,yl,x2,y2,i=1;i<=q;i++){
        cin>>x1>>yl>>x2>>y2;
        if(p[x1][yl]==p[x2][y2])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}