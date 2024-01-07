#ifndef __SINGLETON_H_
#define __SINGLETON_H_

#include <atomic>
#include <mutex>
#include <thread>
#include <typeinfo>

#include <logger.h>

template <typename T>
class BaseUniqueSingleton
{
public:
    static T* get_instance()
    {
        T* tmp = instance__.load(std::memory_order_relaxed);
        std::atomic_thread_fence(std::memory_order_acquire);

        if (tmp == nullptr) {
            std::lock_guard<std::mutex> lock(mutex__);
            tmp = instance__.load(std::memory_order_relaxed);

            if (tmp == nullptr) {
                Logger::log("BaseUniqueSingleton", "Creating new unique instance of type %s", typeid(T).name());

                tmp = new_internal();

                std::atomic_thread_fence(std::memory_order_release);
                instance__.store(tmp, std::memory_order_relaxed);
            }
        }

        return tmp;
    }

    static void destroy_instance()
    {
        T* tmp = instance__.load(std::memory_order_relaxed);
        std::atomic_thread_fence(std::memory_order_acquire);

        if (tmp == nullptr) {
            Logger::log("BaseUniqueSingleton", "Unique instance of type %s is already destroyed, skipping destruction", typeid(T).name());
            return;
        }

        std::lock_guard<std::mutex> lock(mutex__);
        tmp = instance__.load(std::memory_order_relaxed);

        if (tmp == nullptr) {
            Logger::log("BaseUniqueSingleton", "Unique instance of type %s is already destroyed, skipping destruction", typeid(T).name());
            return;
        }

        Logger::log("BaseUniqueSingleton", "Destroying unique instance of type %s", typeid(T).name());

        delete tmp;
        tmp = nullptr;

        std::atomic_thread_fence(std::memory_order_release);
        instance__.store(tmp, std::memory_order_relaxed);
    }

    BaseUniqueSingleton(const BaseUniqueSingleton&) = delete;
    BaseUniqueSingleton& operator=(const BaseUniqueSingleton&) = delete;
    BaseUniqueSingleton(BaseUniqueSingleton&&) = delete;
    BaseUniqueSingleton& operator=(BaseUniqueSingleton&&) = delete;

protected:
    BaseUniqueSingleton() = default;
    ~BaseUniqueSingleton() = default;

private:
    static std::atomic<T*>  instance__;
    static std::mutex       mutex__;
};

template <typename T>
std::atomic<T*> BaseUniqueSingleton<T>::instance__;

template <typename T>
std::mutex      BaseUniqueSingleton<T>::mutex__;

#endif
