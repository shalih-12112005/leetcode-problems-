int minMoves(int* nums, int numsSize) {
    int max = nums[0];
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        sum += nums[i];
    }
    return max * numsSize - sum;
}
