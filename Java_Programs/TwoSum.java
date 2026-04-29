import java.util.HashMap;
import java.util.Map;

class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        // Map to store value -> index
        Map<Integer, Integer> map = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            
            // If complement is found, return the pair of indices
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            
            // Otherwise, add current number and index to map
            map.put(nums[i], i);
        }
        
        // As per problem constraints, a solution always exists
        return new int[0];
    }

    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = Integer.parseInt(sc.nextLine().trim());

        int[] nums = new int[n];
        System.out.print("Enter elements separated by spaces: ");
        String[] tokens = sc.nextLine().trim().split("\\s+");
        for (int i = 0; i < n; i++)
            nums[i] = Integer.parseInt(tokens[i]);

        System.out.print("Enter target: ");
        int target = Integer.parseInt(sc.nextLine().trim());

        TwoSum obj = new TwoSum();
        int[] result = obj.twoSum(nums, target);

        if (result.length == 2)
            System.out.println("Indices: [" + result[0] + ", " + result[1] + "] "
                + "(" + nums[result[0]] + " + " + nums[result[1]] + " = " + target + ")");
        else
            System.out.println("No solution found.");

        sc.close();
    }
}
