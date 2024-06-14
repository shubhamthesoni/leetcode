class Solution {
public:
    string predictPartyVictory(string senate) {
      int len = senate.length();
      queue<int> R;
      queue<int> D;
      for(int i = 0; i < len; i++)
      {
        if(senate[i] == 'R') R.push(i);
        else D.push(i);
      }        

      while(!R.empty() && !D.empty())
      {
        int r = R.front(); R.pop();
        int d = D.front(); D.pop();
        if(r < d) R.push(r+len);
        else D.push(d+len);
      }

      return (R.empty())?"Dire":"Radiant";
    }
};
