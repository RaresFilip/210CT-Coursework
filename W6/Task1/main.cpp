#include <iostream>
#include <stack>
using namespace std;

class BinTreeNode
{
public:
  BinTreeNode(int value)
  {
    this->value=value;
    this->left=NULL;
    this->right=NULL;
  }

  int value;
  BinTreeNode* left;
  BinTreeNode* right;
};

//The class for the elements of the stack
class node
{
public:
    BinTreeNode* data;
    node* next;
};

//The stack with elements of the type "BinTreeNode"
class TheStack
{
public:
    node* top;
    TheStack()
    {
        top=NULL;
    }

    //pushes (or inserts) the elements of the stack which are of the type "node" of which the data variable is of the type "BinTreeNode"
    void push(BinTreeNode* element)
    {
        //cout<<"pushing "<<element->value<<endl;

        node* newNode=new node();
        newNode->data=element;
        newNode->next=top;
        top=newNode;

    }

    //deletes the top element of the stack and updates is with the new top
    BinTreeNode* pop()
    {
        if(top==NULL)
            return NULL;
        BinTreeNode* tt=top->data;
        node* ctop=top;
        top=top->next;
        delete ctop;
        //cout<<"popping "<<tt->value<<endl;

        return tt;
    }
};

BinTreeNode* tree_insert(BinTreeNode* tree, int item)
{
  if(tree==NULL)
    tree=new BinTreeNode(item);
  else
    if(item < tree->value)
      if(tree->left==NULL)
        tree->left=new BinTreeNode(item);
      else
        tree_insert(tree->left,item);
    else
      if(tree->right==NULL)
        tree->right=new BinTreeNode(item);
      else
        tree_insert(tree->right,item);
  return tree;

}

void postorder(BinTreeNode* tree)
{
  if(tree->left!=NULL)
    postorder(tree->left);
  if(tree->right!=NULL)
    postorder(tree->right);
  std::cout << tree->value << std::endl;

}

/*void in_order(BinTreeNode* tree){
  if(tree->left!=NULL)
    in_order(tree->left);
  std::cout << tree->value << std::endl;
  if(tree->right!=NULL)
    in_order(tree->right);
}*/

void in_order(BinTreeNode* tree)
{
    TheStack A = TheStack();
    BinTreeNode* CurrentNode = tree;

    if(CurrentNode == NULL)
        cout<<"The tree is empty";
    else
    {
        //this while loop is for going through the LEFT side of the tree, writing it in order
        A.push(CurrentNode);

        do
        {
            if(CurrentNode->left!= NULL)
            {
                A.push(CurrentNode->left);
                CurrentNode = CurrentNode->left;
            }
            else
            {
                cout<<A.top->data->value<<" ";
                A.pop();

                if(CurrentNode->right!=NULL)
                {
                    A.push(CurrentNode->right);
                    CurrentNode = CurrentNode -> right;
                }
                else
                    if(A.top!=NULL) // this condition prevents poping and deleting inexisting nodes
                    {
                        cout<<A.top->data->value <<" ";
                        A.pop();
                    }
            }
        }while(A.top!=NULL);

        //this while loop is for going through the RIGHT side of the tree, writing it in order
        CurrentNode = tree->right;
        A.push(CurrentNode);

        do
        {
            if(CurrentNode->left!= NULL)
            {
                A.push(CurrentNode->left);
                CurrentNode = CurrentNode->left;
            }
            else
            {
                cout<<A.top->data->value<<" ";
                A.pop();

                if(CurrentNode->right!=NULL)
                {
                    A.push(CurrentNode->right);
                    CurrentNode = CurrentNode -> right;
                }
                else
                    if(A.top!=NULL) // this condition prevents poping and deleting inexisting nodes
                    {
                        cout<<A.top->data->value <<" ";
                        A.pop();
                    }
            }
        }while(A.top!=NULL);
    }
}

int main(int argc, char *argv[])
{
    BinTreeNode* t=tree_insert(0,6);
    tree_insert(t,10);
    tree_insert(t,5);
    tree_insert(t,2);
    tree_insert(t,3);
    tree_insert(t,4);
    tree_insert(t,11);

    in_order(t);

  return 0;
}
