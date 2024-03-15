#pragma once
//#include <QMutex>
//#include <QString>
//#include <QSharedPointer>
#include <string>
#include <mutex>

/*!
 * \brief Класс ресурса
 */
class SimpleClass// : public QObject
{
//    Q_OBJECT

    public:
        SimpleClass(std::string text, bool needCheckLock = true);

        void f();

//    signals:
//        void echo(QString msg);

    private:
        std::string m_text;
        std::mutex m_mutex;
        bool m_needCheckLock = true;
};
