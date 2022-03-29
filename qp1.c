#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    struct BST *left;
    int data;
    struct BST *right;
} *node;

node getnode(int item)
{
    node temp = (node)malloc(sizeof(struct BST));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = item;
    return temp;
}

node insert(node root, int ele)
{
    if(root == NULL)
    {
        return getnode(ele);
    } else if (ele<root->data) {
        root->left = insert(root->left,ele);
    } else if (ele>root->data) {
        root->right = insert(root->right,ele);
    }
    return root;
}
void inorder(node root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

node findmin(node root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
node delete(node root, int info)
{
    if(root == NULL)
    {
        return root;
    } else if (info < root->data) {
        root->left = delete(root->left,info);
    } else if (info > root->data) {
        root->right = delete(root->right,info);
    } else {
        // no child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        // one child
        } else if (root->left == NULL) {
            node temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            node temp = root;
            root = root->left;
            free(temp);
        } else {
        // two child
            node temp = findmin(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);
        }
    }
    return root;
}
int main()
{
    node root = NULL;
    int e,j, ch = 1;

    while (ch != 5)
    {
        printf("\n\n1.Insert\n2.inorder\n3.delete\n4.exit\n");
        printf("5.Exit\n");
        scanf("%d", &ch);
        printf("\n");

        switch (ch)
        {
        case 1:
            printf("Element:");
            scanf("%d", &e);
            root = insert(root, e);
            break;

        case 2:
            inorder(root);
            break;

        case 3:
            printf("Element to delete:");
            scanf("%d", &j);
            root = delete(root,j);
            break;

        case 4:
            printf("Exiting.");
            exit(1);

        default:
            printf("Wrong input!");
        }
    }
}
