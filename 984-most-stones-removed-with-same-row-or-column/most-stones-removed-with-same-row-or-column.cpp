class Solution {
public:
    int findNextVertex(int* matrix, int n)
    {
        for (int i = 0; i < n; i++)
            if (matrix[i] != 0)
                return i;
        
        return -1;
    }
    int countConnectedComponents(int graph[][1001], int size)
    {
        int count = 0;

        if (size == 0)
            return count;

        // if (size == 1)
        //     return 1;
        
        int* passedVertexMatrix = new int[size];

        for (int i = 0; i < size; i++)
        {
            passedVertexMatrix[i] = 1;
        }
            
        
        queue<int> q;
        q.push(0);
        passedVertexMatrix[0] = 0;
        count++;
        
        while (q.size() > 0)
        {
            int checkingRow = q.front();
            q.pop();

            for (int i = 0; i < size; i++)
                if (graph[checkingRow][i] && passedVertexMatrix[i])
                {
                    q.push(i);
                    passedVertexMatrix[i] = 0;
                }
            
            if (q.size() == 0)
            {
                
                int nextVertex = findNextVertex(passedVertexMatrix, size);
                // cout << nextVertex << endl;
                if (nextVertex == -1)
                    break;
                // cout << nextVertex << endl;
                count++;
                passedVertexMatrix[nextVertex] = 0;
                q.push(nextVertex);
            }
        }

        delete [] passedVertexMatrix;

        return count;

    }
    int removeStones(vector<vector<int>>& stones) {
        // int xCord[20000]{0}, yCord[20000]{0};
        int matrix[1001][1001]{0};
        int n = stones.size();
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    matrix[i][j] = 1;
                    matrix[j][i] = 1;
                }
        // cout << n << " " << countConnectedComponents(matrix, n);
        return n - countConnectedComponents(matrix, n);
    }
};