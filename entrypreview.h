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
        explicit EntryPreview(QWidget *parent = Q_NULLPTR, QtDiary *qtdiary = Q_NULLPTR);
        DatabaseHandler *dbHandler;
        Ui::QtDiary *ui;
        QtDiary *qtdiary;
        int id;

    signals:
        void clicked();

    protected:
        void mousePressEvent(QMouseEvent *event);

    private slots:
        void showEntry();

};

#endif // ENTRYPREVIEW_H
