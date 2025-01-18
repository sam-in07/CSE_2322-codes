#include <iostream>
using namespace std;

// Define the structure for the tree node
struct TreeNode {
    int info;
    TreeNode *left;
    TreeNode *right;
};

// Function prototypes
TreeNode* insert(TreeNode* root, int x);
void inorder(TreeNode* root);
void postorder(TreeNode* root);
void preorder(TreeNode* root);
TreeNode* delet(TreeNode* root, int x);
TreeNode* search(TreeNode* root);

int main() {
    TreeNode* root = nullptr;
    int choice, item, item_no;

    do {
        cout << "\n\t 1. Insert in Binary Tree";
        cout << "\n\t 2. Delete from Binary Tree";
        cout << "\n\t 3. Inorder traversal of Binary tree";
        cout << "\n\t 4. Postorder traversal of Binary tree";
        cout << "\n\t 5. Preorder traversal of Binary tree";
        cout << "\n\t 6. Search and replace";
        cout << "\n\t 7. Exit";
        cout << "\n\t Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n Enter new element: ";
                cin >> item;
                root = insert(root, item);
                cout << "\n Inorder traversal of binary tree is: ";
                inorder(root);
                break;
            case 2:
                cout << "\n Enter the element to be deleted: ";
                cin >> item_no;
                root = delet(root, item_no);
                inorder(root);
                break;
            case 3:
                cout << "\n Inorder traversal of binary tree is: ";
                inorder(root);
                break;
            case 4:
                cout << "\n Postorder traversal of binary tree is: ";
                postorder(root);
                break;
            case 5:
                cout << "\n Preorder traversal of binary tree is: ";
                preorder(root);
                break;
            case 6:
                root = search(root);
                break;
            case 7:
                cout << "\n End of program\n";
                break;
            default:
                cout << "\n Invalid choice, try again!\n";
        }
    } while (choice != 7);

    return 0;
}

// Insert a new node into the binary tree
TreeNode* insert(TreeNode* root, int x) {
    if (root == nullptr) {
        root = new TreeNode(); // Allocate memory using new
        root->info = x;
        root->left = root->right = nullptr;
        return root;
    }
    if (x < root->info)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

// Inorder traversal (left, root, right)
void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->info << " ";
        inorder(root->right);
    }
}

// Postorder traversal (left, right, root)
void postorder(TreeNode* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->info << " ";
    }
}

// Preorder traversal (root, left, right)
void preorder(TreeNode* root) {
    if (root != nullptr) {
        cout << root->info << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Delete a node from the binary tree
TreeNode* delet(TreeNode* root, int x) {
    if (root == nullptr) {
        cout << "\nNode not found!\n";
        return root;
    }

    if (x < root->info) {
        root->left = delet(root->left, x);
    } else if (x > root->info) {
        root->right = delet(root->right, x);
    } else {
        // Node with the value found
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            // Node with two children: get the inorder successor
            TreeNode* temp = root->right;
            while (temp && temp->left != nullptr) {
                temp = temp->left;
            }
            root->info = temp->info;
            root->right = delet(root->right, temp->info);
        }
    }
    return root;
}

// Search and replace a node in the binary tree
TreeNode* search(TreeNode* root) {
    int target, new_value;
    cout << "\n Enter the element to be searched: ";
    cin >> target;

    TreeNode* ptr = root;
    while (ptr != nullptr) {
        if (target < ptr->info)
            ptr = ptr->left;
        else if (target > ptr->info)
            ptr = ptr->right;
        else {
            cout << "\n Element " << target << " found. Current value is: " << ptr->info;
            cout << "\n Do you want to replace it? (1 for Yes, 0 for No): ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                cout << "\n Enter the new value: ";
                cin >> new_value;
                ptr->info = new_value;
            }
            break;
        }
    }

    if (ptr == nullptr)
        cout << "\n Element " << target << " not found in the binary tree.\n";

    return root;
}
