#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& words) {
    unordered_map<string, vector<string>> anagrams;
    
    // Group words by their sorted version
    for (const string& word : words) {
        string sorted_word = word;
        sort(sorted_word.begin(), sorted_word.end());
        anagrams[sorted_word].push_back(word);
    }
    
    // Collect all groups of anagrams
    vector<vector<string>> result;
    for (auto& entry : anagrams) {
        sort(entry.second.begin(), entry.second.end());
        result.push_back(entry.second);
    }
    
    return result;
}

int main() {
    vector<string> words = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> groupedAnagrams = groupAnagrams(words);
    
    for (const auto& group : groupedAnagrams) {
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}
