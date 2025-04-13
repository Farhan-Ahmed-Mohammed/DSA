string reverseWords(string &s) {
    string ans = "";
    string temp = "";
    bool firstword = true;
    bool lastword = false; // Will be true when we hit the last actual word

    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            if (!temp.empty()) {
                reverse(temp.begin(), temp.end());

                // Add space *only* if this is not the first word being added
                if (!firstword) {
                    ans.push_back(' ');
                }

                ans += temp;
                temp = "";
                firstword = false;  // We've added the first word now
                lastword = false;   // Reset in case there were spaces after this
            }
        } else {
            temp.push_back(s[i]);
            lastword = true;  // We're in a word now
        }
    }

    // If there was a word at the beginning (last word in reverse)
    if (!temp.empty() && lastword) {
        reverse(temp.begin(), temp.end());
        if (!firstword) {
            ans.push_back(' ');
        }
        ans += temp;
    }

    return ans;
}
