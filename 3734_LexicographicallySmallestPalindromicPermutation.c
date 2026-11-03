#include <stdlib.h>
#include <string.h>
static char* build(const char* H, int h, int n, char mid) {
    char* res = (char*)malloc(n + 1);
    for (int i = 0; i < h; i++) {
        res[i] = H[i];
        res[n - 1 - i] = H[i];
    }
    if (n % 2 == 1) res[h] = mid;
    res[n] = '\0';
    return res;
}
char* lexPalindromicPermutation(char* s, char* target) {
    int n = strlen(s);
    int h = n / 2;
    int cnt[26] = {0};
    for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
    int odds = 0;
    char mid = 0;
    for (int c = 0; c < 26; c++) {
        if (cnt[c] % 2) {
            odds++;
            mid = 'a' + c;
        }
    }
    if (odds > 1) {
        char* e = (char*)malloc(1);
        e[0] = '\0';
        return e;
    }
    int half[26];
    for (int c = 0; c < 26; c++) half[c] = cnt[c] / 2;
    char H[305];
    int tmp[26];
    memcpy(tmp, half, sizeof(tmp));
    int ok = 1;
    for (int i = 0; i < h; i++) {
        int c = target[i] - 'a';
        if (tmp[c] == 0) { ok = 0; break; }
        tmp[c]--;
    }
    if (ok) {
        for (int i = 0; i < h; i++) H[i] = target[i];
        char* P = build(H, h, n, mid);
        if (strcmp(P, target) > 0) return P;
        free(P);
    }
    for (int i = h - 1; i >= 0; i--) {
        memcpy(tmp, half, sizeof(tmp));
        ok = 1;
        for (int j = 0; j < i; j++) {
            int c = target[j] - 'a';
            if (tmp[c] == 0) { ok = 0; break; }
            tmp[c]--;
        }
        if (!ok) continue;
        for (int c = target[i] - 'a' + 1; c < 26; c++) {
            if (tmp[c] > 0) {
                for (int j = 0; j < i; j++) H[j] = target[j];
                H[i] = 'a' + c;
                tmp[c]--;
                int pos = i + 1;
                for (int d = 0; d < 26; d++) {
                    while (tmp[d] > 0) {
                        H[pos++] = 'a' + d;
                        tmp[d]--;
                    }
                }
                return build(H, h, n, mid);
            }
        }
    }
    char* e = (char*)malloc(1);
    e[0] = '\0';
    return e;
}
