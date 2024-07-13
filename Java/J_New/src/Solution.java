import java.util.Arrays;

class Solution {

    public boolean canSortArray(int[] nums) {
        int n = nums.length;
        for(int i = 0 ; i <n ; )
        {
            int start = i;
            int ones = Integer.bitCount(nums[i++]);
            while (i< n && Integer.bitCount(nums[i]) == ones) {
                i++;


                
            }
            Arrays.sort(nums,start,i);
        }
        for(int i = 1; i < n ; i++)
        {
            if(nums[i] <nums[i-1])
            
                return false;
            
        }
        return true;
        
        

    }

    public static void main(String[] args) {

        System.out.println("ds");

    }

}
