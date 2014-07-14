class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0){
            return 0;
        }
        int* ptail = A+(n-1);
        int* phead = A;
        if(n==1){
            if(A[0]==elem){
                return 0;
            }else{
                return 1;
            }
        }/*
        while(*ptail!=elem){
            ptail--;
            
        }*/
        while(phead<ptail){
            if(*phead==elem){
                while(ptail>phead&&*ptail==elem){
                    ptail--;
                }
                int tp = *ptail;
                *ptail = *phead;
                *phead = tp;
            }else{
                phead++;
            }
        }
        return phead-A+(*ptail!=elem);
    }
};