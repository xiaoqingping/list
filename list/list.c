/**
 * list.c - 通用链表实现
 *
 * 将针对链表的常用操作：节点空间申请，节点空间释放，遍历节点，打印等等使用函数指针定义
 * 在遍历节点的基础上可以实现诸如链表节点的搜索、更新、排序等等操作。
 * 该链表的通用性极好，使用者只需要根据自己的情况实现相应的节点操作函数即可，其余的工作由链表模块自己完成
 * 
 * @author   xiaoqingping [xiaoqingping@qq.com] 2016-9-8
 * @link     https://github.com/xiaoqingping/list
 * @license  MIT license
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/* 初始化链表头 */
extern list_t *init_head()
{
    list_t *lst;

    /* 申请空间 */
    lst = (list_t *)malloc(sizeof(list_t));
    if (lst == NULL)
    {
        return NULL;
    }

    /* 初始化 */
    lst->head = NULL;
    lst->tail = NULL;
    lst->len = 0;

    return lst;
}

/* 删除链表 */
extern void *del_list(list_t *lst, free_data ffunc)
{
    node_t *temp;

    if (lst == NULL || lst->len == 0)
    {
        return;
    }

    temp = lst->head;
    while (temp)
    {
        lst->head = lst->head->next; /* 头指针下移 */
        temp->next = NULL; 
        free_node(temp, ffunc);   /* 释放节点 */
        temp = lst->head;
    }

    lst->tail = NULL;
    free(lst);
    lst = NULL;
}

/* 生成节点 */
extern node_t *create_node(void *data, malloc_data mfunc, int size)
{
    node_t *node;

    node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL)
    {
        return NULL;
    }

    node->data = mfunc(size);   /* 申请空间 */
    memcpy(node->data, data, size);
    node->next = NULL;

    return node;
}

/* 释放节点 */
extern void free_node(node_t *node, free_data ffunc)
{
    if (node == NULL)
    {
        return;
    } 

    ffunc(node->data);
    free(node);
}


/* 插入节点 */
extern int insert_node(list_t *lst, node_t *node)
{
    if (lst == NULL || node == NULL)
    {
        return -1;
    }

    if (lst->head == NULL)
    {
        lst->head = node;
        lst->tail = node;
    }
    else
    {
        lst->tail->next = node;
        lst->tail = node;
    }

    lst->len++;

    return 0;
}

/* 删除节点 */
extern int delete_node(list_t *lst, node_t *node)
{
    if (lst == NULL || node == NULL)
    {
        return -1;
    }
}

/* 查询节点 */
extern node_t *search_node(list_t *lst, visit comparefunc, void *key)
{
    node_t *temp;

    if(lst == NULL || lst->len == 0 || comparefunc == NULL)
    {
        return NULL;
    }

    for (temp = lst->head; temp != NULL; temp = temp->next)
    {
        if (comparefunc(temp->data, key) == 0)      /* 比较 */
        {
            return temp;
        }
    }

    return NULL;
}

/* 打印链表 */
extern void print_list(list_t *lst, print_data pfunc)
{
    node_t *node; 

    if (lst == NULL || lst->len == 0 || pfunc == NULL)
    {
        return;
    }

    for (node = lst->head; node != NULL; node = node->next)
    {
        pfunc(node->data);
    }
}

/* 遍历链表 */
extern void visit_list(list_t *lst, visit vfunc, void *res)
{
    node_t *temp;

    if(lst == NULL || lst->len == 0 || vfunc == NULL)
    {
        return;
    }

    for (temp = lst->head; temp != NULL; temp = temp->next)
    {
        vfunc(temp->data, res);
    }
}

/* 根据索引获取节点 */
extern node_t *get_node_by_index(list_t *lst, int index)
{
    node_t *node;
    int i = 0;

    if (lst == NULL || lst->len == 0)
    {
        return NULL;
    }

    if (index > lst->len)
    {
        return NULL;
    } 

    for (node = lst->head; node != NULL; node = node->next)
    {
        i++;
        if (index == i)
        {
            return node;
        }
    }

    return NULL;
}

/* 获取节点在链表中的索引 */
extern int get_index_by_node(list_t *lst, node_t *node)
{
    node_t *temp;
    int index = 0;;

    if (lst == NULL || lst->len == 0)
    {
        return 0;
    }

    for (temp = lst->head; temp != NULL; temp = temp->next)
    {
        index++;
        if (temp == node)
        {
            return index;
        }
    }

    return 0;
}
