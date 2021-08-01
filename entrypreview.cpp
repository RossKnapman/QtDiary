#include "entrypreview.h"

EntryPreview::EntryPreview(QWidget* parent, Qt::WindowFlags f) : QLabel(parent)
{
    connect(this, SIGNAL (clicked()), this, SLOT (showEntry()));
}

void EntryPreview::showEntry()
{
    QString entryText = dbHandler->getEntry(this->id);
    ui->stackedWidget->setCurrentIndex(0);
    ui->editEntry->setText(entryText);
    ui->editEntry->setReadOnly(true);
    ui->editDoneButton->setText("Edit");
}

void EntryPreview::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}
