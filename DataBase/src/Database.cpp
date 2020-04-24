#include <stdio.h>
#include <sqlite3.h>

static void init_temperature_table(void);
static void init_moisture_table(void);

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}
void init_data_base()
{
    init_temperature_table();
    init_moisture_table();
}
sqlite3* open_data_base(void)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_open("test.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(NULL);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);
    return db;
}
bool close_data_base(int rc,sqlite3* db, char* zErrMsg)
{
    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } 
    else {
        fprintf(stdout, "Table created successfully\n");
    }
    sqlite3_close(db);
}
static void init_temperature_table(void)
{
    sqlite3* db = open_data_base();
    char *zErrMsg = 0;
    int rc;
    const char *sql = "CREATE TABLE Sensor_temp (Time DATETIME, Value INT)";
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    close_data_base(rc,db,zErrMsg);
}

static void init_moisture_table(void)
{
    sqlite3* db = open_data_base();
    char *zErrMsg = 0;
    int rc;
    const char *sql = "CREATE TABLE Sensor_Humidity (Time DATETIME, Value INT)";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    close_data_base(rc,db,zErrMsg);
}
void push_data_temp(float value) //TODO check how to import time as string?
{
    sqlite3* db = open_data_base();
    int rc;
    char *zErrMsg = 0;
    char sql[60]={0};
    sprintf(sql,"INSERT INTO Sensor_temp VALUES(GETDATE(),%.2f)",value);
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    close_data_base(rc,db,zErrMsg);
}
void push_data_hum(float value) //TODO check how to import time as string?
{
    sqlite3* db = open_data_base();
    int rc;
    char *zErrMsg = 0;
    char sql[60]={0};
    sprintf(sql,"INSERT INTO Sensor_Humidity VALUES(GETDATE(),%.2f)",value);
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    close_data_base(rc,db,zErrMsg);
}
