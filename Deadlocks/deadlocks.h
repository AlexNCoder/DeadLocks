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
     *
     * \details Флаг needCheckLocking определяет режим воспроизведения дедлока
     */
    void tryMakeDeadLock(bool needCheckLocking = true);
};
