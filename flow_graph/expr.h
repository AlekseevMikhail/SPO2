#pragma once

#include <stddef.h>

#include "ast.h"
#include "flow_graph/literal.h"
#include "utils/position.h"


enum flow_graph_expr_type {

    FLOW_GRAPH_EXPR_TYPE_BINARY = 0,
    FLOW_GRAPH_EXPR_TYPE_UNARY,
    FLOW_GRAPH_EXPR_TYPE_CALL,
    FLOW_GRAPH_EXPR_TYPE_INDEXER,
    FLOW_GRAPH_EXPR_TYPE_LOCAL,
    FLOW_GRAPH_EXPR_TYPE_LITERAL,
};

struct flow_graph_expr;

struct flow_graph_expr_list {

    size_t size;
    size_t capacity;
    struct flow_graph_expr ** values;
};

struct flow_graph_expr_binary {

    enum ast_expr_binary_op op;
    struct flow_graph_expr * lhs;
    struct flow_graph_expr * rhs;
};

struct flow_graph_expr_unary {

    enum ast_expr_unary_op op;
    struct flow_graph_expr * value;
};

struct flow_graph_expr_call {

    struct flow_graph_subroutine * subroutine;
    struct flow_graph_expr_list args;
};

struct flow_graph_expr_indexer {

    struct flow_graph_expr * value;
    struct flow_graph_expr_list indices;
};

struct flow_graph_expr_local {

    struct flow_graph_local * local;
};

struct flow_graph_expr_literal {

    struct flow_graph_literal * literal;
};

struct flow_graph_expr {

    struct position position;
    struct ast_type_reference * type;

    enum flow_graph_expr_type _type;

    union {
        struct flow_graph_expr_binary binary;
        struct flow_graph_expr_unary unary;
        struct flow_graph_expr_call call;
        struct flow_graph_expr_indexer indexer;
        struct flow_graph_expr_local local;
        struct flow_graph_expr_literal literal;
    };
};

struct flow_graph_expr * flow_graph_expr_new_binary(
        struct position position,
        enum ast_expr_binary_op op,
        struct flow_graph_expr * lhs,
        struct flow_graph_expr * rhs
);
struct flow_graph_expr * flow_graph_expr_new_unary(
        struct position position,
        enum ast_expr_unary_op op,
        struct flow_graph_expr * value
);
struct flow_graph_expr * flow_graph_expr_new_call(struct position position, struct flow_graph_subroutine * subroutine);
struct flow_graph_expr * flow_graph_expr_new_indexer(struct position position, struct flow_graph_expr * value);
struct flow_graph_expr * flow_graph_expr_new_local(struct position position, struct flow_graph_local * local);
struct flow_graph_expr * flow_graph_expr_new_literal(struct position position, struct flow_graph_literal * literal);
void flow_graph_expr_delete(struct flow_graph_expr * expr);

struct flow_graph_expr_list flow_graph_expr_list_init(void);
void flow_graph_expr_list_append(struct flow_graph_expr_list * list, struct flow_graph_expr * value);
void flow_graph_expr_list_fini(struct flow_graph_expr_list * list);
