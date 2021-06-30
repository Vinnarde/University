#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

/******************************************/
/* Structure to store information about   */
/* a column.
/******************************************/

struct BINDING {
	SQLSMALLINT cDisplaySize;	/* size to display  */
	CHAR* szBuffer;				/* display buffer   */
	SQLLEN indPtr;              /* size or null     */
	BOOL fChar;                 /* character col?   */
	struct BINDING* sNext;		/* linked list      */
};

void DisplayResults(HSTMT hStmt, SQLSMALLINT cCols);

void AllocateBindings(HSTMT         hStmt,
	SQLSMALLINT   cCols,
	BINDING** ppBinding,
	SQLSMALLINT* pDisplay);

//void DisplayTitles(HSTMT hStmt,
//	DWORD    cDisplaySize,
//	BINDING* pBinding);

void showSQLError(SQLSMALLINT handleType,
	const SQLHANDLE& handle)
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
	//SQLCHAR SQLQuery[] = "SELECT * FROM Contracts Join InsuranceType ON Contracts.InsuranceType = InsuranceType.id Where Contracts.InsuranceAmount >= ? AND DATE BETWEEN ? AND ? Order By Contracts.InsuranceAmount ";
	//SQLCHAR SQLQuery[] = "SELECT * FROM InsuranceType WHERE LOWER(Type) LIKE %?%";
	//SQLCHAR SQLQuery[] = "SELECT * FROM InsuranceType WHERE LOWER(Type) LIKE '%упер%'";
	//SQLCHAR SQLQuery[] = "SELECT * FROM InsuranceType WHERE LOWER(Type) = ?";

	//SQLCHAR SQLQuery[] = "SELECT * FROM Contracts WHERE insuranceAmount > ?  AND  id <= ?";
	SQLCHAR SQLQuery[] = "SELECT * FROM Contracts WHERE Id = ?";

	system("chcp 1251");
	system("cls");

	do
	{
		// Allocate an environment
		if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle) != SQL_SUCCESS)
			break;

		// Register this as an application that expects 3.x behavior,
		// you must register something if you use AllocHandle
		if (SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0) != SQL_SUCCESS)
			break;

		// Allocate a connection
		if (SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle) != SQL_SUCCESS)
			break;

		if (SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0) != SQL_SUCCESS)
			break;

		SQLCHAR retConString[1024];
		SQLCHAR conString[] = "DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=lab11; UID=user; PWD=password";

		// Connect to the driver. Use the connection string supplied
		// on the input.
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


		SQLCHAR param1[] = "7";
		SQLINTEGER param1LenOrInd = SQL_NTS;
		SQLBindParameter(SQLStatementHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, param1, sizeof(param1), &param1LenOrInd);
		//strcpy_s((char*)param1, _countof(param1), "упер");
		param1LenOrInd = SQL_NTS;

		//SQLCHAR param2[] = "2021-05-01";
		//SQLINTEGER param2LenOrInd;
		//SQLBindParameter(SQLStatementHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, param2, sizeof(param2), &param2LenOrInd);
		////strcpy_s((char*)param2, _countof(param2), "упер");
		//param2LenOrInd = SQL_NTS;

		//SQLCHAR param3[] = "2021-07-01";
		//SQLINTEGER param3LenOrInd;
		//SQLBindParameter(SQLStatementHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, param3, sizeof(param3), &param3LenOrInd);
		////strcpy_s((char*)param3, _countof(param3), "упер");
		//param3LenOrInd = SQL_NTS;

		/*SQLINTEGER CustIDInd1;
		SQLUINTEGER CustID1;
		SQLBindParameter(SQLStatementHandle, 1, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 10, 0,
			&CustID1, 0, &CustIDInd1);

		CustID1 = 2500;
		CustIDInd1 = 0;

		SQLINTEGER CustIDInd;
		SQLUINTEGER CustID;
		SQLBindParameter(SQLStatementHandle, 2, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 10, 0,
			&CustID, 0, &CustIDInd);

		CustID = 10;
		CustIDInd = 0;*/

		if (SQLExecDirect(SQLStatementHandle, SQLQuery, SQL_NTS) != SQL_SUCCESS)
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}
		else
		{
			SQLSMALLINT sNumResults;
			SQLNumResultCols(SQLStatementHandle, &sNumResults);

			if (sNumResults > 0)
			{
				DisplayResults(SQLStatementHandle, sNumResults);
			}

			//while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			//{

			//	//std::cout << id << '\t' << type << '\n';
			//}
		}

	} while (false);
}

void DisplayResults(HSTMT hStmt, SQLSMALLINT cCols)
{
	BINDING* pFirstBinding, * pThisBinding;
	SQLSMALLINT cDisplaySize;
	RETCODE RetCode = SQL_SUCCESS;

	// Allocate memory fo each column
	AllocateBindings(hStmt, cCols, &pFirstBinding, &cDisplaySize);

	//DisplayTitles(hStmt, cDisplaySize + 1, pFirstBinding);

	bool fNoData = false;

	do
	{
		RetCode = SQLFetch(hStmt);

		if (RetCode == SQL_NO_DATA_FOUND)
			fNoData = true;
		else
		{
			for (pThisBinding = pFirstBinding;
				pThisBinding != nullptr;
				pThisBinding = pThisBinding->sNext)
			{
				if (pThisBinding->indPtr != SQL_NULL_DATA)
				{
					/*printf(pThisBinding->fChar ? DISPLAY_FORMAT_C : DISPLAY_FORMAT,
						PIPE,
						pThisBinding->cDisplaySize,
						pThisBinding->cDisplaySize,
						pThisBinding->wszBuffer);*/
					std::cout << pThisBinding->szBuffer << ", ";
				}
				else
				{
					/*printf(DISPLAY_FORMAT_C,
						PIPE,
						pThisBinding->cDisplaySize,
						pThisBinding->cDisplaySize,
						"<NULL>");*/

					std::cout << "<NULL>" << ", ";
				}
			}
			//wprintf(L" %c\n", PIPE);
			std::cout << '\n';
		}
	} while (!fNoData);

}

void AllocateBindings(HSTMT         hStmt,
	SQLSMALLINT   cCols,
	BINDING** ppBinding,
	SQLSMALLINT* pDisplay)
{
	SQLSMALLINT     iCol;
	BINDING* pThisBinding, * pLastBinding = NULL;
	SQLLEN          cchDisplay, ssType;
	//SQLSMALLINT     cchColumnNameLength;

	*pDisplay = 0;

	for (iCol = 1; iCol <= cCols; ++iCol)
	{
		pThisBinding = (BINDING*)malloc(sizeof(BINDING));
		if (pThisBinding == nullptr)
		{
			std::cout << "Out of memory\n";
			exit(-100);
		}

		if (iCol == 1)
		{
			*ppBinding = pThisBinding;
		}
		else
		{
			pLastBinding->sNext = pThisBinding;
		}
		pLastBinding = pThisBinding;

		SQLColAttribute(hStmt,
			iCol,
			SQL_DESC_DISPLAY_SIZE,
			NULL,
			0,
			NULL,
			&cchDisplay);

		SQLColAttribute(hStmt,
			iCol,
			SQL_DESC_CONCISE_TYPE,
			NULL,
			0,
			NULL,
			&ssType);

		pThisBinding->fChar = (ssType == SQL_CHAR ||
			ssType == SQL_VARCHAR ||
			ssType == SQL_LONGVARCHAR);

		pThisBinding->sNext = nullptr;

		// Allocate a buffer big enough to hold the text representation
		// of the data.  Add one character for the null terminator
		pThisBinding->szBuffer = (CHAR*)malloc((cchDisplay + 1) * sizeof(CHAR));

		if (!(pThisBinding->szBuffer))
		{
			fwprintf(stderr, L"Out of memory!\n");
			exit(-100);
		}

		SQLBindCol(hStmt,
			iCol,
			SQL_C_TCHAR,
			(SQLPOINTER)pThisBinding->szBuffer,
			(cchDisplay + 1) * sizeof(CHAR),
			&pThisBinding->indPtr);

		//SQLColAttribute(hStmt,
		//	iCol,
		//	SQL_DESC_NAME,
		//	NULL,
		//	0,
		//	&cchColumnNameLength,
		//	NULL);

		//pThisBinding->cDisplaySize = max((SQLSMALLINT)cchDisplay, cchColumnNameLength);
		pThisBinding->cDisplaySize = (SQLSMALLINT)cchDisplay;
		*pDisplay += pThisBinding->cDisplaySize;
	}
}

//void DisplayTitles(HSTMT     hStmt,
//	DWORD     cDisplaySize,
//	BINDING* pBinding)
//{
//	CHAR           szTitle[DISPLAY_MAX];
//	SQLSMALLINT     iCol = 1;
//
//	cDisplaySize++;
//	//SetConsole(cDisplaySize + 2, TRUE);
//
//	for (; pBinding; pBinding = pBinding->sNext)
//	{
//
//		SQLColAttribute(hStmt,
//			iCol++,
//			SQL_DESC_NAME,
//			szTitle,
//			sizeof(szTitle), // Note count of bytes!
//			NULL,
//			NULL);
//
//		printf(DISPLAY_FORMAT_C,
//			PIPE,
//			pBinding->cDisplaySize,
//			pBinding->cDisplaySize,
//			szTitle);
//	}
//	//
//	//Exit:
//	//
//	//	printf(" %c", PIPE);
//	//	//SetConsole(cDisplaySize + 2, FALSE);
//	//	printf("\n");
//
//}