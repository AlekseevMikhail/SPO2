#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "ast.h"


static const char * const TYPE_REFERENCE_BUILTIN_TYPES[] = {
        [AST_TYPE_REFERENCE_BUILTIN_TYPE_BOOL] = "bool",
        [AST_TYPE_REFERENCE_BUILTIN_TYPE_BYTE] = "byte",
        [AST_TYPE_REFERENCE_BUILTIN_TYPE_INT] = "int",
        [AST_TYPE_REFERENCE_BUILTIN_TYPE_UINT] = "uint",
        [AST_TYPE_REFERENCE_BUILTIN_TYPE_LONG] = "long",
        [AST_TYPE_REFERENCE_BUILTIN_TYPE_ULONG] = "ulong",
        [AST_TYPE_REFERENCE_BUILTIN_TYPE_CHAR] = "char",
        [AST_TYPE_REFERENCE_BUILTIN_TYPE_STRING] = "string",
};

static const char * const EXPR_BINARY_OPS[] = {
        [AST_EXPR_BINARY_OP_ASSIGNMENT] = "=",
        [AST_EXPR_BINARY_OP_PLUS] = "+",
        [AST_EXPR_BINARY_OP_MINUS] = "-",
        [AST_EXPR_BINARY_OP_MULTIPLY] = "*",
        [AST_EXPR_BINARY_OP_DIVIDE] = "/",
        [AST_EXPR_BINARY_OP_REMAINDER] = "%",
        [AST_EXPR_BINARY_OP_BITWISE_AND] = "&",
        [AST_EXPR_BINARY_OP_BITWISE_OR] = "|",
        [AST_EXPR_BINARY_OP_BITWISE_XOR] = "^",
        [AST_EXPR_BINARY_OP_AND] = "&&",
        [AST_EXPR_BINARY_OP_OR] = "||",
        [AST_EXPR_BINARY_OP_EQ] = "==",
        [AST_EXPR_BINARY_OP_NE] = "!=",
        [AST_EXPR_BINARY_OP_LT] = "<",
        [AST_EXPR_BINARY_OP_LE] = "<=",
        [AST_EXPR_BINARY_OP_GT] = ">",
        [AST_EXPR_BINARY_OP_GE] = ">=",
        [AST_EXPR_BINARY_OP_LEFT_BITSHIFT] = "<<",
        [AST_EXPR_BINARY_OP_RIGHT_BITSHIFT] = ">>",
        [AST_EXPR_BINARY_OP_ASSIGNMENT_PLUS] = "+=",
        [AST_EXPR_BINARY_OP_ASSIGNMENT_MINUS] = "-=",
        [AST_EXPR_BINARY_OP_ASSIGNMENT_MULTIPLY] = "*=",
        [AST_EXPR_BINARY_OP_ASSIGNMENT_DIVIDE] = "/=",
        [AST_EXPR_BINARY_OP_ASSIGNMENT_REMAINDER] = "%=",
        [AST_EXPR_BINARY_OP_ASSIGNMENT_BITWISE_AND] = "&=",
        [AST_EXPR_BINARY_OP_ASSIGNMENT_BITWISE_OR] = "|=",
        [AST_EXPR_BINARY_OP_ASSIGNMENT_BITWISE_XOR] = "^=",
        [AST_EXPR_BINARY_OP_ASSIGNMENT_AND] = "&&=",
        [AST_EXPR_BINARY_OP_ASSIGNMENT_OR] = "||=",
};

static const char * const EXPR_UNARY_OPS[] = {
        [AST_EXPR_UNARY_OP_MINUS] = "-",
        [AST_EXPR_UNARY_OP_BITWISE_NOT] = "~",
        [AST_EXPR_UNARY_OP_NOT] = "!",
        [AST_EXPR_UNARY_OP_INC] = "++",
        [AST_EXPR_UNARY_OP_DEC] = "--",
};

void ast_display_source(struct ast_source * source, const char * label, size_t indent, FILE * output);
void ast_display_source_item(struct ast_source_item * source_item, const char * label, size_t indent, FILE * output);
void ast_display_function_signature(
        struct ast_function_signature * function_signature,
        const char * label,
        size_t indent,
        FILE * output
);
void ast_display_type_reference(
        struct ast_type_reference * type_reference,
        const char * label,
        size_t indent,
        FILE * output
);
void ast_display_stmt(struct ast_stmt * stmt, const char * label, size_t indent, FILE * output);
void ast_display_expr(struct ast_expr * expr, const char * label, size_t indent, FILE * output);
void ast_display_literal(struct ast_literal * literal, const char * label, size_t indent, FILE * output);
