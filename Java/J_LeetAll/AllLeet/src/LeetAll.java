
import java.util.Arrays;
import java.util.HashSet;

class Solution {
    public int[] findIntersectionValues(int[] nums1, int[] nums2) {

        HashSet<Integer> s1 = new HashSet<>();
        for (int x : nums1) {
            s1.add(x);
        }
        HashSet<Integer> s2 = new HashSet<>();
        for (int x : nums2) {
            s2.add(x);
        }
        int[] res = new int[2];
        for (int x : nums1) {
            if (s2.contains(x))
                res[0]++;
        }

        for (int x : nums2) {
            if (s1.contains(x))
                res[1]++;
        }
        return res;
    }
    //////// 24-7-15

    public int incremovableSubarrayCount(int[] a) {
        int n = a.length;
        int i = 0;
        while (i < n - 1 && a[i] < a[i + 1]) {
            i++;

        }
        if (i == n - 1) {
            return n * (n + 1) / 2;

        }
        int ans = i + 2;

        for (int j = n - 1; j == n - 1 || a[j] < a[j + 1]; j--) {
            while (i >= 0 && a[i] >= a[j]) {
                i--;
            }
        }
        return ans;

    }
    ///////////////// 24-7-17

    public int minimumLevels(int[] possible) {
        int n = possible.length;
        int s = 0;
        for (int x : possible) {
            s += x;

        }
        s = s * 2 - n;
        int pre = 0;
        for (int i = 0; i < n; i++) {
            pre += possible[i] == 1 ? 2 : -2;
            if (pre > s) {
                return i + 1;
            }

        }
        return -1;

    }

    public int maximumSum(int[] arr) {// 前后缀分解

        int n = arr.length;
        int[] f = new int[n], g = new int[n];
        int res = arr[0];
        f[0] = arr[0];
        for (int i = 1; i < n; i++) {
            f[i] = Math.max(f[i - 1], 0) + arr[i];
            res = Math.max(res, f[i]);

        }

        g[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            g[i] = Math.max(g[i + 1], 0) + arr[i];

        for (int i = 1; i < n - 1; i++)
            res = Math.max(res, f[i - 1] + g[i + 1]);

        return res;

    }

    public int findValueOfPartition(int[] nums) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE;

        Arrays.sort(nums);

        for (int i = 1; i < n; i++) {
            ans = Math.min(ans, nums[i] - nums[i - 1]);
        }
        return ans;
    }

}
// --------------------------------------------------------------------------------//

public class LeetAll {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
        //////////////////////////////////////////////////////

        int[] arr = { 1, 2, 3, 4, 5 };
        int count = new Solution().incremovableSubarrayCount(arr);
        System.out.println("Number of incremovable subarrays: " + count);
    }
}