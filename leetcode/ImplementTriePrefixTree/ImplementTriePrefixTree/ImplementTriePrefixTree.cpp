/**********************************************************************************
*
* Implement a trie with insert, search, and startsWith methods.
*
* Note:
* You may assume that all inputs are consist of lowercase letters a-z.
*
*
**********************************************************************************/
	
#include<unordered_map>
using namespace std;
class TrieNode {
public:
	//Initialize your data structure here 
	TrieNode():isWord(false){ }
	unordered_map<char, TrieNode*>children;

	bool isWord;

};


class Trie {
public:
	Trie()
	{
		root =new 
	}

private :
	inline bool retrieve(const string &key, bool isWord)
	{
		if (key.size()<=0)
		{
			return false;
		}
		TrieNode*node = root;
		for (int i = 0; i < key.length; i++)
		{
			if (node->children.find(key[i])==node->children.end())
			{
				return false;
			}
			node = node->children[key[i]];
		}
		return isWord ? node->isWord : true;

	}

	TrieNode*root;
};


// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

