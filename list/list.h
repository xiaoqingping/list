/**
 * list.h - 通用链表头文件
 *
 * 将针对链表的常用操作：节点空间申请，节点空间释放，遍历节点，打印等等使用函数指针定义
 * 在遍历节点的基础上可以实现诸如链表节点的搜索、更新、排序等等操作。
 * 该链表的通用性极好，使用者只需要根据自己的情况实现相应的节点操作函数即可，其余的工作由链表模块自己完成
 * 
 * @author xiaoqingping [xiaoqingping@qq.com] 2016-9-8
 * @link     https://github.com/xiaoqingping/list
 * @license  MIT license
 * 
 */
#ifndef _LIST_H_
#define _LIST_H_

typedef void *(*malloc_data)(int size);        /* 申请空间 */ 
typedef void (*free_data)(void *data);         /* 释放空间 */
typedef int (*visit)(void *data, void *res);   /* 遍历 */
typedef void (*print_data)(void *data);        /* 打印 */

/* 链表头结点 */
typedef struct node_s
{
    void *data;
    struct node_s *next;
} node_t;

/* 链表 */
typedef struct list_s
{
    node_t *head;
    node_t *tail;
    int len;
} list_t;

/* 初始化链表头 */
extern list_t *init_head();

/* 删除链表 */
extern void *del_list(list_t *lst, free_data ffunc);

/* 生成节点  */
extern node_t *create_node(void *data, malloc_data mfunc, int size);

/* 释放节点 */
extern void free_node(node_t *node, free_data ffunc);

/* 插入节点 */
extern int insert_node(list_t *lst, node_t *node);

/* 删除节点 */
extern int delete_node(list_t *lst, node_t *node);

/* 查询节点 */
extern node_t *search_node(list_t *lst, visit vfunc, void *key);

/* 打印链表 */
extern void print_list(list_t *lst, print_data pfunc);

/* 遍历链表 */
extern void visit_list(list_t *list, visit vfunc, void *res);

/* 根据索引获取节点 */
extern node_t *get_node_by_index(list_t *list, int index);

/* 获取节点在链表中的索引 */
extern int get_index_by_node(list_t *list, node_t *node);

#endif
