#pragma once
#ifndef C2MYSQL_H
#define C2MYSQL_H

#include <Windows.h>
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

class MyDB
{
public:
	// ���캯��
	MyDB();
	MyDB(string _dbName);
	MyDB(string _host, string _user, string _psw, string _dbName);
	// ��������
	~MyDB();
	// ���ݿ��ʼ������
	bool initDB();
	// ���ݿ�sqlִ�к���
	bool showAllSQL();
	
	bool selectSQL(string sql);
	void updateSQL(string sql);
	void deleteSQL(string sql);
	void insertSQL();

protected:
	bool executeSQL(string opType, string sql);
	string insertHelper();

private:
	// mysql����
	MYSQL connection;
	// mysqlִ�н����
	MYSQL_RES *result;
	MYSQL_ROW row;

	// ����host
	string host;
	// ���ݿ��¼�û�user
	string user;
	// ���ݿ��¼����psw
	string psw;
	// Ҫ���������ݿ�dbName
	string dbName;
};

#endif // !C2MYSQL_H