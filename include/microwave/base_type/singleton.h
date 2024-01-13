
/*
 * Copyright (c) 2024, noir51
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * File name: microwave/base_type/singleton.h
 */

#ifndef __BASE_TYPE_SINGLETON_H_
#define __BASE_TYPE_SINGLETON_H_

#include <atomic>
#include <mutex>
#include <thread>
#include <typeinfo>

#include <microwave/debug/logger.h>

template <typename T>
class BaseSingleton
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
                Logger::log("BaseSingleton", "Creating new unique instance of type %s", typeid(T).name());

                tmp = new T();

                std::atomic_thread_fence(std::memory_order_release);
                instance__.store(tmp, std::memory_order_relaxed);
            }
        }

        alive__.store(true, std::memory_order_relaxed);

        return tmp;
    }

    static void destroy_instance()
    {
        T* tmp = instance__.load(std::memory_order_relaxed);
        std::atomic_thread_fence(std::memory_order_acquire);

        if (tmp == nullptr) {
            Logger::log("BaseSingleton", "Unique instance of type %s is already destroyed, skipping destruction", typeid(T).name());
            return;
        }

        std::lock_guard<std::mutex> lock(mutex__);
        tmp = instance__.load(std::memory_order_relaxed);

        if (tmp == nullptr) {
            Logger::log("BaseSingleton", "Unique instance of type %s is already destroyed, skipping destruction", typeid(T).name());
            return;
        }

        Logger::log("BaseSingleton", "Destroying unique instance of type %s", typeid(T).name());

        delete tmp;
        tmp = nullptr;

        std::atomic_thread_fence(std::memory_order_release);
        instance__.store(tmp, std::memory_order_relaxed);

        alive__.store(false, std::memory_order_relaxed);
    }

    static bool is_alive() { return alive__.load(std::memory_order_relaxed); }

    BaseSingleton(const BaseSingleton&) = delete;
    BaseSingleton& operator=(const BaseSingleton&) = delete;
    BaseSingleton(BaseSingleton&&) = delete;
    BaseSingleton& operator=(BaseSingleton&&) = delete;

protected:
    BaseSingleton() = default;
    ~BaseSingleton() = default;

private:
    static std::atomic<T*>      instance__;
    static std::mutex           mutex__;
    static std::atomic<bool>    alive__;
};

template <typename T>
std::atomic<T*> BaseSingleton<T>::instance__ = nullptr;

template <typename T>
std::mutex BaseSingleton<T>::mutex__;

template <typename T>
std::atomic<bool> BaseSingleton<T>::alive__ = false;

#endif

/* EOF */

