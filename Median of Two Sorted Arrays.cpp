/**
 *  寻找第K大数
 */
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len = nums1.size() + nums2.size();
    if (len == 0) {
        return 0.0;
    }
    if (len % 2) {
        return findKth(nums1.begin(), nums2.begin(), (int)nums1.size(), (int)nums2.size(), len / 2 + 1);
    } else {
        return (findKth(nums1.begin(), nums2.begin(), (int)nums1.size(), (int)nums2.size(), len / 2) + 
                findKth(nums1.begin(), nums2.begin(), (int)nums1.size(), (int)nums2.size(), len / 2 + 1)) / 2.0;
    }
}
/**
*  两个排序数组中寻找中位数
*/
int findKth(vector<int>::iterator A, vector<int>::iterator B, int la, int lb, int k) {
    if (la > lb) {
        return findKth(B, A, lb, la, k);
    }
    if (la == 0) {
        return B[k - 1];
    }
    if (k == 1) {
        return min(*A, *B);
    }
    int ak = min(k / 2, la), bk = k - ak;
    if (A[ak - 1] < B[bk - 1]) {
        return findKth(A + ak, B, la - ak, bk, k - ak);
    }
    if (A[ak - 1] > B[bk - 1]) {
        return findKth(A, B + bk, ak, lb - bk, k - bk);
    }
    return A[ak - 1];
}