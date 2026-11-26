/**
 *------------------------------------------------------------------------------
 * @file        Singleton
 * @brief       Provides lazy per-type singleton construction for test helpers.
 * @details     Uses std::call_once and a unique pointer to initialize one instance and forward
 *              constructor arguments.
 *
 * @author      76426
 * @date        2025/11/12
 * @version     V1.0.0
 *
 * @copyright   Copyright (c) 2026 [XSilverWolf]
 *              This project is licensed under the MIT License.
 *              See the LICENSE file in the project root for license information.
 *              SPDX-License-Identifier: MIT
 *
 * ------------------------------------------------------------------------------
 *  REVISION HISTORY (Modify)
 * ------------------------------------------------------------------------------
 *  [81761c6] - 2026/1/9 by 骇客速成计划
 *    - Added the call-once singleton template.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#include <memory>
#include <mutex>
#ifndef XTEST_SINGLETON_H
#define XTEST_SINGLETON_H
template<typename T, typename... Args>
class Singleton {
public:
    // 删除拷贝构造函数、移动构造函数、拷贝赋值运算符和移动赋值运算符，以防止外部复制、赋值或移动对象
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator=(Singleton &&) = delete;

    // 单例模板类的获取实例函数，使用完美转发和std::call_once来创建并返回单例对象
    static T *GetInstance(Args &&... args) {
        std::call_once(flag_, [&]() { instance_ = std::make_unique<T>(std::forward<Args>(args)...); });
        return instance_.get();
    }

protected:
    // 单例模板类的构造函数和析构函数，私有化以防止外部创建或销毁对象
    Singleton() = default;
    ~Singleton() = default;

    // 单例模板类的成员变量，包括一个智能指针指向单例对象，和一个once_flag变量保证线程安全
    static std::unique_ptr<T> instance_;
    static std::once_flag flag_;
};

// 初始化单例模板类的静态成员变量
template<typename T, typename... Args>
std::unique_ptr<T> Singleton<T, Args...>::instance_ = nullptr;

template<typename T, typename... Args>
std::once_flag Singleton<T, Args...>::flag_;
#endif //XTEST_SINGLETON_H
