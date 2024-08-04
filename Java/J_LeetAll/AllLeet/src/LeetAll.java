
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
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

    public int maximumSum(int[] arr) {// prefix and suffix decomposition

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

    public String getSmallestString(String s, int k) {
        char[] t = s.toCharArray();
        for (int i = 0; i < t.length; i++) {
            int dis = Math.min(t[i] - 'a', 'z' - t[i] + 1);
            if (dis > k) {
                t[i] -= k;
                break;
            }
            t[i] = 'a';
            k -= dis;
        }
        return new String(t);

    }

    public int calPoints(String[] operations) {

        Deque<Integer> stk = new ArrayDeque<>();
        for (String op : operations) {
            if ("+".equals(op)) {
                int a = stk.pop();
                int b = stk.peek();
                stk.push(a);
                stk.push(a + b);

            } else if ("D".equals(op)) {
                stk.push(stk.peek() << 1);
            } else if ("C".equals(op)) {
                stk.pop();
            } else {
                stk.push(Integer.valueOf(op));
            }
        }
        return stk.stream().mapToInt(Integer::intValue).sum();
    }

    public long numberOfRightTriangles(int[][] grid) {

        int n = grid[0].length;
        int[] colSum = new int[n];
        Arrays.fill(colSum, -1);
        for (int[] row : grid) {
            for (int j = 0; j < n; j++) {
                colSum[j] += row[j];
            }
        }
        long ans = 0;
        for (int[] row : grid) {
            int rowSum = -1;
            for (int x : row) {
                rowSum += x;

            }
            for (int j = 0; j < row.length; j++) {
                if (row[j] == 1) {
                    ans += rowSum * colSum[j];
                }
            }
        }
        return ans;
    }

    public int maxPointsInsideSquare(int[][] points, String s) {

        int n = points.length;
        int[][] tep = new int[n][2];
        for (int i = 0; i < n; i++) {
            tep[i][0] = Math.max(Math.abs(points[i][0]), Math.abs(points[i][1]));
            tep[i][0] = s.charAt(i) - 'a';

        }
        Arrays.sort(tep, ((o1, o2) -> o1[0] - o2[0]));
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] cnt = new int[26];
        int ans = 0;
        for (int i = 0; i < tep.length; i++) {
            cnt[tep[i][1]]++;
            if (cnt[tep[i][1]] > 1) {
                ans -= map.getOrDefault(tep[i][0], 0);
                break;
            }
            map.put(tep[i][0], map.getOrDefault(tep[i][0], 0) + 1);
            ans++;

        }
        return ans;
    }
    // --------------------------------------java------------------------------------//
    //
    //
    //
    //
    //
    //
    //
    //
    //
    //
}
// ---------------------------------------Java---------------------------------------//

public class LeetAll {
    // Definition for a binary tree node.
    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    // ---------------------------------binary_tree----------------------------------//

    public static void main(String[] args) {
        System.out.println("Hello, World!");
        //////////////////////////////////////////////////////

        int[] arr = { 1, 2, 3, 4, 5 };
        int count = new Solution().incremovableSubarrayCount(arr);
        System.out.println("Number of incremovable subarrays: " + count);


    }
}