#include <fs.h>
#include <lib/alloc.h>
#include <lib/string.h>
#include <pl011.h>

#include "shell.h"

#define OUT_BUF_SIZE    4096

static char shell_out_buf[OUT_BUF_SIZE];

static void shell_output_clear(void) {
    for (size_t i = 0; i < OUT_BUF_SIZE; i++) shell_out_buf[i] = 0;
}

static void shell_clear(const char *args, uint32_t sz) {
    if (sz > 0)
        uart_puts(args);
}

static void shell_echo(const char *args, uint32_t sz) {
    uint32_t len;
    uint32_t input_len;
    const char *input;
    const char *str;

    input = args;
    input_len = strlen(input);
    if (input_len + 1 < sz) {
        str = &args[input_len+1];
        if (strcmp(str, ">") == 0) {
            len = strlen(str);
            if (len + 1 < sz) {
                str = &str[len + 1];
                const struct fs_node *node = fs_find(str);
                if (node != NULL) {
                    if (node->ops != NULL) {
                        if (node->ops->write != NULL) {
                            node->ops->write(input);
                        }
                    }
                } else {
                    uart_puts("File ");
                    uart_puts(str);
                    uart_puts(" not found");
                }
            }
        }
    }
}

static void shell_cat(const char *args, uint32_t sz) {
    const char *str;

    str = args;
    const struct fs_node *node = fs_find(str);
    if (node != NULL) {
        if (node->ops != NULL) {
            if (node->ops->read != NULL) {
                node->ops->read(shell_out_buf, OUT_BUF_SIZE);
            }
        }
    } else {
        uart_puts("File ");
        uart_puts(str);
        uart_puts(" not found");
    }
}

static void shell_ls(const char *args, uint32_t sz) {
    if (sz > 0)
        uart_puts(args);
}

static void shell_process_command(const char *cmd, uint32_t sz) {
    uint32_t len;
    const char *str;
    const char *args;

    str = cmd;
    len = strlen(str) + 1;
    args = &cmd[len];

    if (strcmp(str, "clear") == 0) {
        shell_clear(args, sz - len);
    } else if (strcmp(str, "ls") == 0) {
        shell_ls(args, sz - len);
    } else if (strcmp(str, "cat") == 0) {
        shell_cat(args, sz - len);
    } else if (strcmp(str, "echo") == 0) {
        shell_echo(args, sz - len);
    } else {
        uart_puts("Command not found");
    }
}

void shell_run(void)
{
    char ch;
    uint32_t i;
    char cmd[256];

    for (;;){
        uart_putc('>');
        uart_putc(' ');

        ch = uart_getc();
        uart_putc(ch);
        i = 0;
        while ((ch != '\n' && ch != '\r') && i < 255) {
            if (ch == ' ' || ch == '\t') {
                cmd[i] = '\0';
                i++;
                while (ch == ' ' || ch == '\t') {
                    ch = uart_getc();
                    uart_putc(ch);
                }
            }
            cmd[i] = ch;
            ch = uart_getc();
            uart_putc(ch);
            i++;
        }
        cmd[i] = '\0';
        i++;

        shell_process_command(cmd, i);
        uart_puts(shell_out_buf);
        shell_output_clear();

        uart_putc('\n');
    }
}

void shell_init(void)
{
    return;
}
