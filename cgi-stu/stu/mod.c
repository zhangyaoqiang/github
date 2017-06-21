#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "cgic.h"

char * footname = "footer.html";
char * headname ="head.html";

int cgiMain()
{


	FILE * fd;

		char sname[32] = "\0";
		char age[16] = "\0";
		char sno[32] = "\0";
		char address[32] ="\0";
		char sex[16] ="\0";
		char scno[32] ="\0";

		int status = 0;
		char ch;

	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");

	if(!(fd = fopen(headname, "r"))){
		fprintf(cgiOut, "Cannot open file, %s\n", headname);
		return -1;
	}
	ch = fgetc(fd);

	while(ch != EOF){
		fprintf(cgiOut, "%c", ch);
		ch = fgetc(fd);
	}
fclose(fd);

status = cgiFormString("sno",  sno, 32);
if (status != cgiFormSuccess)
{
	fprintf(cgiOut, "get sno error!\n");
	return 1;
}


status = cgiFormString("sname",  sname, 32);
if (status != cgiFormSuccess)
{
	fprintf(cgiOut, "get sname error!\n");
	return 1;
}


status = cgiFormString("address",  address, 32);
if (status != cgiFormSuccess)
{
	fprintf(cgiOut, "get address error!\n");
	return 1;
}


status = cgiFormString("age",  age, 16);
if (status != cgiFormSuccess)
{
	fprintf(cgiOut, "get age error!\n");
	return 1;
}



status = cgiFormString("sex",  sex, 32);
if (status != cgiFormSuccess)
{
	fprintf(cgiOut, "get sex error!\n");
	return 1;
}

status = cgiFormString("scno",  scno, 32);
if (status != cgiFormSuccess)
{
	fprintf(cgiOut, "get scno error!\n");
	return 1;
}


	//fprintf(cgiOut, "name = %s, age = %s, stuId = %s\n", name, age, stuId);

	int ret;
	char sql[128] = "\0";
	MYSQL *db;

	//初始化
	db = mysql_init(NULL);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_init fail:%s\n", mysql_error(db));
		return -1;
	}

	//连接数据库
	db = mysql_real_connect(db, "127.0.0.1", "root", "123456", "stu",  3306, NULL, 0);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_real_connect fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}


	sprintf(sql, "update information set sname='%s', address='%s',age= %d, sex='%s', scno=%d where sno = %d ",
	                                           sname, address, atoi(age), sex, atoi(scno), atoi(sno));
	if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
	{
		fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}



	fprintf(cgiOut, "update student ok!\n");
	mysql_close(db);
	return 0;
}
