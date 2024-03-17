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
        SimpleClass(
                std::string objName,
                bool verbose = false);

        void f();
        void lock(std::string threadName);
        bool tryLock(std::string threadName);
        void unLock(std::string threadName);

    private:
        std::mutex m_mutex;
        std::string m_objName;
        bool m_verbose = false;
//        std::unique_ptr<std::lock_guard<std::mutex>> m_locker;
};
