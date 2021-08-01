#ifndef ENTRYPREVIEW_H
#define ENTRYPREVIEW_H

#include <QLabel>

class EntryPreview : public QLabel
{
    Q_OBJECT
    public:
        explicit EntryPreview(QWidget *parent = nullptr);
};

#endif // ENTRYPREVIEW_H
