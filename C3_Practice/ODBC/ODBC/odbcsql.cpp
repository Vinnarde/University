#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

void showSQLError(SQLSMALLINT handleType, const SQLHANDLE& handle)
{
	SQLCHAR SQLState[1024];
	SQLCHAR message[1024];

	if (SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL) == SQL_SUCCESS)
	{
		std::cout << "SQL driver message: " << message <<
			"\nSQL state: " << SQLState << ".\n";
	}

}

int main()
{
	SQLHANDLE SQLEnvHandle = nullptr;
	SQLHANDLE SQLConnectionHandle = nullptr;
	SQLHANDLE SQLStatementHandle = nullptr;
	SQLRETURN retCode = 0;
	SQLCHAR SQLQuery[] = "SELECT Id, InsuranceAmount FROM Contracts";

	system("chcp 1251");
	system("cls");

	do
	{
		if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle) != SQL_SUCCESS)
			break;
		if (SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0) != SQL_SUCCESS)
			break;
		if (SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle) != SQL_SUCCESS)
			break;
		if (SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0) != SQL_SUCCESS)
			break;

		SQLCHAR retConString[1024];
		SQLCHAR conString[] = "DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=lab11; UID=user; PWD=password";

		switch (SQLDriverConnect(SQLConnectionHandle, nullptr, conString, SQL_NTS, retConString, 1024, nullptr, SQL_DRIVER_NOPROMPT))
		{
		case SQL_SUCCESS:
			break;
		case SQL_SUCCESS_WITH_INFO:
			break;
		case SQL_NO_DATA_FOUND:
		case SQL_INVALID_HANDLE:
		case SQL_ERROR:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;

		default:
			break;
		}

		if (retCode == -1)
			break;

		if (SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle) != SQL_SUCCESS)
			break;

		if (SQLExecDirect(SQLStatementHandle, SQLQuery, SQL_NTS) != SQL_SUCCESS)
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else
		{
			int id;
			char type[256];

			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), nullptr);
				SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &type, sizeof(type), nullptr);
				std::cout << id << '\t' << type  << '\n';
			}
		}

	} while (false);
}