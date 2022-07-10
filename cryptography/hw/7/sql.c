#include <stdio.h>
#include <sqlite3.h>

int callback(void * data, int argc, char ** argv, char ** header)
{
    for(int i = 0; i < argc; ++i)
    	printf("%s : %s\n", header[i], argv[i]);
    printf("\n");
    return 0;
}

int main()
{
	char * er;
	sqlite3 * db;
	int r1 = sqlite3_open("msgdb", &db);
	if(r1)
		printf("open\n");
	int r2 = sqlite3_exec(db, "select * from tb1;", callback, 0, &er);
	if(r2)
		printf("exec\n");
	sqlite3_close(db);
}
