class Solution {
    public int orangesRotting(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        record Point(int x, int y) {
        }

        Set<Point> fresh = new HashSet<>();
        Queue<Point> queue = new LinkedList<>();

        int m = grid.length;
        int n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int time = 0;

        queue.offer(new Point(-1, -1));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    fresh.add(new Point(row, col));
                if (grid[row][col] == 2)
                    queue.offer(new Point(row, col));
            }
        }
        while (!queue.isEmpty() && queue.size() > 1 && !fresh.isEmpty()) {
            Point rottenApple = queue.poll();
            if (rottenApple.x == -1 && rottenApple.y == -1) {
                time++;
                queue.offer(new Point(-1, -1));
                continue;
            }

            Point left = new Point(rottenApple.x - 1, rottenApple.y);
            Point right = new Point(rottenApple.x + 1, rottenApple.y);
            Point up = new Point(rottenApple.x, rottenApple.y - 1);
            Point down = new Point(rottenApple.x, rottenApple.y + 1);

            if (fresh.contains(left)) {
                fresh.remove(left);
                queue.offer(left);
            }
            if (fresh.contains(right)) {
                fresh.remove(right);
                queue.offer(right);
            }
            if (fresh.contains(up)) {
                fresh.remove(up);
                queue.offer(up);
            }
            if (fresh.contains(down)) {
                fresh.remove(down);
                queue.offer(down);
            }
            // System.out.println(rottenApple);
        }

        if (fresh.isEmpty())
            return time;

        return -1;
    }
}