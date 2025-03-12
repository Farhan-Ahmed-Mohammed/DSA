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

        int index = word[0] - 'a';  // Convert to uppercase and calculate index
        TrieNode* child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);  // Insert as uppercase character
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));  // Recursively insert the rest of the word
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

   
    void printSuggesstion(TrieNode* curr,vector<string> &temp,string prefix)
{
    if(curr->isTerminal)
    {
        temp.push_back(prefix);
    }

    for(char ch='a';ch<='z';ch++)
    {
        TrieNode* next=curr->children[ch-'a'];
        if(next!=NULL)
        {
            prefix.push_back(ch);
            printSuggesstion(next,temp,prefix);
            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestion(string str)
{
    TrieNode* prev=root;
    vector<vector<string>> output;
    string prefix="";

    for(int i=0;i<str.length();i++)
    {
        char lastch=str[i];
        prefix.push_back(lastch);

        TrieNode* curr=prev->children[lastch-'a'];

        if(curr==NULL)
        {
            break;
        }

        vector<string> temp;
        printSuggesstion(curr,temp,prefix);
        output.push_back(temp);
        temp.clear();
        prev=curr;
    }

    return output;
}
};



vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t=new Trie();
    for(int i=0;i<contactList.size();i++)
    {
        string str=contactList[i];
        t->insertWord(str);
    }
    
    return t->getSuggestion(queryStr);//    Write your code here.
}
