class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int i = 0, j = 0;
        for (j = 0; j < n; j++) {
            if (word[j] == ch) break;
        }
        if (j == n) return word;
        cout << i << " " << j << endl;
        while (i < j) {
            swap(word[i], word[j]);
            i++, j--;
        }
        return word;
    }
};