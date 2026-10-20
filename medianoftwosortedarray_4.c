double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    if (m > n) {
        return findMedianSortedArrays(nums2, n, nums1, m);
    }
    
    int low = 0, high = m;
    int totalLeft = (m + n + 1) / 2;
    
    while (low <= high) {
        int partitionX = low + (high - low) / 2;
        int partitionY = totalLeft - partitionX;
        
        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == m) ? INT_MAX : nums1[partitionX];
        
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == n) ? INT_MAX : nums2[partitionY];
        
        if (maxX <= minY && maxY <= minX) {
            if ((m + n) % 2 == 0) {
                int maxLeft = (maxX > maxY) ? maxX : maxY;
                int minRight = (minX < minY) ? minX : minY;
                return (double)(maxLeft + minRight) / 2.0;
            } else {
                return (double)((maxX > maxY) ? maxX : maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    
    return 0.0;
}
