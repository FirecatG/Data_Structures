#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


bool opr(int* popped,int n) {
        stack<int> st;
        for (int i = 0, j = 0; i < n; i++) {
            st.push(i+1);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }


int main()
{
    int n,k,i,j;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d",&n);
        int nums[n];
        for(j=0;j<n;j++)scanf("%d",&nums[j]);
        bool ans=opr(nums,n);
        if(ans) printf("Yes\n");
        else printf("No\n");


           }
           return 0;
}
