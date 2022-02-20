#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "t_time.h"
#include "t_timetable.h"

t_timetable * t_timetable_init(int size) {
    t_timetable * tt;

    tt = (t_timetable *) malloc(sizeof(t_timetable));

    tt->table = (t_timetable_item*) malloc(sizeof(t_timetable_item)* size);
    tt->size = size;
    tt->n = 0;

    return tt;
}

void t_timetable_put(t_timetable * tt, t_time * key, char * value) {
    int i, j;

    if (tt->n ==tt->size) exit(-1);

    i = 0;
    while (i <tt->n && t_time_cmp(key,tt->table[i].key) > 0) {
        i++;
    }

    if (tt->n > i && t_time_cmp(key,tt->table[i].key) != 0) {
        for (j =tt->n - 1; j >= i; --j) {
            tt->table[j + 1].key =tt->table[j].key;
            tt->table[j + 1].value =tt->table[j].value;
        }
    }

    tt->table[i].key = key;
    tt->table[i].value = value;

    if (tt->n == i)tt->n++;
}

char * t_timetable_get(t_timetable *tt, t_time * key) {
    int start, end, middle, target;

    start = 0;
    end =tt->n - 1;

    while(start <= end) {
        middle = (start + end) / 2;

        target = t_time_cmp(tt->table[middle].key, key);

        if (target == 0) {
            return tt->table[middle].value;

        } else if (target == 1) {
            end = middle - 1;

        } else {
            start = middle + 1;
        }
    }
    return NULL;
}

t_time * t_timetable_min(t_timetable *tt) {
    return tt->table[0].key;
}
t_time * t_timetable_max(t_timetable *tt) {
    return tt->table[tt->n - 1].key;
}
t_time * t_timetable_floor(t_timetable *tt, t_time * key) {
    int target;

    for (int i =tt->n - 1; i >= 0; i--) {
        target = t_time_cmp(tt->table[i].key, key);

        if (target == -1 || target == 0) {
            return tt->table[i].key;
        }
    }
    return NULL;
}

t_time * t_timetable_ceiling(t_timetable *tt, t_time * key) {
    int target;

    for (int i = 0; i <=tt->n - 1; i++) {
        target = t_time_cmp(tt->table[i].key, key);

        if (target == 1 || target == 0) {
            return tt->table[i].key;
        }
    }
    return NULL;
}

void t_timetable_print(t_timetable *tt) {
    t_time * time;
    int i, h, m, s;

    for (i = 0; i <tt->n; ++i) {
        time =tt->table[i].key;

        h = t_time_get_h(time);
        m = t_time_get_m(time);
        s = t_time_get_s(time);

        printf("[%02d] - %02d:%02d:%02d => %s\n", i, h, m, s,tt->table[i].value);
    }
}