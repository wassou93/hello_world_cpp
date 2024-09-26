#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        auto root = make_shared<TrieNode>();

        // Populate the TrieNode
        for (const auto& word : words)
        {
            auto node = root;
            for (char c : word)
            {
                if (node->childrens.find(c) == node->childrens.end())
                {
                    node->childrens[c] = make_shared<TrieNode>();
                }
                node = node->childrens[c];
                node->score += 1;
            }
        }

        // calculate scores
        scores.reserve(words.size());
        for (const auto& word : words)
        {
            auto node = root;
            int score = 0;
            for (char c : word)
            {
                node = node->childrens[c];
                score += node->score;
            }
            scores.push_back(score);
        }

        // return the vector of scores
        return scores;
    }
private:
    vector<int> scores;
    
    struct TrieNode 
    {
        unordered_map<char, shared_ptr<TrieNode>> childrens;
        int score = 0;
    };

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

