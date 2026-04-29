import java.util.Scanner;
class LongestRepeatingCharacterReplacement {
    static int bestLeft = 0, bestRight = 0;

    public static int characterReplacement(String s, int k) {
        int[] count = new int[26];
        int left = 0;
        int maxFreq = 0;
        int result = 0;

        for (int right = 0; right < s.length(); right++) {
            count[s.charAt(right) - 'A']++;

            maxFreq = Math.max(maxFreq, count[s.charAt(right) - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                count[s.charAt(left) - 'A']--;
                left++;
            }

            if (right - left + 1 > result) {
                result = right - left + 1;
                bestLeft = left;
                bestRight = right;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the string (uppercase letters only): ");
        String s = sc.nextLine();

        System.out.print("Enter the value of k: ");
        int k = Integer.parseInt(sc.nextLine());

        int ans = characterReplacement(s, k);
        System.out.println("Longest repeating character replacement length: " + ans);

        // Find the dominant character (most frequent) in the best window
        String window = s.substring(bestLeft, bestRight + 1);
        int[] freq = new int[26];
        for (char c : window.toCharArray()) freq[c - 'A']++;
        char dominant = 'A';
        for (int i = 1; i < 26; i++)
            if (freq[i] > freq[dominant - 'A']) dominant = (char)('A' + i);

        // Build the modified string by replacing non-dominant chars in the window
        StringBuilder modified = new StringBuilder(s);
        for (int i = bestLeft; i <= bestRight; i++)
            modified.setCharAt(i, dominant);

        System.out.println("Modified string: " + modified);
        System.out.println("Best window: [" + bestLeft + ", " + bestRight + "] → \"" + window + "\" → replaced with '" + dominant + "'");

        sc.close();
    }
}
