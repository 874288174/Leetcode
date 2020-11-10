/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    set<pair<int, int>> visited;
    const vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    
    void dfs(Robot& robot, int x, int y, int dir){
        robot.clean();
        for(int k = 1; k <= 4; k++) {
            robot.turnRight();
            int new_dir = (dir + k) % 4;
            int xx = x + dirs[new_dir][0], yy = y + dirs[new_dir][1];
            if (visited.count({xx, yy})) continue;
            visited.emplace(xx,yy);
            if (robot.move()) {
                dfs(robot, xx, yy, new_dir);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
        }
    }
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
};