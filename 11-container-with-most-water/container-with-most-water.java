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
        int ans = 0, container = Math.min(height[p1], height[p2]) * (p2 - p1);
        while (p1 < p2) {
            // ans = Math.max(ans, container);
            // if (height[p1] > height[p2]) {
            //     container = height[p2] * (p2 - p1);
            //     p2--;
            // }
            // else {
            //     container = height[p1] * (p2 - p1);
            //     p1++;
            // }
            int h1 = height[p1];
            int h2 = height[p2];
            
            // Current "bottleneck" height
            int currentMinHeight = Math.min(h1, h2);
            
            // Calculate area just once per "bottleneck"
            ans = Math.max(ans, currentMinHeight * (p2 - p1));

            // OPTIMIZATION:
            // Instead of just if/else moving one step, we skip
            // ALL lines that are not taller than the current bottleneck.
            
            // If p1 was the shorter (or equal) side, move it until we find a taller line
            while (p1 < p2 && height[p1] <= currentMinHeight) {
                p1++;
            }
            
            // If p2 was the shorter (or equal) side, move it until we find a taller line
            while (p1 < p2 && height[p2] <= currentMinHeight) {
                p2--;
            }
        }
        ans = Math.max(ans, container);

        return ans;
    }
}