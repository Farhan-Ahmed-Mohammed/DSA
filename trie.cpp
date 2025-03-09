#include<iostream>
#include<cctype>  // For toupper() function
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie
{
    public:
    TrieNode* root;

    Trie()
    {
        root=new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word)
    {
        if (word.length() == 0)  // Base case: when the word is fully inserted
        {
            root->isTerminal = true;
            return;  // No further recursion needed
        }

        int index = toupper(word[0]) - 'A';  // Convert to uppercase and calculate index
        TrieNode* child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(toupper(word[0]));  // Insert as uppercase character
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));  // Recursively insert the rest of the word
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
    {
        if (word.length() == 0)  // Base case: if word is empty, check if it's terminal
        {
            return root->isTerminal;
        }

        int index = toupper(word[0]) - 'A';  // Convert to uppercase and calculate index
        TrieNode* child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;  // If the character is not found, return false
        }

        return searchUtil(child, word.substr(1));  // Continue searching the rest of the word
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
};

int main()
{
    Trie* t = new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");

    // Testing search
    cout << "Present or Not for TIM: " << t->searchWord("TIM") << endl;  // Should output 0 (false)
    cout << "Present or Not for TIME: " << t->searchWord("TIME") << endl; // Should output 1 (true)

    delete t;  // Clean up memory
}
