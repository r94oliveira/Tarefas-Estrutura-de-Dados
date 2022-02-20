#include <stdio.h>
#include <stdlib.h>
#include "t_time.h"
#include "t_timetable.h"

size_t getline(char **pString, size_t *pInt, FILE *pIobuf);

int main(){

	t_time *ta;
	t_timetable * tt;
	char * str;
	size_t len;

	int h,m,s,size;
    printf("Tamanho: ");
	scanf("%d",&size);
	tt = t_timetable_init(size);
    fflush(stdin);
    printf("Horario: ");
	scanf("%d:%d:%d",&h,&m,&s);
    fflush(stdin);

	while(h >= 0){
        printf("getchar");
		getchar();
        printf("1...");
		ta = t_time_init(h,m,s);
        printf("2...");
		// read string
        fflush(stdin);
		str = NULL;
        printf("3...");
		len = getline(&str, &len, stdin);
        printf("4...");
		str[len-1] = '\0';
        printf("5...");
		t_timetable_put(tt,ta,str);
		//t_timetable_put_seq(tt,ta,str);
        printf("6...");
        fflush(stdin);
        printf("Horario: ");
		scanf("%d:%d:%d",&h,&m,&s);
	}

	t_timetable_print(tt);

	scanf("%d:%d:%d",&h,&m,&s);
	while(h >= 0){
		ta = t_time_init(h,m,s);
		str = t_timetable_get(tt,ta);
		//str = t_timetable_get_seq(tt,ta);

		if(str)
			printf("%02d:%02d:%02d => %s\n",h,m,s,str);
		else
			printf("%02d:%02d:%02d => nao encontrado\n",h,m,s);

		scanf("%d:%d:%d",&h,&m,&s);
	}
}

size_t getline(char **pString, size_t *pInt, FILE *pIobuf) {
    return 0;
}
