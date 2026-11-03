int* maxDepthAfterSplit(char* seq, int* returnSize) {
     int len = strlen(seq);
    *returnSize = len;
    int* ans = (int*)malloc(len * sizeof(int));
    int depth = 0;
    for (int i = 0; i < len; i++) {
        if (seq[i] == '(') {
            ans[i] = depth % 2;
            depth++;
        } else {
            depth--;
            ans[i] = depth % 2;
        }
    }
    return ans;
}
