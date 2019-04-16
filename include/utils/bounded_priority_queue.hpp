/**
 * @file bounded_priority_queue.h
 * @brief Provides a fixed-size priority queue implementation.
 */

#pragma once

#if !defined(Bounded_Priority_Queue_h__)
#define Bounded_Priority_Queue_h__

#include "types.h"

template <typename Type, typename Comp, size_t Size>
class Bounded_Priority_Queue {
public:
    template <typename ...Parameters>
    bool emplace(Parameters&&... params) {
        // If we haven't reached max capacity yet, just emplace and sort,
        // otherwise check if we are try to emplace an item with greater
        // priority than our min, and if so inject and sort.
        if (m_size < Size) {
            // Emplace our new item.
            new(&m_data[m_size]) Type(std::forward<Parameters>(params)...);
            // Increment size.
            ++m_size;
            // Sort the queue.
            std::sort(std::launder(reinterpret_cast<Type*>(&m_data[0])), std::launder(reinterpret_cast<Type*>(&m_data[m_size])), m_comp);
            // We added something.
            return true;
        } else {
            // Construct item and check if it is higher priority than at least
            // the current lowest priority item.
            Type item(std::forward<Parameters>(params)...);
            // TODO(Matthew): Check if this is the right way round.
            if (m_comp(*std::launder(reinterpret_cast<const Type*>(&m_data[m_size - 1])), item)) {
                // Overwrite our lowest priority item.
                new(&m_data[m_size - 1]) Type(std::move(item));
                // Sort the queue.
                std::sort(std::launder(reinterpret_cast<Type*>(&m_data[0])), std::launder(reinterpret_cast<Type*>(&m_data[m_size])), m_comp);
                // We changed something.
                return true;
            }
        }
        // We didn't add anything.
        return false;
    }

    bool push(Type item) {
        // If we haven't reached max capacity yet, just emplace and sort,
        // otherwise check if we are try to emplace an item with greater
        // priority than our min, and if so inject and sort.
        if (m_size < Size) {
            // Push our new item.
            new(&m_data[m_size]) Type(std::move(item));
            // Increment size.
            ++m_size;
            // Sort the queue.
            std::sort(std::launder(reinterpret_cast<Type*>(&m_data[0])), std::launder(reinterpret_cast<Type*>(&m_data[m_size])), m_comp);
            // We added something.
            return true;
        } else {
            // Check if it is higher priority than at least
            // the current lowest priority item.
            // TODO(Matthew): Check if this is the right way round.
            if (m_comp(*std::launder(reinterpret_cast<const Type*>(&m_data[m_size - 1])), item)) {
                // Overwrite our lowest priority item.
                new(&m_data[m_size - 1]) Type(std::move(item));
                // Sort the queue.
                std::sort(std::launder(reinterpret_cast<Type*>(&m_data[0])), std::launder(reinterpret_cast<Type*>(&m_data[m_size])), m_comp);
                // We changed something.
                return true;
            }
        }
        // We didn't add anything.
        return false;
    }

    size_t size() { return m_size; }

    const Type& operator[](size_t index) const {
#if DEBUG
        assert(index < m_size);
#endif

        return *std::launder(reinterpret_cast<const Type*>(&m_data[index]));
    }
    Type& operator[](size_t index) {
#if DEBUG
        assert(index < m_size);
#endif

        return *std::launder(reinterpret_cast<Type*>(&m_data[index]));
    }
protected:
    typename std::aligned_storage<sizeof(Type), alignof(Type)>::type m_data[Size];
    size_t m_size = 0;
    Comp   m_comp;
};

#endif // !defined(Bounded_Priority_Queue_h__)
