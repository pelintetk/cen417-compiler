#ifndef AST_H
#define AST_H

typedef enum {
    NODE_PROGRAM,
    NODE_VAR_DECL,
    NODE_FUNC_DECL,
    NODE_ASSIGN,
    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV,
    NODE_LT,
    NODE_GT,
    NODE_EQ,
    NODE_NEQ,
    NODE_IF,
    NODE_FOR,
    NODE_RETURN,
    NODE_PRINT,
    NODE_IDENTIFIER,
    NODE_INTEGER_LITERAL,
    NODE_TRUE,
    NODE_FALSE
} NodeType;

typedef struct ASTNode {
    NodeType type;
    char *value;
    struct ASTNode *left;
    struct ASTNode *right;
    struct ASTNode *next;
} ASTNode;

ASTNode* create_node(NodeType type, char *value);
ASTNode* create_binary_node(NodeType type, ASTNode *left, ASTNode *right);
void print_ast(ASTNode *node, int indent);
void free_ast(ASTNode *node);

#endif