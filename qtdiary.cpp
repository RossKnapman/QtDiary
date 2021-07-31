#include "qtdiary.h"
#include "ui_qtdiary.h"
#include "databasehandler.h"

QtDiary::QtDiary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtDiary)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
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
    ui->stackedWidget->setCurrentIndex(0);
}

void QtDiary::on_newButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void QtDiary::on_readButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QSqlQuery query = this->dbHandler->GetAllEntries();

    query.next();

    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widget);

    this->setCentralWidget(widget);
    widget->setLayout(layout);

    while(query.next())
    {
//        qDebug() << "Query returned: " << query.value(1).toString();

        QLabel *testLabel = new QLabel(ui->ReadPage);
        testLabel->setFixedSize(ui->ReadPage->width(), 100);
        testLabel->setStyleSheet("QLabel { background-color : white; color : blue; }");
        testLabel->setText(query.value(1).toString());

        layout->addWidget(testLabel);
    }
}
