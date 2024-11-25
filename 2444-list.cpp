#include<iostream>
#include<vector>
#include<stack>

struct listnode{
    int val;
    listnode* next;
    int depth;
    listnode* parent;
};


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int nums[n][2];
    for(int i=0;i<n;i++)scanf("%d %d",&nums[i][0],&nums[i][1]);
    
    int val,depth=-1;
    bool left=true;
    listnode* pre=NULL;
    while(scanf("%d",&val)){
        depth++;
        if(val==-1){
            if(left){
                left=false;
            }
            else{
                left=true;
                depth--;
            }
        }
        listnode* root=new listnode;
        root->val=val;
        root->next=NULL;
        root->depth=depth;
        if(pre!=NULL){if(left)
            root->parent=pre;
        else
            root->parent=pre->parent;
        }
        pre=root;

    }
    return 0;
}