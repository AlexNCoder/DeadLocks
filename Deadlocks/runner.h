#pragma once
#include "simpleclass.h"

/*!
 * \brief Класс, отвечающий за работу с общими ресурсами из потоков
 */
class Runner
{

    public:
        Runner(
                SimpleClass &objA,
                SimpleClass &objB,
                std::string threadName,
                bool abLckOrder = true);

        void run();

        void thAB();
        void thBA();

    private:
        SimpleClass &m_objA;
        SimpleClass &m_objB;
        bool m_abLckOrder = false;
        std::string m_threadName;
};
