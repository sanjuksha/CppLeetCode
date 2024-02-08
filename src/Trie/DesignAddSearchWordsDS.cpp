/**
 * @file DesignAddSearchWordsDS.cpp
 * @author Sanjuksha Nirgude
 * @brief 
 *Design a data structure that supports adding new words and finding if a string matches
 * any previously added string.
 * 
 * Implement the WordDictionary class:
 * 
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched later.
 * bool search(word) Returns true if there is any string in the data structure that 
 * matches word or false otherwise. word may contain dots '.' 
 * where dots can be matched with any letter.
 * 
 * Example:
 * Input
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * 
 * Output
 * [null,null,null,null,false,true,true,true]
 * 
 */

#include <iostream>
#include <string>
#include <map>

struct TrieNode
{
    std::map<char, TrieNode*> children; // Map assign children node to every char
    bool isLastOfWord = false;

};

class WordDictionary
{
public:
    /**
     * @name Constructor
     * @brief Initializes the root node
     */
    WordDictionary()
    {
        root = new TrieNode();
    }
    /**
     * @name addWord
     * @brief 
     * Initialize curr node to the root node
     * Iterate through every char in the word string
     * find if the char exists in the children of root node if not add it
     * Update the current node to the child
     * At the end update the isLastOfWord true to mark the end of that word
     * @param word 
     */
    void addWord(std::string word)
    {
        auto curr = root;
        for(auto& c : word)
        {
            if(curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isLastOfWord = true;
    }
    /**
     * @name search
     * @brief Call dfs with root node and index 0 as we want to start from the begining 
     * of the word.
     *      
     * @param word 
     * @return true 
     */
    bool search(std::string word)
    {
        return dfs(word, 0,root);
    }

private:
    TrieNode* root;
    /**
     * @name DFS - Depth First search
     * @brief 
     * Initialize the current node to root node we get from dfs args
     * for every char in the string word- use int i = ind here as we need to reduce the len every loop of dfs
     * check if we have already parsed through the rest of the word in the previous revursoion
     * if not 
     *       check if the char exist in the children map -if not return false
     *       if yes - update the curr node to the child of current child
     *       At the end return isLastOfWord which was marked in the end of addWord saying word found
     * if '.' is true
     *      for each child of our curr node we recursive search in all children's values in map
     *      This is because we don't to search the level in tree of the .
     *      if the dfs gives us true meaning we found the entire . and post word so return true
     *      if the for loop is over and we didn't find anything then we return false
     * 
     * @param ind 
     * @param currRoot - current root node
     * @return true if word exists false o.w
     */
    bool dfs(std::string& word, int ind, TrieNode* currRoot)
    {
        auto curr = currRoot;
        for(int i = ind; i < word.size(); i++)
        {
            char c = word[i];

            if(c == '.')
            {
                for(auto& child : curr->children)
                {
                    if (dfs(word, i+1, child.second))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                if(curr->children.find(c) == curr->children.end())
                {
                    return false;
                }
                curr = curr->children[c];
            }
        }
        return curr->isLastOfWord;
    }


};

int main()
{
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    bool output1 = obj->search("bad");
    bool output2 = obj->search("pad");
    bool output3 = obj->search("b..");
    bool output4 = obj->search(".ad");

    std::cout<<"LeetCode 211: Design Add and Search Words Data Structure \n";
    std::cout<<"bad :"<<output1<<"\n";
    std::cout<<"pad :"<<output2<<"\n";
    std::cout<<"b.. :"<<output3<<"\n";
    std::cout<<".ad :"<<output4<<"\n";

}