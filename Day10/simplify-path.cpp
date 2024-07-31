#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(token);
            }
        }

        string result;
        while (!stk.empty()) {
            result = "/" + stk.top() + result;
            stk.pop();
        }

        return result.empty() ? "/" : result;
    }
};

int main() {
    Solution sol;
    string path1 = "/home/";
    string path2 = "/home//foo/";
    string path3 = "/home/user/Documents/../Pictures";
    string path4 = "/../";
    string path5 = "/.../a/../b/c/../d/./";

    cout << "Simplified path for \"" << path1 << "\" is " << sol.simplifyPath(path1) << endl;
    cout << "Simplified path for \"" << path2 << "\" is " << sol.simplifyPath(path2) << endl;
    cout << "Simplified path for \"" << path3 << "\" is " << sol.simplifyPath(path3) << endl;
    cout << "Simplified path for \"" << path4 << "\" is " << sol.simplifyPath(path4) << endl;
    cout << "Simplified path for \"" << path5 << "\" is " << sol.simplifyPath(path5) << endl;

    return 0;
}
