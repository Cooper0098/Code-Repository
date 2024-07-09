public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!-------->");
        int a = 23;
        int b = 2132;
        System.out.println(a+b);
        
    }
}


class Solution {
    public int maximumPrimeDifference(int[] nums) {
        int i = 0;
        while( ! isPrime(nums[i]))
        {
            i++;
        }
        int j = nums.length - 1;
        while(!isPrime(nums[j]))
        {
            j--;
        }
        return j - i;
        

    }



    private boolean isPrime(int n)
    {
        for(int i = 2; i*i <= n ; i++)
        {
            if(n%i == 0 )
                return false;

            
        }
        return n >= 2;
    }
}