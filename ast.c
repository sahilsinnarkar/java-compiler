#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ASTNode* createNode(const char *type, const char *value,
                    ASTNode *left, ASTNode *right, ASTNode *next) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type ? strdup(type) : NULL;
    node->value = value ? strdup(value) : NULL;
    node->dataType = NULL;
    node->left = left;
    node->right = right;
    node->next = next;
    node->cases = NULL;
    return node;
}

void printAST(ASTNode *node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s", node->type);
    if (node->value) printf(" (%s)", node->value);
    if (node->dataType) printf(" [%s]", node->dataType);
    printf("\n");
    printAST(node->left, level + 1);
    printAST(node->right, level + 1);
    printAST(node->next, level);
}