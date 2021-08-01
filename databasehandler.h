#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QDir>

class DatabaseHandler
{
public:
    DatabaseHandler();
    void DatabaseConnect();
    void DatabaseInit();
    void DatabaseInsert(const QString&);
    QSqlQuery GetAllEntries();
    QString getEntry(const int&);

private:
    QSqlDatabase m_db;
};

#endif // DATABASEHANDLER_H
