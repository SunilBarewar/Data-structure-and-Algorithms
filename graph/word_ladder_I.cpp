#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(targetWord) == dict.end())
            return 0;
        queue<string> q;
        q.push(startWord);
        dict.erase(startWord);
        int dist = 0;
        while (!q.empty())
        {
            int sz = q.size();
            dist++;
            for (int i = 0; i < sz; i++)
            {
                string word = q.front();
                q.pop();

                for(int j = 0; j < word.size();j++){
                    string temp = word;
                    for(char ch = 'a'; ch <= 'z';ch++){
                        temp[j] = ch;
                        auto it  = dict.find(temp);
                        if(targetWord.compare(temp) == 0)
                        return dist+1;
                        if(it != dict.end()){
                            q.push(temp);
                            dict.erase(it);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{

    return 0;
}