class Solution {
    void insert(vector<char> &chars, int & index, int count)
    {
        string cnt = to_string(count);
        for(char c : cnt)
        {
            chars[index++] = c;
        }
        return;
    }
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        if(len == 1) return 1;

        int index = 0;
        int count = 0;
        char prev = chars[0];
        for(int i = 0; i < len; i++)
        {
            if(chars[i] == prev)
            {
                count++;
            }
            else
            {
                chars[index++] = prev;
                if(count > 1) 
                {
                    insert(chars, index, count);
                }
                prev = chars[i]; 
                count = 1;
            }
            //printf("Prev : %c, Count : %d, Char : %c, Index : %d\n",prev, count, chars[i], index); 
        }
        chars[index++] = prev;
        if(count > 1) insert(chars, index, count);
        return index;
    }
};
