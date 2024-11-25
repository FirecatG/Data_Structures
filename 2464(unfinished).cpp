#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct treenode {
    int val;
    treenode *left;
    treenode *right;
    bool accessed=false;
    treenode(int x) : val(x), left(NULL), right(NULL) {}
};

treenode* buildFullTree(treenode* root,vector<int> nums,int i){
    if(i>=nums.size()) 
        return NULL;
    root->left = buildFullTree(root->left,nums,2*i);
    root->right = buildFullTree(root->right,nums,2*i+1);
    return new treenode(nums[i]);;
}


void dfs1(treenode* root,vector<int> scanVals,vector<treenode*> accessibles,vector<int> ways[2],vector<int> accessibleVal,bool flag){
    if(root==NULL) return;
    root->accessed=true;
    for(int i=0;i<scanVals.size();i++){
        if(scanVals[i]==root->val){
            scanVals[i]=10001;
        }
    }
    for(int i=0;i<accessibleVal.size();i++){
        if(root->val==accessibleVal[i]){
            accessibles.push_back(root);
            accessibleVal.erase(accessibleVal.begin()+i);
        }
    }
    for(int i=0;i<ways[0].size();i++){
        if(ways[0][i]==root->val){
            accessibleVal.push_back(ways[1][i]);
            ways[0].erase(ways[0].begin()+i);
            ways[1].erase(ways[1].begin()+i);
        }
    }
    
    dfs1(root->left,scanVals,accessibles,ways,accessibleVal,flag);
    dfs1(root->right,scanVals,accessibles,ways,accessibleVal,flag);
}
int main()
{
    int n,val;
    scanf("%d",&n);
    vector<int> nums;
    nums.push_back(-1);
    vector<treenode*> roots;
    for(int i=0;i<n;i++){
        int depth;
        scanf("%d",&depth);
        for(int j=0;j<pow(2,depth)-1;j++){
            scanf("%d",&val);
            nums.push_back(val);
        }
        treenode* root=new treenode(nums[0]);
        roots.push_back(buildFullTree(root,nums,1));
        nums.clear();
        nums.push_back(-1);
    }


    int wayCount=0;
    scanf("%d",&wayCount);
    vector<int> ways[2];
    int t1,t2;
    for(int i=0;i<wayCount;i++){
        scanf("%d,%d",&t1,&t2);
        ways[0].push_back(t1);
        ways[1].push_back(t2);
    }

    int times,scanVal;
    vector<int> scanvals;
    scanf("%d",&times);
    for(int i=0;i<times;i++){
        scanf("%d",&scanVal);
        scanvals.push_back(scanVal);
    }
    vector<treenode*>accessibles;
    vector<int> accessibleVal;

    dfs1(roots[0],scanvals,accessibles,ways,accessibleVal,true);
        while(accessibleVal.size()){
        for(int i=1;i<n;i++)
            dfs1(roots[i],scanvals,accessibles,ways,accessibleVal,false);
    }




    while(accessibles.size()!=0){
        dfs1(accessibles[0],scanvals,accessibles,ways,accessibleVal,true);
        accessibles.erase(accessibles.begin());
    }


    for(int i=0;i<scanvals.size();i++){
        if(scanvals[i]!=10001) printf("Yes\n");
        else printf("No\n");
    }
    return 0;

}
