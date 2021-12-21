
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
 
struct node
{
    int lbit, rbit;
    int data;
    node *left, *right;
};
 
class TBT
{
private:
    node *head;
    node *root;
 
public:
    TBT() {
        root = NULL;
        head = NULL;
    }
    void Create(int dat)
    {
        node *tmp = new node;
 
        tmp->data = dat;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->lbit = 0;
        tmp->rbit = 0;
 
        if (root == NULL)
        {
            head = new node;
            root = tmp;
            head->data = -999;
            head->left = root;
            head->lbit = 1;
            head->right = head;
            head->rbit = 1;
            root->left = head;
            root->right = head;
        }
        else
        {
            insert(root, tmp);
        }
    }
 
    void insert(node *r, node *tmp)
    {
        if (tmp->data < r->data)
        {
            if (r->lbit == 0)
            {
                tmp->left = r->left;
                r->left = tmp;
                r->lbit = 1;
                tmp->right = r;
            }
            else
            {
                insert(r->left, tmp);
            }
        }
 
        if (tmp->data > r->data)
        {
            if (r->rbit == 0)
            {
                tmp->right = r->right;
                r->right = tmp;
                r->rbit = 1;
                tmp->left = r;
            }
            else
            {
                insert(r->right, tmp);
            }
        }
    }
 
    void PreorderTraversal()
    {
        node *T = head;
        T = T->left;
 
        while (T != head)
        {
            cout << T->data << " ";
            T = PreorderSuccessor(T);
        }
        cout << endl;
    }
 
    node *PreorderSuccessor(node *p)
    {
        if (p->lbit == 1)
        {
            return p->left;
        }
        while (p->rbit == 0)
            p = p->right;
        return p->right;
    }

    
    

};
 
int main()
{
    TBT tree;
    int arr[] = {4, 2, 6, 1, 8};
    for (int i = 0; i < 5; i++)
    {
        tree.Create(arr[i]);
    }
    tree.PreorderTraversal();
  
    return 0;
}