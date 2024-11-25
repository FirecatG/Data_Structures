#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct treenode{
    int val;
    treenode *left;
    treenode *right;
    treenode(int x) : val(x), left(NULL), right(NULL) {}
};

treenode* merge(treenode* root,treenode* newNode){
    if(root==NULL) return newNode;
    if(newNode==NULL) return root;
    root->val+=newNode->val;
    if(root->val<newNode->val){
        root->right=merge(root->right,newNode);
    }else{
        root->left=merge(root->left,newNode);
    }
}

treenode* hafmanTree(vector<int> nums){
    treenode* root=new treenode(nums[0]);
    for(int i=1;i<nums.size();i++){
        treenode* newNode=new treenode(nums[i]);
        root=merge(root,newNode);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    treenode* root=hafmanTree(nums);
    cout << root->val;



    return 0;
}
