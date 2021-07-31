#include "qtdiary.h"
#include "ui_qtdiary.h"

QtDiary::QtDiary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtDiary)
{
    ui->setupUi(this);

    connect(ui->actionClear, &QAction::triggered, this, &QtDiary::clear);
}

QtDiary::~QtDiary()
{
    delete ui;
}

void QtDiary::clear()
{
    ui->textEdit->clear();
}
