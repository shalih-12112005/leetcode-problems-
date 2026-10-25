char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* empty = (char*)malloc(1 * sizeof(char));
        empty[0] = '\0';
        return empty;
    }
    int firstLen = strlen(strs[0]);
    char* prefix = (char*)malloc((firstLen + 1) * sizeof(char));
    for (int col = 0; col < firstLen; col++) {
        char currentChar = strs[0][col];
        for (int row = 1; row < strsSize; row++) {
            if (strs[row][col] == '\0' || strs[row][col] != currentChar) {
                prefix[col] = '\0';
                return prefix;
            }
        }
        prefix[col] = currentChar;
    }
    prefix[firstLen] = '\0';
    return prefix;
}
