/**
 * @file IslandPerimeter.cpp
 * @author Sanjuksha Nirgude
 * @brief You are given row x col grid representing a map where grid[i][j] = 1 
 * represents land and grid[i][j] = 0 represents water.
 * Grid cells are connected horizontally/vertically (not diagonally).
 *  The grid is completely surrounded by water, and there is exactly one island 
 * (i.e., one or more connected land cells). The island doesn't have "lakes", 
 * meaning the water inside isn't connected to the water around the island. 
 * One cell is a square with side length 1. The grid is rectangular,
 * width and height don't exceed 100. Determine the perimeter of the island.
 * 
 * Example:
 * Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * Output: 16
 * @date 2024-01-26
 */

#include <iostream>
#include <vector>
#include <set>
#include <utility>

class Solution
{
public:
    Solution()
    {
        visited = {};
    }
    /**
     * @brief Island Perimeter is calculated by first,
     * finding the first peice of land/cell with value 1
     * by iterating through the entire grid
     * Then apply dfs on it and return the perimeter.
     * 
     * @param grid 
     * @return int 
     */
    int islandPerimeter(std::vector<std::vector<int>>& grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j])
                    return dfs(grid, i, j);
            }
        }
        return 0;
    }
    /**
     * @brief This is the main part where we follow recursionn.
     * Base Case: Check if current cell is out of bounds of matrix, or if its
     * a water cell and return 1 as we found a boundary and add to perimeter
     * Check if this cell is already visited and return 0 
     * If neither then,
     * Invoke Recursion: apply dfs on every neighbor and accumulate value 
     * in perimeter. And return perimeter
     * 
     * @param i 
     * @param j 
     * @return int 
     */
    int dfs(std::vector<std::vector<int>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() 
        || j >= grid[0].size() || grid[i][j] == 0)
        {
            //out of bounds or water
            return 1;
        }

        if(visited.find({i,j}) != visited.end())
        {
            //already visited cell
            return 0;
        }
        visited.insert(std::make_pair(i,j));
        int peri = 0;
        peri +=dfs(grid, i+1,j);
        peri +=dfs(grid, i-1,j);
        peri +=dfs(grid, i,j+1);
        peri +=dfs(grid, i,j-1);

        return peri;
    }

private:
    std::set<std::pair<int,int>> visited;

};


int main()
{
    std::vector<std::vector<int>> grid;
    
    grid = {
            {0,1,0,0},
            {1,1,1,0}, 
            {0,1,0,0},
            {1,1,0,0}};

    Solution solve;

    int output = solve.islandPerimeter(grid);

    std::cout<<"LeetCode 463: Island Perimeter \n";
    std::cout<<"Output : "<<output;
}