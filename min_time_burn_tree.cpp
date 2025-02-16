/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  Node* createparentNode(Node* root,int target,map<Node*,Node*> &nodeToParent)
  {
      Node* res=NULL;
      
      queue<Node*> q;
      q.push(root);
      nodeToParent[root]=NULL;
      
      while(!q.empty())
      {
          Node* front=q.front();
          q.pop();
          
          if(front->data==target)
          {
              res=front;
          }
          
          if(front->left)
          {
              nodeToParent[front->left]=front;  // it means front-> left parent is front
              q.push(front->left);
              
          }
          
           if(front->right)
          {
              nodeToParent[front->right]=front;  // it means front-> left parent is front
              q.push(front->right);
              
          }
      }
      
      return res;
  }
  
  int burntree(Node* root,map<Node*,Node*> &nodeToParent)
  {
      map<Node*,bool> visited; // to checif every node is visited or not 
      queue<Node*> q;
      q.push(root);
      visited[root]=true;
      int ans=0;
      
      while(!q.empty())  // here we use bfs logic 
      {
          
          bool flag=false;
          int size=q.size();
          
          for(int i=0;i<size;i++)
          {
              Node* front=q.front();
              q.pop();
              
              if(front->left && !visited[front->left]) // checking left child
              {
                  flag=true;
                  q.push(front->left);
                  visited[front->left]=true;
              }
              
              if(front->right && !visited[front->right]) // checking right chile
              {
                  flag=true;
                  q.push(front->right);
                  visited[front->right]=true;
              }
              
              if(nodeToParent[front] && !visited[nodeToParent[front]])  //checking parent
              {
                  flag=true;
                  q.push(nodeToParent[front]);
                  visited[nodeToParent[front]]=true;
              }
              
              
          }
          if(flag==true)
          {
              ans++;
          }
          
      }
      return ans;
  }
    int minTime(Node* root, int target) {
        map<Node*,Node*> nodeToParent;
        Node* targetNode=createparentNode(root,target,nodeToParent);// first we neet to search target node in tree and it beconmes root
        int ans=burntree(targetNode,nodeToParent);
        return ans;// code here
    }
};
