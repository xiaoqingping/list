/**
 * example.h - 示例代码的头文件
 *
 * @author xiaoqingping [xiaoqingping@qq.com] 2016-9-8
 * @link     https://github.com/xiaoqingping/list
 * @license  MIT license
 * 
 */
#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_

/* 用户表 */ 
typedef struct user_s
{
    char uid[7];          /* 用户ID */
    char name[16];        /* 姓名 */
    char pwd[17];         /* 密码 */
    int type;             /* 用户类型，0为后台用户，2为前台用户 */
    int deltag;           /* 删除标志，0表示正常，1表示删除 */
    char remark[101];     /* 备注 */
} user_t;

/* 商品表 */
typedef struct goods_s
{
    char code[9];           /* 条形码 */
    char name[31];          /* 商品名称 */
    char unit[17];          /* 单位 */
    char spec[17];          /* 规格 */
    float saleprice;        /* 单价 */
    float inprice;          /* 进价 */
    int repcount;           /* 库存  */
    int amount;             /* 售卖数量 */
    float discount;         /* 折扣 */
    int deltag;             /* 删除标志 */
} goods_t;

/* 销售表 */
typedef struct sale_s
{
    char sid[19];   /* 销售单号 */
    char uid[7];    /* 雇员ID */
    char date[51];  /* 销售日期 */
    float rlprice;  /* 应付金额 */
    float uprice;   /* 实际金额 */
    float zprice;   /* 找零 */
} sale_t;

/* 销售明细表 */
typedef struct sale_info_s
{
    float id;       /* 销售明细ID */
    char code[9];   /* 商品条形码 */
    char sid[19];   /* 销售单号 */
    float count;    /* 数量 */
    float price;    /* 销售单价 */
}  sale_info_t;


extern user_t *malloc_user(int size);
extern goods_t *malloc_goods(int size);
extern sale_t *malloc_sale(int size);
extern sale_info_t *malloc_sale_info(int size);


extern void free_user(void *data);
extern void free_goods(void *data);
extern void free_sale(void *data);
extern void free_sale_info(void *data);

extern int find_user_by_name(void *data, void *key);
extern int find_user_by_id(void *data, void *key);
extern int find_goods_by_code(void *data, void *key);
extern int find_goods_by_name(void *data, void *key);
extern int get_full_price(void *data, void *res);
extern int find_sale_by_sid(void *data, void *key);
extern int find_sale_by_uid(void *data, void *key);
extern int find_sale_by_date(void *data, void *key);
extern int find_sale_info(void *data, void *key);


extern void print_user(void *data);
extern void print_goods_in_cashier(void *data);
extern void print_goods_in_admin(void *data);
extern void print_sale(void *data);
extern void print_sale_info_cashier(void *data);
extern void print_sale_info_admin(void *data);

#endif

