#pragma once

#include "runner.h"

namespace Ui
{
    class Deadlocks;
}

/*!
 * \brief Окно приложения
 */
class Deadlocks
{

public:
    explicit Deadlocks();
    ~Deadlocks();

    /*!
     * \brief Запуск конкурирующих потоков
     * \param needCheckLocking Флаг необходимости проверки блокировок ресурсов
     * \param verbose Флаг, включающий вывод программы на консоль
     *
     * \details Флаг needCheckLocking определяет режим воспроизведения дедлока
     */
    void tryMakeDeadLock(bool needCheckLocking = true, bool verbose = false);
};
