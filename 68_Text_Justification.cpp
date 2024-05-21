class Solution {
    string indent(string & s, int len, int word_count, int maxWidth, bool lastLine)
    {
        string result;
        //cout << s << " With word_count "<<word_count<<endl;
        if((word_count == 1) || (lastLine)) { string temp((maxWidth - len),' '); return s.append(temp); }
        int space_to_be_added = maxWidth - len;
        int extra_space = space_to_be_added % (word_count - 1 );
        int each_space = space_to_be_added / (word_count - 1);
        //cout << "Need to add space of width "<<each_space << " with first of len " <<(extra_space + each_space) << endl;
        stringstream ss(s);
        string words;
        string temp(each_space+1, ' ');
        while(ss >> words)
        {
            result.append(words);
            word_count--;
            if(word_count) result.append(temp);
            if(extra_space) {result.push_back(' '); extra_space--;}
        }
        return result;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> R;
        vector<int> L;
        int len = words.size();
        string line = "";
        int line_len = 0;
        int word_count = 0;
        int word_len = 0;
        for(int i = 0; i < len; i++)
        {
            word_len = words[i].length();
            //cout << word_len << " " << line_len << endl;
            if(line_len == 0) { line.append(words[i]); line_len = word_len; word_count = 1;}
            else if((line_len + 1 + word_len) <= maxWidth)
            {
                line.push_back(' ');
                line.append(words[i]); 
                line_len += (1+word_len);
                word_count++;
            }
            else
            {
              line = indent(line, line_len, word_count, maxWidth, false);
              R.push_back(line);
              line = "";
              line.append(words[i]); line_len = word_len; word_count = 1; 
            }
        }
        if(line_len) { line = indent(line, line_len, word_count, maxWidth, true);  R.push_back(line); }
        return R;
    }
};
