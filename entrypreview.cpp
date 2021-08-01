#include "entrypreview.h"

EntryPreview::EntryPreview(QWidget* parent, QtDiary *qtdiary) : QLabel(parent)
{
    this->qtdiary = qtdiary;
    connect(this, SIGNAL (clicked()), this, SLOT (showEntry()));
}

void EntryPreview::showEntry()
{
    QString entryText = dbHandler->getEntry(this->id);
    ui->stackedWidget->setCurrentIndex(0);
    ui->editEntry->setText(entryText);
    ui->editEntry->setReadOnly(true);
    ui->editDoneButton->setText("Edit");
    qtdiary->id = id;
}

void EntryPreview::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}
