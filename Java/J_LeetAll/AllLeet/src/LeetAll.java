
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

    int ans = Integer.MAX_VALUE;
    int[][] grid;
    public int minimumMoves(int[][] grid) {
        this.grid = grid;
        int cnt = 0;
        for(int i = 0 ; i < 3 ; i++)
        {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == 0)
                    cnt++;
            }
        }
        
        dfs(0, cnt);
        return ans;

        

    }

    private void dfs(int sum, int cnt)
    {
        if(cnt == 0) 
            ans = Math.min(sum, ans);

            for(int i = 0 ; i < 3 ; i++)
            {
                for(int j = 0 ; j < 3;j++)
                {
                    if(grid[i][j] == 0)
                    {
                        for(int k = 0 ; k <3;k++)
                        {
                            for(int l = 0 ; l <3;l++)
                            {
                                if(grid[k][l] > 1)
                                {
                                    grid[k][l]--;
                                    grid[i][j] = 1;
                                    dfs(sum + Math.abs(i - k) + Math.abs(j - l), cnt - 1);
                                    grid[k][l]++;
                                    grid[i][j] = 0;
                                }
                            }
                        }
                    }
                }
            }
    }

}

public class LeetAll {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
        //////////////////////////////////////////////////////

        int[] arr = { 1, 2, 3, 4, 5 };
        int count = new Solution().incremovableSubarrayCount(arr);
        System.out.println("Number of incremovable subarrays: " + count);
    }
}