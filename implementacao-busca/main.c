#include <stdio.h>
#include <stdlib.h>

#include "t_time.h"
#include "t_timetable.h"

size_t getline(char **pString, size_t *pInt, FILE *pIobuf);

int main(){
    t_time *time;
    t_timetable * tt;

    char * string;
    size_t length;

    int h, m, s, size;
    fflush(stdin);
    scanf("%d", &size);
    tt = t_timetable_init(size);
    fflush(stdin);
    scanf("%d:%d:%d", &h, &m, &s);
    while(h >= 0) {
        fflush(stdin);
        getchar();

        time = t_time_init(h, m, s);

        string = NULL;
        length = getline(&string, &length, stdin);
        string[length-1] = '\0';

        t_timetable_put(tt, time, string);
        fflush(stdin);
        scanf("%d:%d:%d", &h, &m, &s);
    }

    t_timetable_print(tt);

    scanf("%d:%d:%d", &h, &m, &s);
    while(h >= 0) {
        time = t_time_init(h, m, s);
        string = t_timetable_get(tt, time);

        if(string) {
            printf("%02d:%02d:%02d => %s\n", h, m, s, string);
        } else {
            printf("%02d:%02d:%02d => No Occurrence\n", h, m, s);
        }
        scanf("%d:%d:%d", &h, &m, &s);
    }

    t_time * timeMin = t_timetable_min(tt);
    printf("min: %02d:%02d:%02d\n", timeMin->h, timeMin->m, timeMin->s);

    t_time * timeMax = t_timetable_max(tt);
    printf("max: %02d:%02d:%02d\n", timeMax->h, timeMax->m, timeMax->s);

    t_time * key = t_time_init(9, 20, 0);

    t_time * timeFloor = t_timetable_floor(tt, key);
    if (timeFloor != NULL) {
        printf("floor: %02d:%02d:%02d\n", timeFloor->h, timeFloor->m, timeFloor->s);
    }

    t_time * timeCeiling = t_timetable_ceiling(tt, key);
    if (timeCeiling != NULL) {
        printf("ceiling: %02d:%02d:%02d\n", timeCeiling->h, timeCeiling->m, timeCeiling->s);
    }
}

size_t getline(char **pString, size_t *pInt, FILE *pIobuf) {
    return 0;
}
