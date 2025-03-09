class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        childCount=0;
        isTerminal=false;
    }
};

class Trie
{
    public:
    TrieNode* root;

    Trie(char ch)
    {
        root=new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word)
    {
        if (word.length() == 0)  // Base case: when the word is fully inserted
        {
            root->isTerminal = true;
            return;  // No further recursion needed
        }

        int index = word[0] - 'a';  // Convert to uppercase and calculate index
        TrieNode* child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;  // Insert as uppercase character
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));  // Recursively insert the rest of the word
    
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str,string &ans)
    {
        for(int i=0;i<str.size();i++)
        {
            char ch=str[i];

            if(root->childCount==1)
            {
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }

            else
            {
                break;
            }

            if(root->isTerminal)
            {
                break;
            }
        }
    }

};



string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t=new Trie('\0');
    
    for(int i=0;i<n;i++)
    {
        t->insertWord(arr[i]);
    }
    
    string first=arr[0];
    string ans="";
    
    t->lcp(first,ans);
    return ans;// Write your code here
}


