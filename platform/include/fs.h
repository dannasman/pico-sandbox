#ifndef FS_H
#define FS_H

#include <stddef.h>
#include <stdint.h>

#define FS_NODE(_type, _name, _read, _write)    \
{                                               \
    .type = _type,                              \
    .name = #_name,                             \
    .ops = {                                    \
        .read = &_read,                         \
        .write = &_write                        \
    }                                           \
}

enum fs_type {
    FS_FILE,
    FS_DIR,
    FS_DEV,
};

struct fs_ops {
    void (*read)(char *, size_t);
    void (*write)(const char *);
};

struct fs_node {
    enum fs_type type;
    const char *name;
    struct fs_node *parent;
    struct fs_node *next;
    struct fs_node *children;
    const struct fs_ops *ops;
};

void fs_led_init(void);
void fs_time_init(void);

void fs_add_dev(const char *, const struct fs_ops *);
void fs_init(void);
struct fs_node *fs_find(const char *);

#endif
