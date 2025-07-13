#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());

        while(!q.empty()){
            string s=q.front().first;
            int count=q.front().second;
            q.pop();

            if(s==endWord){
                return count;
            }

            for(int i=0;i<s.length();i++){
                string temp=s;
                // Try changing each character to every letter from 'a' to 'z'
                for(char c='a';c<='z';c++){
                    temp[i]=c;
                    if(st.count(temp)){
                        q.push({temp,count+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};