#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <string.h>

typedef struct ASTNode {
    char *type;
    char *value;
    char *dataType;
    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *next;
} ASTNode;

ASTNode* createNode(const char *type, const char *value,
                    ASTNode *left, ASTNode *right, ASTNode *next);
void printAST(ASTNode *node, int level);

#endif // AST_H