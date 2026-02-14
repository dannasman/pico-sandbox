#include <time.h>
#include <lib/string.h>
#include <pl011.h>

#include "fs.h"

static void fs_time_read(char *buf, size_t n)
{
    const uint64_t t = current_us();
    if (n >= 21) {
        char tbuf[21];
        const char *tstr = u64_to_str(t, tbuf);
        for (size_t i = 0; i < 21; i++) buf[i] = tstr[i];
    }
}

static const struct fs_ops fs_time_ops = {
    .read = &fs_time_read,
};

void fs_time_init(void) {
    fs_add_dev("time", &fs_time_ops);
}
