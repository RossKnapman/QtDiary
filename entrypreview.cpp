#include "entrypreview.h"

EntryPreview::EntryPreview(QWidget* parent, Qt::WindowFlags f) : QLabel(parent)
{
    connect(this, SIGNAL (clicked()), this, SLOT (showEntry()));
}

void EntryPreview::showEntry()
{
    QString entryText = dbHandler->getEntry(this->id);
    ui->stackedWidget->setCurrentIndex(2);
    ui->textBrowser->setText(entryText);
}

void EntryPreview::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}
