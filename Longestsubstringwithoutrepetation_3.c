int lengthOfLongestSubstring(char* s) {
    int lastSeen[128];
    for (int i = 0; i < 128; i++) {
        lastSeen[i] = -1;
    }
    int maxLength = 0;
    int left = 0;    
    for (int right = 0; s[right] != '\0'; right++) {
        char currentChar = s[right];
        if (lastSeen[(unsigned char)currentChar] >= left) {
            left = lastSeen[(unsigned char)currentChar] + 1;
        }
        lastSeen[(unsigned char)currentChar] = right;
        int currentLength = right - left + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    } 
    return maxLength;
}
