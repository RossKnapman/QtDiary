#include "databasehandler.h"

DatabaseHandler::DatabaseHandler()
{
    // Initialise
    DatabaseConnect();
    DatabaseInit();
}

void DatabaseHandler::DatabaseConnect()
{
    const QString DRIVER("QSQLITE");

    // Connect to the database
    // Note that, for SQLite, opening a database also creates it
    if (QSqlDatabase::isDriverAvailable(DRIVER))
    {
        QSqlDatabase m_db = QSqlDatabase::addDatabase(DRIVER);

        const QString desktopFolder = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        m_db.setDatabaseName(desktopFolder + "/SomeDatabase.sqlite3");

        if (!m_db.open())
            qWarning() << "DatabaseHandler::DatabaseConnect - ERROR: " << m_db.lastError().text();
    }
    else
        qWarning() << "DatabaseHandler::DatabaseConnect - ERROR: no driver " << DRIVER << " available";
}

void DatabaseHandler::DatabaseInit()
{
    QSqlQuery query("CREATE TABLE entries (id INTEGER PRIMARY KEY, entry TEXT)");

    // Check if the statement was successful
    if (!query.isActive())
        qWarning() << "DatabaseHandler::DatabaseInit - ERROR: " << query.lastError().text();
}

void DatabaseHandler::DatabaseInsert(const QString& entry)
{
    QSqlQuery query;
    query.prepare("INSERT INTO entries (entry) VALUES (:entry)");
    query.bindValue(":entry", entry);
    if (!query.exec())
            qWarning() << "DatabaseHandler::DatabaseInsert - ERROR: " << query.lastError().text();
}

QSqlQuery DatabaseHandler::GetAllEntries()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM entries;");
    if (!query.exec())
    {
        qWarning() << "DatabaseHandler::GetAllEntries - ERROR: " << query.lastError().text();
    }
    else
    {
        return query;
    }
}

QString DatabaseHandler::getEntry(const int& id)
{
    QSqlQuery query;
    query.prepare("SELECT entry FROM entries WHERE id=:id");
    query.bindValue(":id", id);
    if (!query.exec())
    {
        qWarning() << "DatabaseHandler::getEntry - ERROR: " << query.lastError().text();
    }
    query.next();
    QString entry = query.value(0).toString();
    qDebug() << entry;
    return entry;
}
