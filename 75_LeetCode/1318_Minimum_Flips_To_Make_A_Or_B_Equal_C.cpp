class Solution {
public:
    int minFlips(int a, int b, int c) {
        int r = (a | b) ^ c;
        int count = 0;
        cout << r << endl;
        while(r)
        {
           if(r&1)
           {
              count += a&1;
              count += b&1;
              if(((a&1) == 0)&&((b&1)==0)) count++;
           }
           r>>=1; a>>=1; b>>=1;
        }
        return count;
    }
};
