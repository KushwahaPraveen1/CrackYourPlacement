class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();

        int size = 0;
        vector<string> sentence;
        for (int i = 0; i < n; i++){
            string word = words[i];
            size+=word.size(); 

            sentence.push_back(word);
            int s = sentence.size();
            if (i == n-1 || maxWidth < s + size + words[i+1].size()) {
                // not enough space to store the next word
                string resStr = "";
                int space_available = maxWidth - size;
                if (s - 1 == 0) {
                    string spaces(space_available, ' ');
                    resStr += sentence[s-1] + spaces;
                } else {
                    vector<int> spaces(s - 1, 0);
                    while (space_available > 0) {
                        for (int j=0; j<s-1; j++){
                            if (space_available-- > 0) {
                                spaces[j]++;
                            }
                        }
                    }
                    for (int j = 0; j < s; j++) {
                        if (j > 0) {
                            string whitespaces(spaces[j-1],' ');
                            resStr += whitespaces;
                        }
                        resStr += sentence[j];
                    }
                }
                res.push_back(resStr);
                size = 0;
                sentence = vector<string>();
            }
        }
        
        string last_sentence = res[res.size() - 1];
        vector<string> last_words;
        int wordSize = 0;
        string word = ""; 
        for (char& c: last_sentence) {
            if (c == ' ' && word.size() > 0) {
                last_words.push_back(word);
                word="";
            } else if (c!= ' ') {
                wordSize++;
                word+=c;
            }
        }

        if (word != ""){
            last_words.push_back(word);
        }

        string lastStr = "";
        for (int i = 0; i<last_words.size();i++){
            if (i == last_words.size() - 1) {
                int prev_spaces = last_words.size() - 1;
                string spaces(maxWidth - wordSize - prev_spaces,' ');
                lastStr += last_words[i] + spaces;
            } else {
                lastStr += last_words[i] + ' ';
            }
        }
        res[res.size()-1] = lastStr;
        return res;
    }
};