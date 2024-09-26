#include <algorithm> // Add this include directive for std::sort
#include <iostream>
#include <unordered_map>

using namespace std;

class trie {
public:
    int x;
    trie* v[26];
};
void maketrie(string str, trie* node) {
    for (auto& i : str) {
        if (node->v[i - 'a'] == NULL) {
            node->v[i - 'a'] = new trie();
            node = node->v[i - 'a'];
            node->x = node->x + 1;
        }
        else {
            node = node->v[i - 'a'];
            node->x = node->x + 1;
        }
    }
}
void solve(string str, trie* node, int& x) {
    trie* p = node;
    for (auto& i : str) {
        p = p->v[i - 'a'];
        x += p->x;
    }
}
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trie* node = new trie();
        for (auto& i : words) {
            maketrie(i, node);
        }
        int x = 0;
        vector<int> ans;
        for (auto& i : words) {
            x = 0;
            solve(i, node, x);
            ans.push_back(x);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<std::string> words = { "abc","ab","bc","b" };
    vector<int> scores = s.sumPrefixScores(words);
    for (const auto& score : scores)
    {
        std::cout << score << " ";
    }
    std::cout << endl;
}
