class Solution {
    public int maxArea(int[] height) {
        // int ans = 0;
        // for (int i = 0; i < height.length; i++) {
        //     for (int j = i + 1; j < height.length; j++) {
        //         int container = 0;
        //         if (height[i] < height[j])
        //             container = height[i] * (j - i);
        //         else
        //             container = height[j] * (j - i);
        //         ans = Math.max(ans, container);
        //     }
        // }
        int p1 = 0, p2 = height.length - 1;
        int ans = Math.min(height[p1], height[p2]) * (p2 - p1);
        while (p1 < p2) {
            int container = Math.min(height[p1], height[p2]) * (p2 - p1);
            ans = Math.max(ans, container);
            if (height[p1] > height[p2])
                p2--;
            else
                p1++;
        }

        return ans;
    }
}