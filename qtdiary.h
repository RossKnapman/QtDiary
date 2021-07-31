#ifndef QTDIARY_H
#define QTDIARY_H

#include <QMainWindow>
#include <QPushButton>
#include "databasehandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtDiary; }
QT_END_NAMESPACE

class QtDiary : public QMainWindow
{
    Q_OBJECT

public:
    QtDiary(QWidget *parent = nullptr);
    ~QtDiary();

private slots:
    void on_saveButton_clicked();

private:
    Ui::QtDiary *ui;
    DatabaseHandler *dbHandler = new DatabaseHandler;
};
#endif // QTDIARY_H
