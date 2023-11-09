/**
    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

    Example 1:

    Input: grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
    ]
    Output: 1

    Example 2:

    Input: grid = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
    ]
    Output: 3
 * 
 */

#include <iostream>
#include <vector>


class Solution
{
public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int islandCount = 0;

        //Traverse through ever element
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                // If the element is an island("1"),
                // then check its neighbors and increment counter
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, row, col);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }

    void dfs(std::vector<std::vector<char>>& grid, int i, int j, int row, int col)
    {
        //Check boundary conditions if it is at the edge or
        // Check if its for an island('1') if its a 0 - water or visited - 2
        if( i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1')
            return;

        // If its not any boundary condition- you are now visiting this island part
        // Mark it visited by changing it to 2
        grid[i][j] = '2';

        //Repeat the dfs on all of it's neighbors
        dfs(grid, i-1, j, row, col ); //Top neighbor
        dfs(grid, i, j+1, row, col ); // Right neighbor
        dfs(grid, i, j-1, row, col);// Left neighbor
        dfs(grid, i+1, j, row, col); // Bottom Neighbor
    }

};

int main()
{
    std::vector<std::vector<char>> grid;

    grid = {{'1', '1', '1', '1'},
            {'1', '1', '0', '0'},
            {'1', '0', '1', '0'},
            {'0', '0', '0', '1'}};

    Solution solution;
    int numOfIslands;
    numOfIslands = solution.numIslands(grid);
    std::cout<<numOfIslands<<std::endl;

}