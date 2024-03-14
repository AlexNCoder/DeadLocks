#pragma once
#include <QMutex>
#include <QString>
#include <QSharedPointer>

/*!
 * \brief Класс ресурса
 */
class SimpleClass : public QObject
{
    Q_OBJECT

    public:
        SimpleClass(QString text, bool needCheckLock = true);

        void f(QString threadName);

    signals:
        void echo(QString msg);

    private:
        QString m_text;
        QMutex m_mutex;
        QSharedPointer<QMutexLocker> m_locker;
        bool m_needCheckLock = true;
};
