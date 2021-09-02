#ifndef COMMON_H
#define COMMON_H

#define _GNU_SOURCE

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ncurses.h>

/*
 * Some keycode ncurses doesn't define
 */
#define KEY_ESCAPE 27
#define KEY_RETURN 10

/*
 * Temporary color definitions before the settings system is created
 */
#define UI_SEARCH 10
#define UI_LINE_NUMBERS 11
#define UI_STATUS 12

#define MINIMUM_CAPACITY 128

/*
 * The usage documentation of this application
 */
#define USAGE "usage: memo FILE"

/*
 * Mask for comparing against CTRL-pressed characters
 */
#define CTRL(k) ((k) & 0x1f)

/*
 * Assert a condition, quitting if false
 */
#define ASSERT(condition, ...)                  \
    if (!(condition)) {                         \
        fprintf(stderr, "error: ");             \
        fprintf(stderr, __VA_ARGS__);           \
        fprintf(stderr, "\n");                  \
        exit(1);                                \
    }

/*
 * Grow a capacity value incrementally
 */
#define GROW_CAPACITY(capacity) (max(capacity * 2, MINIMUM_CAPACITY))

/*
 * Grow an array to a capacity
 */
#define GROW_ARRAY(array, size, capacity)       \
    ((array)                                    \
     ? realloc(array, sizeof(size) * capacity)  \
     : malloc(sizeof(size) * capacity))

/*
 * Shift the elements of an array
 */
#define SHIFT_ARRAY(array, index, count, type, length)  \
    memmove(array + index + count,                      \
            array + index,                              \
            sizeof(type) * (length - (index)))

/*
 * Shift the elements of an array backwards
 */
#define BSHIFT_ARRAY(array, index, count, type, length)     \
    memmove(array + index,                                  \
            array + index + count,                          \
            sizeof(type) * (length - (index) - (count)))

/*
 * Get the minimum between two values
 * @param a int The first value
 * @param b int The second value
 * @return int The minimum value
 */
static inline int min(int a, int b)
{
    return (a < b) ? a : b;
}

/*
 * Get the minimum between two values
 * @param a int The first value
 * @param b int The second value
 * @return int The minimum value
 */
static inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

/*
 * Get the difference between two values
 * @param a int The first value
 * @param b int The second value
 * @return size_t The difference
 */
static inline size_t diff(int a, int b)
{
    return (a > b) ? a - b : b - a;
}

/*
 * 2D vectors
 */
typedef struct {
    size_t x;
    size_t y;
} Vec2D;

#endif // COMMON_H
