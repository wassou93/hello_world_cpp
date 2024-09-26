#include <algorithm> // Add this include directive for std::sort
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        auto root = new TrieNode();

        // Populate the TrieNode
        for (const auto& word : words)
        {
            auto node = root;
            for (char c : word)
            {
                if (node->children[c - 'a'] == NULL)
                {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
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
                node = node->children[c - 'a'];
                score += node->score;
            }
            scores.push_back(score);
        }

        // return the vector of scores
        return scores;
    }
private:
    vector<int> scores;
    
private:
    

    struct TrieNode
    {
        TrieNode* children[26];
        int score = 0;
    };

};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
    }();


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
