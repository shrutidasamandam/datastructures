#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    struct BST *left;
    struct BST *right;
    int data;
}*node;

node getnode(int item)
{
    node newnode = (node)malloc(sizeof(struct BST));
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> data = item;
    return newnode;
}

node insert(node root, int ele)
{
    if(root == NULL)
    {
        return getnode(ele);
    } else if (ele < root->data) {
        root->left = insert(root->left,ele);
    } else if (ele > root->data) {
        root->right = insert(root->right,ele);
    }
    return root;
}

node minval(node min)
{
    while(min->left!=NULL)
    {
        min = min->left;
    }
    return min;
}

node delete(node root, int data)
{
    if(root==NULL)
    {
        return root;
    } else if (data < root->data) {
        root->left = delete(root->left,data);
    } else if (data > root->data) {
        root->right = delete(root->right,data);
    } else {
        // case 1: no child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // case 2: one child
        else if (root->left == NULL) {
            node temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            node temp = root;
            root = root->left;
            free(temp);
        // case 3: 2 child
        } else {
            node temp = minval(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
}

node maxval(node max)
{
    while(max->right!=NULL)
    {
        max = max->right;
    }
    return max;
}

void inorder(node root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

void preorder(node root)
{
    if(root==NULL)
    return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

node search(node nodem, int key)
{
    if(nodem == NULL)
    return NULL;
    if(nodem->data==key)
    {
        return nodem->data;
    } if (key<nodem->data) {
        search(nodem->left,key);
    } else {
        search(nodem->right,key);
    }
}
int main()
{
    node root = NULL;
    int d,e,s,ch=1;

    while(ch!=8)
    {
        printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postoder\n5.Min\n6.Max\n7.Exit\n8.search");
        scanf("\n%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter element");
                    scanf("%d",&e);
                    root = insert(root,e);
                    break;
            case 2: preorder(root);
                    break;
            case 3: inorder(root);
                    break;
            case 4: postorder(root);
                    break;
            case 5: 
                    printf("Minimum value is %d",minval(root));
                    break;
            case 6: 
                    printf("Maximum value is %d",maxval(root));
                    break;
            case 8: printf("\nEnter element to search");
                    scanf("%d",&s);
                    printf("found at %d",search(root,s));
                    break;
            case 7: exit(0);
        }
    }
}

