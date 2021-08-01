#include "qtdiary.h"
#include "ui_qtdiary.h"
#include "databasehandler.h"
#include "entrypreview.h"

QtDiary::QtDiary(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtDiary)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    id = -1;
}

QtDiary::~QtDiary()
{
    delete ui;
}

void QtDiary::on_newButton_clicked()
{
    ui->editEntry->clear();
    ui->stackedWidget->setCurrentIndex(0);
    ui->editEntry->setReadOnly(false);
    id = -1;
    isEdit = true;
    ui->editDoneButton->setText("Done");
}

void QtDiary::on_readButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QSqlQuery query = this->dbHandler->GetAllEntries();

    query.next();

    QWidget *window = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(window);

    while (query.next())
    {
        EntryPreview *entryPreview = new EntryPreview(ui->scrollArea, this);
        entryPreview->setFixedSize(0.96*ui->scrollArea->width(), 100);
        entryPreview->setStyleSheet("QLabel { background-color: white; color: blue; }");
        entryPreview->setText(query.value(1).toString());
        entryPreview->ui = this->ui;
        entryPreview->dbHandler = this->dbHandler;
        entryPreview->id = query.value(0).toInt();
        layout->addWidget(entryPreview);
    }

    ui->scrollArea->setFixedSize(ui->EntriesPage->width(), ui->EntriesPage->height());
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setWidget(window);
    ui->scrollArea->show();
}

void QtDiary::on_editDoneButton_clicked()
{
    if (isEdit)
    {
        isEdit = false;
        ui->editDoneButton->setText("Edit");
        ui->editEntry->setReadOnly(true);
        QString text = ui->editEntry->toPlainText();
        ui->editEntry->setReadOnly(true);

        if (id == -1)  // Creating a new entry (we set id = -1 for new entries)
        {
            this->dbHandler->DatabaseInsert(text);
        }
        else
        {
            this->dbHandler->databaseUpdate(id, text);
        }
    }
    else
    {
        isEdit = true;
        ui->editDoneButton->setText("Done");
        ui->editEntry->setReadOnly(false);
    }
}
