#include <algorithm> // Add this include directive for std::sort
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
        int wordCount = words.size();
        std::vector<int> sortedIndices(wordCount);
        for (int i = 0; i < wordCount; i++) {
            sortedIndices[i] = i;
        }
        std::sort(sortedIndices.begin(), sortedIndices.end(),
            [&words](int a, int b) { return words[a] < words[b]; });

        std::vector<int> commonPrefixLengths = calculateCommonPrefixLengths(words, sortedIndices);
        std::vector<int> scores = calculateScores(words, sortedIndices, commonPrefixLengths);
        return scores;
    }

private:
    std::vector<int> calculateCommonPrefixLengths(const std::vector<std::string>& words, const std::vector<int>& sortedIndices) {
        std::vector<int> commonPrefixLengths(words.size(), 0);
        for (int i = 1; i < words.size(); i++) {
            const std::string& prevWord = words[sortedIndices[i - 1]];
            const std::string& currWord = words[sortedIndices[i]];
            int commonLength = 0;
            while (commonLength < prevWord.length() &&
                commonLength < currWord.length() &&
                prevWord[commonLength] == currWord[commonLength]) {
                commonLength++;
            }
            commonPrefixLengths[i] = commonLength;
        }
        return commonPrefixLengths;
    }

    std::vector<int> calculateScores(const std::vector<std::string>& words, const std::vector<int>& sortedIndices, const std::vector<int>& commonPrefixLengths) 
    {
        std::vector<int> scores(words.size(), 0);
        for (int i = 0; i < sortedIndices.size(); i++) 
        {
            int wordIndex = sortedIndices[i];
            int wordLength = words[wordIndex].length();
            scores[wordIndex] += wordLength;
            int j = i + 1;
            int commonLength = wordLength;
            while (j < words.size()) 
            {
                commonLength = std::min(commonLength, commonPrefixLengths[j]);
                if (commonLength == 0) 
                {
                    break;
                }
                scores[wordIndex] += commonLength;
                scores[sortedIndices[j]] += commonLength;
                j++;
            }
        }
        return scores;
    }
};
static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
    }();

//KDS Appraoch 1

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
