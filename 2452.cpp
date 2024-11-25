#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
struct treenode {
    int val;
    treenode *left;
    treenode *right;
    treenode(int x) : val(x), left(NULL), right(NULL) {}
};

int nums[7];
int index = 0;
int pos=-1;

void build(treenode *root){
    root->left=new treenode(nums[index++]);
    root->right=new treenode(nums[index++]);
    return;
}

void dfs(treenode *root,int cnt){
    if(root==NULL)
        return;
    
    dfs(root->left,cnt);
    pos++;
    if(pos==7-cnt){
        printf("%d",root->val);
    }
    dfs(root->right,cnt);
    return;
}


void deleteTree(treenode *root){
    if(root==NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main(int argc, char const *argv[])

{

    int cnt;
    for(int i=0;i<7;i++)
        scanf("%d",&nums[i]);
    scanf("%d",&cnt);
    treenode *root=new treenode(nums[index++]);
    build(root);
    build(root->left);
    build(root->right);

    
    dfs(root,cnt);
    
    deleteTree(root);
    return 0;
}
