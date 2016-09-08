/**
 * example.c - 示例代码
 *
 * 一个使用通用链表的小程序
 * 
 * @author xiaoqingping [xiaoqingping@qq.com] 2016-9-8
 * @link     https://github.com/xiaoqingping/list
 * @license  MIT license
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "example.h"

extern user_t *malloc_user(int size)
{
    user_t *user;

    user = (user_t *)malloc(size);
    if (user == NULL)
    {
        return NULL;
    }
    memset(user, 0, size);

    return user;
}

extern goods_t *malloc_goods(int size)
{
    goods_t *goods;

    goods = (goods_t *)malloc(size);
    if (goods == NULL)
    {
        return NULL;
    }
    memset(goods, 0, size);

    return goods;
}

extern sale_t *malloc_sale(int size)
{
    sale_t *sale;

    sale = (sale_t *)malloc(size);
    if (sale == NULL)
    {
        return NULL;
    }
    memset(sale, 0, size);

    return sale;
}

extern sale_info_t *malloc_sale_info(int size)
{
    sale_info_t *sale_info;

    sale_info = (sale_info_t *)malloc(size);
    if (sale_info == NULL)
    {
        return NULL;
    }
    memset(sale_info, 0, size);

    return sale_info;
}

extern void free_user(void *data)
{
    static int i = 0; 

    i++;
    printf("Free 第%d个节点\n", i);
    user_t *user = (user_t *)data;
    free(user);
}

extern void free_goods(void *data)
{
    goods_t *goods = (goods_t *)data;
    free(goods);
}

extern void free_sale(void *data)
{
    sale_t *sale = (sale_t *)data; 
    free(sale);
} 

extern void free_sale_info(void *data)
{
    sale_info_t *sale_info = (sale_info_t *)data;
    free(sale_info);
}

extern int find_user_by_name(void *data, void *key)
{
    user_t *user = (user_t *)data;
    char *name = (char *)key;

    return strcmp(user->name, name);
}

extern int find_user_by_id(void *data, void *key)
{
    user_t *user = (user_t *)data;
    char *id = (char *)key;

    return strcmp(user->uid, id);
}

extern int find_goods_by_code(void *data, void *key)
{
    goods_t *goods = (goods_t *)data;
    char *code = (char *)key;

    return strcmp(goods->code, code);
}

extern int find_goods_by_name(void *data, void *key)
{
    goods_t *goods = (goods_t *)data;
    char *name = (char *)key;

    return strcmp(goods->name, name);
}

extern int get_full_price(void *data, void *res)
{
    goods_t *goods = (goods_t *)data;
    float *price = (float *)res;
    *price += goods->saleprice * goods->amount;

    return *price;

}

extern int find_sale_by_sid(void *data, void *key)
{
    sale_t *sale = (sale_t *)data;
    char *sid = (char *)key;

    return strcmp(sale->sid, sid);
}

extern int find_sale_by_uid(void *data, void *key)
{
    sale_t *sale = (sale_t *)data;
    char *uid = (char *)key;

    return strcmp(sale->uid, uid);
}

extern int find_sale_by_date(void *data, void *key)
{
    sale_t *sale = (sale_t *)data;
    char *date = (char *)key;

    return strcmp(sale->date, date);
}

extern int find_sale_info(void *data, void *key)
{
    sale_info_t *sale_info = (sale_info_t *)data;
    int *id = (int *)key;

    return (sale_info->id == *id) ? 0 : 1;
}

extern void print_user(void *data)
{
    user_t *user = (user_t *)data;
}

extern void print_goods_in_cashier(void *data)
{
    goods_t *goods = (goods_t *)data;
}

extern void print_goods_in_admin(void *data)
{
    goods_t *goods = (goods_t *)data;
}

extern void print_sale(void *data)
{
    sale_t *sale = (sale_t *)data;
} 

extern void print_sale_info_cashier(void *data)
{
    sale_info_t *sale_info = (sale_info_t *)data;
}

extern void print_sale_info_admin(void *data)
{
    sale_info_t *sale_info = (sale_info_t *)data;
} 

int main(void)
{
    node_t *node;
    list_t *l = init_head();
    user_t user;

    memset(&user, 0, sizeof(user));
    strcpy(user.uid, "000001");
    strcpy(user.name, "1234567");
    strcpy(user.pwd, "123456");
    user.type = 1; 

    node = create_node((void *)&user, (void *)malloc_user, sizeof(user));
    insert_node(l, node);
    print_list(l, print_user); 

    node = create_node((void *)&user, (void *)malloc_user, sizeof(user));
    insert_node(l, node);
    print_list(l, print_user); 

    node = create_node((void *)&user, (void *)malloc_user, sizeof(user));
    insert_node(l, node);
    print_list(l, print_user); 

    node = create_node((void *)&user, (void *)malloc_user, sizeof(user));
    insert_node(l, node);
    print_list(l, print_user); 

    del_list(l, free_user); 

    return 0;
}
