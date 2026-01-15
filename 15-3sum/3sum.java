class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> ans = new HashSet<>();
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int oldCount = 0;
            if (count.containsKey(nums[i]))
                oldCount = count.get(nums[i]);
            
            count.put(nums[i], oldCount + 1);
        }

        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            // first sum
            int key = entry.getKey();
            int value = entry.getValue();
            entry.setValue(value - 1);

            for (Map.Entry<Integer, Integer> entry1 : count.entrySet()) {
                int key1 = entry1.getKey();
                int value1 = entry1.getValue();
                if (value1 < 1)
                    continue;
                entry1.setValue(value1 - 1);
                int key2 = -(key + key1);
                if (count.containsKey(key2)) {
                    int value2 = count.get(key2);
                    if (value2 > 0) {
                        List<Integer> triplet = new ArrayList<>();
                        triplet.add(key);
                        triplet.add(key1);
                        triplet.add(key2);
                        Collections.sort(triplet);
                        ans.add(triplet);
                    }
                }

                entry1.setValue(value1);
            }
            
            entry.setValue(value);
        }
        

        // HashMap<Integer, List<Integer>> numsLocation = new HashMap<>();
        // for (int i = 0; i < nums.length; i++) {
        //     List<Integer> indexes = numsLocation.computeIfAbsent(nums[i], k -> new ArrayList<>());

        //     if (indexes.size() < 3) {
        //         indexes.add(i);
        //     }
        //     // numsLocation.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        // }
        // for (int i = 0; i < nums.length; i++) {
        //     for (int j = 0; j < nums.length && j != i; j++) {
        //         if (nums[i] + nums[j] > Integer.MAX_VALUE)
        //             continue;
        //         int sum = -(nums[i] + nums[j]);
        //         if (numsLocation.containsKey(sum)) {
        //             List<Integer> kList = numsLocation.get(sum);
        //             for (int k : kList) {
        //                 if (k != i && k != j) {
        //                     List<Integer> triplet = new ArrayList<>();
        //                     triplet.add(nums[i]);
        //                     triplet.add(nums[j]);
        //                     triplet.add(nums[k]);
        //                     Collections.sort(triplet);
        //                     ans.add(triplet);
        //                 }
        //             }
        //         }
        //     }
        // }

        return new ArrayList<>(ans);
    }
}