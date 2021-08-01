#ifndef QTDIARY_H
#define QTDIARY_H

#include <QMainWindow>
#include <QPushButton>
#include "databasehandler.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QScrollArea>

QT_BEGIN_NAMESPACE
namespace Ui { class QtDiary; }
QT_END_NAMESPACE

class QtDiary : public QMainWindow
{
    Q_OBJECT

public:
    QtDiary(QWidget *parent = nullptr);
    ~QtDiary();
    bool isEdit;
    int id;  // The ID of the entry being edited (set to -1 for a new entry)

private slots:
    void on_newButton_clicked();
    void on_readButton_clicked();
    void on_editDoneButton_clicked();

private:
    Ui::QtDiary *ui;
    DatabaseHandler *dbHandler = new DatabaseHandler;
};
#endif // QTDIARY_H
