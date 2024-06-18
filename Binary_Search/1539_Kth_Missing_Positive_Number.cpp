class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int index = 0;
        int count = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if((arr[i] - count - 1) >= k ) return count + k;
            else {  k -= (arr[i] - count - 1); count = arr[i]; }
            printf("loop count : %d, k : %d\n", count, k);
            /*
            while((count < (arr[i]-1))) 
            { 
                count++; 
                k--;
                if(k==0) return count;
            }
            */
            //printf("After loop count : %d, k : %d\n", count, k);
            //count = arr[i];
            //printf("End loop count : %d, k : %d\n", count, k);
        }
        if(k > 0) count += k;
        //while(k>0) { count++; k--;}
        //printf("Exit count : %d, k : %d\n", count, k);
        return count;
    }
};
