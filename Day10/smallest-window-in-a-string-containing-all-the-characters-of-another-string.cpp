#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

string smallestWindow(string s, string p) {
    if (s.empty() || p.empty()) return "-1";

    unordered_map<char, int> charCountP, charCountWindow;
    int required = 0, formed = 0, l = 0, r = 0, minLength = INT_MAX;
    string result = "";

    // Create a frequency map for characters in P
    for (char c : p) {
        charCountP[c]++;
    }
    required = charCountP.size();

    // Start sliding window
    while (r < s.size()) {
        char c = s[r];
        charCountWindow[c]++;

        // Check if current window contains all characters of P
        if (charCountP.find(c) != charCountP.end() && charCountWindow[c] == charCountP[c]) {
            formed++;
        }

        // Contract the window from the left
        while (l <= r && formed == required) {
            c = s[l];
            if (r - l + 1 < minLength) {
                minLength = r - l + 1;
                result = s.substr(l, minLength);
            }
            charCountWindow[c]--;
            if (charCountP.find(c) != charCountP.end() && charCountWindow[c] < charCountP[c]) {
                formed--;
            }
            l++;
        }

        r++;
    }

    return result.empty() ? "-1" : result;
}

int main() {
    string s1 = "timetopractice";
    string p1 = "toc";
    string s2 = "zoomlazapzo";
    string p2 = "oza";

    cout << "Smallest window for s = \"" << s1 << "\" and p = \"" << p1 << "\" is " << smallestWindow(s1, p1) << endl;
    cout << "Smallest window for s = \"" << s2 << "\" and p = \"" << p2 << "\" is " << smallestWindow(s2, p2) << endl;

    return 0;
}
