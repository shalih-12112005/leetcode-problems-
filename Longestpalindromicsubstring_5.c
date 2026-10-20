int expandAroundCenter(char* s, int left, int right, int len) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}
char* longestPalindrome(char* s) {
 if (s == NULL || *s == '\0') {
        char* res = (char*)malloc(1);
        res[0] = '\0';
        return res;
    }
    int start = 0, maxLength = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i, len);
        int len2 = expandAroundCenter(s, i, i + 1, len);
        int currentLen = (len1 > len2) ? len1 : len2;
        if (currentLen > maxLength) {
            maxLength = currentLen;
            start = i - (currentLen - 1) / 2;
        }
    }
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    for (int i = 0; i < maxLength; i++) {
        result[i] = s[start + i];
    }
    result[maxLength] = '\0';
    return result;   
}
