#ifndef QTDIARY_H
#define QTDIARY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QtDiary; }
QT_END_NAMESPACE

class QtDiary : public QMainWindow
{
    Q_OBJECT

public:
    QtDiary(QWidget *parent = nullptr);
    ~QtDiary();

private slots:
    void clear();

private:
    Ui::QtDiary *ui;
};
#endif // QTDIARY_H
