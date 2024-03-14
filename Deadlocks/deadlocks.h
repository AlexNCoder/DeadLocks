#pragma once

#include <QMainWindow>
#include "runner.h"

namespace Ui
{
    class Deadlocks;
}

/*!
 * \brief Окно приложения
 */
class Deadlocks : public QMainWindow
{
    Q_OBJECT

public:
    explicit Deadlocks(QWidget *parent = nullptr);
    ~Deadlocks();

    /*!
     * \brief Запуск конкурирующих потоков
     * \param needCheckLocking Флаг необходимости проверки блокировок ресурсов
     *
     * \details Флаг needCheckLocking определяет режим воспроизведения дедлока
     */
    void tryMakeDeadLock(bool needCheckLocking = true);

private slots:
    void on_pushButton_clicked();
    void slotEcho(QString msg);

    void on_clrOutputBtn_clicked();

private:
    Ui::Deadlocks *m_ui;
};

//#endif // DEADLOCKS_H
