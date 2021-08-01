#ifndef ENTRYPREVIEW_H
#define ENTRYPREVIEW_H

#include <QLabel>
#include "databasehandler.h"
#include "qtdiary.h"
#include "ui_qtdiary.h"

class EntryPreview : public QLabel
{
    Q_OBJECT
    public:
        explicit EntryPreview(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
        DatabaseHandler *dbHandler;
        Ui::QtDiary *ui;
        int id;

    signals:
        void clicked();

    protected:
        void mousePressEvent(QMouseEvent *event);

    private slots:
        void showEntry();

};

#endif // ENTRYPREVIEW_H
