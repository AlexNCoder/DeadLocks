#pragma once
#include "simpleclass.h"
//#include <QThread>
//#include <QString>

/*!
 * \brief Класс, отвечающий за работу с общими ресурсами из потоков
 */
class Runner// : public QThread
{
//    Q_OBJECT

    public:
        Runner(SimpleClass &objA,
                SimpleClass &objB,
                std::string threadName,
                bool abLckOrder = true);

        void run() override;

        void thAB();
        void thBA();
    signals:
        void echo(QString msg);

    private:
        SimpleClass &m_objA;
        SimpleClass &m_objB;
        bool m_abLckOrder = false;
        QString m_threadName;
        QMutex m_mutex;
};
