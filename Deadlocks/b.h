#ifndef B_H
#define B_H
#include <QObject>
#include <QMutex>

class B : public QObject
{
    Q_OBJECT

    public:
        B();

        void f();

    private:
        QMutex m_mutex;
};

#endif // B_H
