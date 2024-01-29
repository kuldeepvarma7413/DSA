import java.util.*;

class Solution {
    public static List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> list = new ArrayList<>();
        
        int i = 0;
        while (i < nums.length) {
            int position = nums[i] - 1;
            if (nums[i] != nums[position]) {
                int temp = nums[i];
                nums[i] = nums[position];
                nums[position] = temp;
            } else {
                i++;
            }
        }
        
        for (i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                list.add(i + 1);
            }
        }
        
        return list;
    }
}


public class DisappearedNumbersInArray {
    public static void main(String[] args){
        int[] nums={4,3,2,7,8,2,3,1};
        List<Integer> sol=Solution.findDisappearedNumbers(nums);
        System.out.println(sol);
    }
}
