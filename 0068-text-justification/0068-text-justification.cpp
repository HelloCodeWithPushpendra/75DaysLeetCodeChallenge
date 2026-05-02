class Solution {
public:

    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> result;

        int n = words.size();
        int i = 0;

        while(i < n) {

            int j = i;
            int wordsLength = 0;

            while(j < n && wordsLength + words[j].size() + (j - i) <= maxWidth) {

                wordsLength += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            if(j == n || gaps == 0) {

                for(int k = i; k < j; k++) {

                    line += words[k];

                    if(k != j - 1)
                        line += " ";
                }

                line += string(maxWidth - line.size(), ' ');
            }

            else {

                int totalSpaces = maxWidth - wordsLength;

                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for(int k = i; k < j; k++) {

                    line += words[k];

                    if(k != j - 1) {

                        int spaces = evenSpaces;

                        if(extraSpaces > 0) {
                            spaces++;
                            extraSpaces--;
                        }

                        line += string(spaces, ' ');
                    }
                }
            }

            result.push_back(line);

            i = j;
        }

        return result;
    }
};