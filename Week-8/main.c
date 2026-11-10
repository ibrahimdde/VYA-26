
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int veri;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

Node* createNode(int x) {
    Node* newNode = malloc(sizeof(Node));

    if (newNode == NULL)
        return NULL;

    newNode->veri = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

Node* insertBST(Node* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->veri)
        root->left = insertBST(root->left, x);
    else if (x > root->veri)
        root->right = insertBST(root->right, x);

    return root;
}

int height(Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if (left > right)
        return left + 1;
    else
        return right + 1;
}

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

int balanceFactor(Node* root) {
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

Node* rotateLeft(Node* root) {
    Node* y = root->right;
    Node* temp = y->left;

    y->left = root;
    root->right = temp;

    root->height = height(root);
    y->height = height(y);

    return y;
}

Node* rotateRight(Node* root) {
    Node* y = root->left;
    Node* temp = y->right;

    y->right = root;
    root->left = temp;

    root->height = height(root);
    y->height = height(y);

    return y;
}

Node* insertAVL(Node* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->veri)
        root->left = insertAVL(root->left, x);
    else if (x > root->veri)
        root->right = insertAVL(root->right, x);
    else
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int bf = balanceFactor(root);

    if (bf > 1 && x < root->left->veri)
        return rotateRight(root);

    if (bf < -1 && x > root->right->veri)
        return rotateLeft(root);

    if (bf > 1 && x > root->left->veri) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (bf < -1 && x < root->right->veri) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->veri);
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->veri);
    preorder(root->left);
    preorder(root->right);
}

void clear(Node* root) {
    if (root == NULL)
        return;

    clear(root->left);
    clear(root->right);
    free(root);
}

int main(void) {
    printf("===== SORU 1 =====\n");

    Node* root = NULL;

    root = insertBST(root, 10);
    printf("10 eklendi. BF(kok) = %d\n", balanceFactor(root));

    root = insertBST(root, 20);
    printf("20 eklendi. BF(kok) = %d\n", balanceFactor(root));

    root = insertBST(root, 30);
    printf("30 eklendi. BF(kok) = %d\n", balanceFactor(root));

    if (balanceFactor(root) < -1) {
        printf("RR dengesizligi: Sol rotasyon!\n");
        root = rotateLeft(root);
    }

    printf("Kok: %d\n", root->veri);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\n\n");

    clear(root);

    printf("===== SORU 2 =====\n");

    int testler[4][3] = {
        {30, 20, 10},
        {10, 20, 30},
        {30, 10, 20},
        {10, 30, 20}
    };

    char* isimler[4] = {"LL", "RR", "LR", "RL"};

    for (int i = 0; i < 4; i++) {
        Node* avl = NULL;

        for (int j = 0; j < 3; j++) {
            avl = insertAVL(avl, testler[i][j]);
        }

        printf("Test %c (%s)\n", 'A' + i, isimler[i]);

        printf("Kok: %d\n", avl->veri);

        printf("Preorder: ");
        preorder(avl);

        printf("\nInorder: ");
        inorder(avl);

        printf("\n\n");

        clear(avl);
    }

    return 0;
}

