/**
 * @file ImplementTrie.cpp
 * @author Sanjuksha Nirgude
 * @brief A trie (pronounced as "try") or prefix tree is a tree data structure used 
 * to efficiently store and retrieve keys in a dataset of strings. 
 * There are various applications of this data structure, such as autocomplete and spellchecker.
 * 
 * Implement the Trie class:
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie 
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously 
 * inserted string word that has the prefix prefix, and false otherwise.
 * 
 * Example 1:
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * 
 * Output
 * [null, null, true, false, true, null, true]
 */

#include <iostream>
#include <string>
#include <map>

struct TrieNode
{
    std::map<char,TrieNode*> children; // Pointer to an array of size 26 for  all letters

    bool isLastOfWord = false; // Bool to check if it's the last letter of the word
};

class Trie
{
public:
    /**
     * @name Constructor
     * @brief Initialize a root node
     */
    Trie()
    {
        root = new TrieNode();
    }
    /**
     * @name Insert
     * @brief 
     * set the current node to root.
     * for the given string 'word' iterate through every char.
     * check if the char is a child of the root node
     * if not then add it as a child
     * update the current node to the child of that char
     * After for loop set the last node bool IsLastOfWord true
     * @param word 
    */
    void insert(std::string word)
    {
        auto curr = root;

        for(auto& c : word)
        {
            if(curr->children.find(c) == curr->children.end())
            {
                curr->children[c] = new TrieNode;
            }
            curr = curr->children[c];
        }
        curr->isLastOfWord = true;
    }

    /**
     * @name Search
     * @brief 
     * set the current node to root
     * For every char in the word check if it is child of root node
     * if not return flase
     * if yes, update the current node to that child
     * Return isLastOfWord after the for loop is over since it is set true if
     * the word is complete in the insert function.
     * 
     * @param word 
     * @return isLastOfWord - true if the word exists in the Trie & false o.w 
    */
    bool search(std::string word)
    {
        auto curr = root;
        for(auto& c : word)
        {
            if(curr->children.find(c) == curr->children.end())
             {
                return false;
             }
             curr = curr->children[c];
        }
        return curr->isLastOfWord;
    }

    /**
     * @name StartsWith 
     * @brief 
     * set the current node to root
     * For every char in the word check if it is child of root node
     * if not return flase
     * if yes, update the current node to that child
     * If the for loop is complete return true
     * @param prefix 
     * @return true if there exists a word which starts with the given prefix, false o.w 
    */
    bool startsWith(std::string prefix)
    {
        auto curr = root;
        for(auto& c : prefix)
        {
            if(curr->children.find(c) == curr->children.end())
            {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }

private:
    TrieNode* root;

};

int main()
{
    std::string word = "apple";
    Trie* obj = new Trie();
    obj->insert(word);
    bool param_2 = obj->search(word);
    bool param_3 = obj->startsWith("app");

    std::cout<<"LeetCode 208: Implement a Trie(prefix tree)\n";
    std::cout<<"Output : "<<param_2<<" "<<param_3;
}




















