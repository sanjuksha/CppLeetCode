/**
 * @file FloodFill.cpp
 * @author Sanjuksha Nirgude
 * @brief You are also given three integers sr, sc, and color. 
 * You should perform a flood fill on the image starting from
 *  the pixel image[sr][sc].
 * To perform a flood fill, consider the starting pixel, 
 * plus any pixels connected 4-directionally to the starting pixel
 * of the same color as the starting pixel, plus any pixels 
 * connected 4-directionally to those pixels (also with the same color),
 * and so on. Replace the color of all of the aforementioned pixels with color.
 * Return the modified image after performing the flood fill.
 * 
 * Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * 
 * @date 2024-01-26
 * 
 */

#include <iostream>
#include <set>
#include <vector>

class Solution
{
public:
    Solution()
    {
        colored = {};
    }
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image,
     int sr, int sc, int color) 
    {   
        int og = image[sr][sc];
       
        dfs(image, sr, sc, og, color);

        return image;
        
    }

    void dfs(std::vector<std::vector<int>>& image,
     int i, int j, int og, int color)
    {
         //Check if not in bounds or 0 - return
         if(i < 0 || j < 0 || i >= image.size() 
         || j >= image[0].size() || image[i][j] != og)
            return;

         //check if already colored -return
         if(colored.find({i,j}) != colored.end())
            return;

         //if neither -color it
         image[i][j] = color;
         colored.insert({i,j});
         //explore neighbors

         dfs(image, i+1, j, og, color);
         dfs(image, i-1, j, og, color);
         dfs(image, i, j+1, og, color);
         dfs(image, i, j-1, og, color);
    }
private:
    std::set<std::pair<int,int>> colored;
};

int main()
{
    int color = 2;
    int sr = 1;
    int sc = 1;
    std::vector<std::vector<int>> image;
    image = {{1,1,1},
             {1,1,0},
             {1,0,1}};

    Solution solve;

    std::vector<std::vector<int>> coloredImage;
    coloredImage = solve.floodFill(image, sr, sc, color );
    std::cout<<" LeetCode 733. Flood Fill\n";
    //Print Matrix Image
    std::cout<<"{ \n";
    for(int i = 0; i < coloredImage.size(); i++)
    {
        std::cout<<"[";
        for(int j = 0; j < coloredImage[i].size(); j++)
        {
            std::cout<<coloredImage[i][j]<<" , ";
        }
        std::cout<<" ]\n";
    }
    std::cout<<"}";
}