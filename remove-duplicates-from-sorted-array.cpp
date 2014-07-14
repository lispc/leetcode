class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0)
            return 0;
        int * head = A;
        int * tail = A;
        int now = A[0];
        while(1)
        {
            while(tail<A+n&&*tail==*head)
                tail++;
            if(tail>=A+n)
                return head-A+1;
            else
            {
                *++head=*tail;
            }
        }
    }
};