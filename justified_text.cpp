#include <bits/stdc++.h>

using namespace std;
// what must be acknowledgement shall be
// science is what we understand well enough to explain to a computer. Art is everything else we do
vector < string > fullJustified(vector < string > words, int maxWidth) {
    int i = 0;
    int n = words.size();
    vector < vector < string > > lines;
    vector < string > line;
    int lineCount = 0;
    int spaceCount = 0;
    int count = 0;
    int wordCount = 0;

    while (i < n) {
        if (line.empty() == true) {
            lineCount += words[i].length();
        } else {
            lineCount += words[i].length();
            lineCount += 1;
        }

        if (lineCount > maxWidth) {
            lines.push_back(line);
            lineCount = words[i].length();
            line.clear();
        }

        if (line.empty() == true) {
            line.push_back(words[i]);
        } else {
            line.push_back(" ");
            line.push_back(words[i]);
        }
        i++;
    }

    if (lineCount <= maxWidth) {
        lines.push_back(line);
    }

    int characterCount = 0;
    int extraSpace = 0;

    for (int i = 0; i < lines.size(); i++) {
        characterCount = 0;
        wordCount = 0;
        for (int j = 0; j < lines[i].size(); j++) {
            if (lines[i][j] != " ") {
                characterCount += lines[i][j].length();
            } else {
                wordCount++;
            }
        }

        spaceCount = maxWidth - characterCount;
        string add = " ";
        int extraSpace = 0;

        if (wordCount != 0) {
            int tempExtraSpace = spaceCount % (wordCount);
            string tempAdd(spaceCount / (wordCount), ' ');
            extraSpace = tempExtraSpace;
            add = tempAdd;
        }

        if (i == (lines.size() - 1)) {
            string extra(spaceCount - wordCount, ' ');
            lines[i].push_back(extra);
        } else if (lines[i].size() == 1) {
            string extra(spaceCount, ' ');
            lines[i].push_back(extra);
        } else {
            if (spaceCount != 0) {
                for (int j = 1; j < lines[i].size(); j += 2) {
                    if (extraSpace != 0) {
                        string extra(1, ' ');
                        lines[i][j] = add + extra;
                        extraSpace--;
                    } else {
                        lines[i][j] = add;
                    }
                }
            }
        }

    }

    vector < string > result;
    string path = "";

    for (int i = 0; i < lines.size(); i++) {
        path = "";
        for (int j = 0; j < lines[i].size(); j++) {
            path += lines[i][j];
        }
        result.push_back(path);
    }

    return result;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector < string > words;
        string word;
        for (int i = 0; i < n; i++) {
            cin >> word;
            words.push_back(word);
        }

        int maxWidth;
        cin >> maxWidth;

        vector < string > result;
        result = fullJustified(words, maxWidth);
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << endl;
        }
    }
    return 0;
}
