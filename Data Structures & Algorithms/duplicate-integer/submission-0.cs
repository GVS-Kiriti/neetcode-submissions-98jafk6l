public class Solution {
    public bool hasDuplicate(int[] nums) {
         int n = nums.Length ;
         HashSet<int> x = new HashSet<int>() ;


        for(int i = 0; i<n ; i++)
        {
            if (x.Contains(nums[i]))
            {
               
                return true ;

            }
            else {
                 x.Add(nums[i]) ;
            }
            

        }
        return false;

    }
}
