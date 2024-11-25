#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<iostream>
using namespace std;
int getMax(vector<vector<int>>& lake,int i,int j){
    if(i<0 || i>= lake.size() || j<0 || j>=lake[0].size() || lake[i][j]==0) return 0;
    int num=lake[i][j];
    lake[i][j]=0;
    num+=getMax(lake,i+1,j);
    num+=getMax(lake,i-1,j);
    num+=getMax(lake,i,j+1);
    num+=getMax(lake,i,j-1);
    return num;
}
int main()
{
    int m,n,ans=0;
    cin >> m >> n;
    vector<vector<int>> lake(m,vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> lake[i][j];
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(lake[i][j] != 0)
                ans = max(getMax(lake,i,j),ans);
        }
    }
    printf("%d",ans);
    return 0;
}
