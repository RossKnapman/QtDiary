#include "qtdiary.h"
#include "ui_qtdiary.h"
#include "databasehandler.h"
#include "entrypreview.h"

QtDiary::QtDiary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtDiary)
{
    ui->setupUi(this);
//    setCentralWidget(ui->stackedWidget);
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
}

void QtDiary::on_newButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void QtDiary::on_readButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QSqlQuery query = this->dbHandler->GetAllEntries();

    query.next();

    QWidget *window = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(window);

    while(query.next())
    {
        EntryPreview *entryPreview = new EntryPreview(ui->scrollArea);
        entryPreview->setFixedSize(ui->scrollArea->width(), 100);
        entryPreview->setStyleSheet("QLabel { background-color : white; color : blue; }");
        entryPreview->setText(query.value(1).toString());

        layout->addWidget(entryPreview);
    }

    ui->scrollArea->setFixedSize(ui->ReadPage->width(), ui->ReadPage->height());
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setWidget(window);
    ui->scrollArea->show();
}
