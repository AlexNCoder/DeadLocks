#pragma once
#include <string>
#include <mutex>
#include <memory>

/*!
 * \brief Класс ресурса
 */
class SimpleClass
{
    public:
        SimpleClass(std::string objName, bool needCheckLock = true);

        void f(std::string threadName);

    private:
        std::mutex m_mutex;
        std::string m_objName;
        bool m_needCheckLock = true;
        std::unique_ptr<std::lock_guard<std::mutex>> m_locker;
};
