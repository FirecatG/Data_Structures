#include<iostream>
#include<vector>
#include<stack>

int n;
std::vector<int> xs,ys,xp,yp,xDepth,yDepth;



 void build(int depth,int parentVal){
    int val;
    if(scanf("%d",&val)!=EOF)
    {
        if(val==-1)
            return ;
        for(int i=0;i<n;i++){
            if(val==xs[i]){
                xDepth[i]=depth;
                xp[i]=parentVal;
            }
            if(val==ys[i]){
                yDepth[i]=depth;
                yp[i]=parentVal;
            }
        }

        build(depth+1,val);
        build(depth+1,val);
        
        
    }
    return ;
 }



int main(int argc, char const *argv[])
{
    scanf("%d",&n);

    xs.resize(n);
    ys.resize(n);
    xp.resize(n);
    yp.resize(n);
    xDepth.resize(n);
    yDepth.resize(n);

    for(int i=0;i<n;i++)scanf("%d %d",&xs[i],&ys[i]);

    build(0,-1);
    for(int i=0;i<n;i++){
        if(xp[i]!=yp[i]&&xDepth[i]==yDepth[i])
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
