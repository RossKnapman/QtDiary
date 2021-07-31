#include "qtdiary.h"
#include "ui_qtdiary.h"
#include "databasehandler.h"

QtDiary::QtDiary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtDiary)
{
    ui->setupUi(this);
}

QtDiary::~QtDiary()
{
    delete ui;
}

void QtDiary::on_saveButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    this->dbHandler->DatabaseInsert(text);
    ui->textEdit->clear();
}
