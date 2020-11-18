/*
    ��̬�滮
    3.�ж��ַ����Ƿ����Ӵ�����
    
    ����һ���ַ���S�Լ�һ���ֵ�dict���ж�S�Ƿ������dict���
*/
#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        auto wordDictSet = unordered_set<string>();
        for (auto word : wordDict)
        {
            wordDictSet.insert(word);
        }

        auto dp = vector<bool>(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

vector<string> split(const string &s)
{
    vector<string> result;
    istringstream str(s);	
	string out;

	while (str >> out) {
        result.push_back(out);
    }

    return result;
}

int main(int argc, char const *argv[])
{

    //��ʼ�ַ���
    string str;
    getline(cin, str);

    //�ֵ�
    string dict;
    //cin>>pattern;
    getline(cin, dict); //���ڻ�ȡ���ո���ַ���

    vector<string> dictWord = split(dict);

    // for (int i = 0; i < dictWord.size(); i++)
    // {
    //     cout << dictWord[i] << endl;
    //     cout << dictWord[i].size() << endl;
    // }

    Solution s1;

    bool fin = s1.wordBreak(str, dictWord);
    if (fin == 1)
        cout << "true";
    if (fin == 0)
        cout << "false";

    return 0;
}

