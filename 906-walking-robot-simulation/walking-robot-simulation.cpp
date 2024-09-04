class Solution {
public:
    void changeDirection(int& xDirection, int& yDirection, int cmd) {
        if (cmd == -1) {
            if (yDirection) {
                xDirection = yDirection;
                yDirection = 0;
            } else {
                yDirection = -xDirection;
                xDirection = 0;
            }
        }
        if (cmd == -2) {
            if (yDirection) {
                xDirection = -yDirection;
                yDirection = 0;
            } else {
                yDirection = xDirection;
                xDirection = 0;
            }
        }
    }
    void moveRobot(int direction, int cmd, int& movingPos, int constPos,
                   vector<int> obstacles) {
        int newPos = movingPos + cmd * direction;
        

        if (direction == 1)
            for (int i = 0; i < obstacles.size(); i++) {
                if (obstacles[i] > movingPos && obstacles[i] <= newPos)
                    newPos = obstacles[i] - 1;
            }
        else
            for (int i = 0; i < obstacles.size(); i++) {
                if (obstacles[i] < movingPos && obstacles[i] >= newPos)
                    newPos = obstacles[i] + 1;
            }
        
        movingPos = newPos;
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> xConstObs(70000);
        vector<vector<int>> yConstObs(70000);

        int obsSize = obstacles.size();
        int maxDist = 0;

        for (int i = 0; i < obsSize; i++) {
            obstacles[i][0] += 30000;
            obstacles[i][1] += 30000;
            xConstObs[obstacles[i][0]].push_back(obstacles[i][1]);
            yConstObs[obstacles[i][1]].push_back(obstacles[i][0]);
        }

        int xPos = 30000, yPos = 30000;
        int yDirection = 1, xDirection = 0;

        int cmdSize = commands.size();

        for (int i = 0; i < cmdSize; i++) {
            int cmd = commands[i];
            cout << xPos << ":" << yPos << " " << xDirection << ":" << yDirection << " " << cmd << endl;
            if (cmd < 0)
                changeDirection(xDirection, yDirection, cmd);
            else {
                if (xDirection) {
                    moveRobot(xDirection, cmd, xPos, yPos, yConstObs[yPos]);
                    // int xNewPos = xPos + cmd * xDirection;
                    // if (xDirection == 1)
                    //     for (int i = 0; i < yConstObs[yPos].size(); i++) {
                    //         if (yConstObs[yPos][i] >= xPos &&
                    //                 yConstObs[yPos][i] = < xNewPos)
                    //             xNewPos = yConstObs[yPos][i];
                    //     }
                    // else
                    //     for (int i = 0; i < yConstObs[yPos].size(); i++) {
                    //         if (yConstObs[yPos][i] =
                    //                 < xPos && yConstObs[yPos][i] >= xNewPos)
                    //             xNewPos = yConstObs[yPos][i];
                    //     }
                } else {
                    moveRobot(yDirection, cmd, yPos, xPos, xConstObs[xPos]);
                }
            }
            int newDist = (xPos - 30000) * (xPos - 30000) + (yPos - 30000) * (yPos - 30000);
            if (newDist > maxDist)
                maxDist = newDist;
        }

        // xPos = xPos - 30000;
        // yPos = yPos - 30000;

        return maxDist;
    }
};