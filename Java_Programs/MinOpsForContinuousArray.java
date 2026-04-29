import java.util.Arrays;

public class MinOpsForContinuousArray {
    public int minOperations(int[] nums) {
        int n = nums.length;
        // Step 1: Remove duplicates and sort
        int[] sortedUnique = Arrays.stream(nums).distinct().sorted().toArray();
        
        int minOps = n;
        int left = 0;
        
        // Step 2: Sliding window
        for (int right = 0; right < sortedUnique.length; right++) {
            // Keep window valid: range must be < n
            while (sortedUnique[right] - sortedUnique[left] >= n) {
                left++;
            }
            
            // Elements to keep: (right - left + 1)
            // Operations needed: n - elements_to_keep
            int currentOps = n - (right - left + 1);
            minOps = Math.min(minOps, currentOps);
        }
        
        return minOps;
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

        MinOpsForContinuousArray obj = new MinOpsForContinuousArray();
        int result = obj.minOperations(nums);
        System.out.println("Minimum operations to make array continuous: " + result);

        sc.close();
    }
}
