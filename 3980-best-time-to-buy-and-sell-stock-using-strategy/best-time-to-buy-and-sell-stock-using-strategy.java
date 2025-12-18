class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        int[] originalDailyProfit = new int[prices.length];
        long maxProfit = 0;
        for (int i = 0; i < prices.length; i++) {
            originalDailyProfit[i] = prices[i] * strategy[i];
            maxProfit += originalDailyProfit[i];
        }
        long originalMaxProfit = maxProfit;

        boolean flag = true;
        long[] originalKProfit = new long[prices.length - k + 1];
        long[] modifiedKProfit = new long[prices.length - k + 1];

        for (int i = 0; i < prices.length - k + 1; i++) {
            if (flag) {
                for (int j = 0; j < k; j++) {
                    originalKProfit[i] += originalDailyProfit[j];
                    if (j >= k/2){
                        modifiedKProfit[i] += prices[j];
                    }
                }
                flag = false;
            } else {
                originalKProfit[i] = originalKProfit[i - 1] - originalDailyProfit[i - 1] + originalDailyProfit[i + k - 1];
                modifiedKProfit[i] = modifiedKProfit[i - 1] - prices[i - 1 + k/2] + prices[i + k - 1];
            }
            // System.out.println(maxProfit + " - " + originalKProfit[i] + " - " + modifiedKProfit[i]);
            maxProfit = Math.max(maxProfit, originalMaxProfit - originalKProfit[i] + modifiedKProfit[i]);
        }

        return maxProfit;

    }
}