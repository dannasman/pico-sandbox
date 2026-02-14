#include <led.h>
#include <lib/alloc.h>
#include <lib/string.h>

#include <pl011.h>

#include "fs.h"

static struct fs_node *nroot;
static struct fs_node *ncur;

static void fs_add_child(struct fs_node *node,
                         const char *name,
                         enum fs_type type,
                         const struct fs_ops *ops)
{
    struct fs_node *prev;
    struct fs_node *next;

    next = (struct fs_node *)p2s_alloc(sizeof(struct fs_node));
    if (next == NULL) {
        return;
    }
    next->type = type;
    next->name = name;
    next->parent = node;
    next->next = NULL;
    next->children = NULL;
    next->ops = ops;

    prev = node->children;
    node->children = next;
    node->children->next = prev;
}

struct fs_node *fs_find(const char *str) {
    uint32_t i, sz;
    char buf[256];
    const char *name;
    struct fs_node *node;

    sz = 0;
    while (*str != '\0' && sz < 255) {
        if (*str == '/') buf[sz] = '\0';
        else buf[sz] = *str;
        str++;
        sz++;
    }

    buf[sz] = '\0';
    sz++;
    node = ncur;

    i = 0;
    while (i < sz && node != NULL) {
        name = &buf[i];
        if (strcmp(name, node->name) == 0) {
            i += strlen(name) + 1;
            if (i < sz) {
                node = node->children;
            }
        } else {
            node = node->next;
        }
    }

    return node;
}

#if 0
static void fs_init_dev(void) {
    struct fs_node *dev;

    dev = (struct fs_node *)p2s_alloc(sizeof(struct fs_node));
    dev->type = FS_DIR;
    dev->name = "dev";
    dev->parent = nroot;
    dev->children = NULL;
    dev->ops = NULL;


    fs_add_child(dev, "uart", FS_DEV, NULL);
    fs_add_child(dev, "led", FS_DEV, &fs_led_ops);

    nroot->children = dev;
}
#endif

void fs_add_dev(const char *name, const struct fs_ops *ops) {
    fs_add_child(nroot, name, FS_DEV, ops);
}

static void fs_init_dev(void) {
    fs_led_init();
    fs_time_init();
}

void fs_init(void) {
    nroot = (struct fs_node *)p2s_alloc(sizeof(struct fs_node));
    if (nroot == NULL)
        uart_puts("nroot is NULL\n");
    nroot->type = FS_DIR;
    nroot->name = "";
    nroot->parent = NULL;
    nroot->next = NULL;
    nroot->children = NULL;
    nroot->ops = NULL;

    ncur = nroot;

    fs_init_dev();
}
