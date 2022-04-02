#include <linux/hashtable.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>

struct h_node {
    int data;
    struct hlist_node n;
};

DEFINE_HASHTABLE(ht, 3);

static u32 hash_func(int value, int size)
{
    u32 key = 0;
    key = value % size;

    return key;
}

static int __init h_init(void)
{
    struct h_node node_a, node_b, node_c, *curr;
    unsigned bkt;

    pr_info("Hello, hash table\n");
    pr_info("Is hash table empty? %u", hash_empty(ht));

    node_a.data = 4;
    node_b.data = 5;
    node_c.data = 12;

    u32 key_a = hash_func(4, 8);
    u32 key_b = hash_func(5, 8);
    u32 key_c = hash_func(12, 8);

    pr_info("key_a = %u\n", key_a);
    pr_info("key_b = %u\n", key_b);
    pr_info("key_c = %u\n", key_c);

    hash_init(ht);

    hash_add(ht, &node_a.n, key_a);
    hash_add(ht, &node_b.n, key_b);
    hash_add(ht, &node_c.n, key_c);

    hash_for_each(ht, bkt, curr, n) {
        pr_info("hash: data = %d, node = %p \n", curr->data, &curr->n);
    }

    hash_del(&node_a.n);
    hash_del(&node_b.n);
    hash_del(&node_c.n);

    return 0;
}

static void __exit h_exit(void)
{
    pr_info("Bye, hash table\n");
}

module_init(h_init);
module_exit(h_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Lee Wei");
