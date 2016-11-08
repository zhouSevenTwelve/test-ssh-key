#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"mysql.h"

int main(int argc, char *argv[])
{
	MYSQL *my_connection;
	int res;


	my_connection=mysql_init(NULL);
	if (mysql_real_connect(my_connection, "115.159.63.114",
		"hx", "123456", "demo", 0, NULL, 0)) {
		printf("Connection success\n");

		res = mysql_query(my_connection, "INSERT INTO user(name, password) VALUES('D.K', 1234567)");
		if (!res) {
			printf("Inserted %lu rows\n", (unsigned long)mysql_affected_rows(my_connection));
		}
		else {
			fprintf(stderr, "Insert error %d: %s\n", mysql_errno(my_connection),
				mysql_error(my_connection));
		}

		mysql_close(my_connection);
	}
	else {
		fprintf(stderr, "Connection failed\n");
		if (mysql_errno(my_connection)) {
			fprintf(stderr, "Connection error %d: %s\n",
				mysql_errno(my_connection), mysql_error(my_connection));
		}
	}

	return EXIT_SUCCESS;
}
