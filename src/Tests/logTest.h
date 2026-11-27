/**
 *------------------------------------------------------------------------------
 * @file        logTest
 * @brief       Defines the GoogleTest fixture for the named-logger example.
 * @details     Logs suite and case lifecycle events and invokes logger initialization in the
 *              fixture's test.
 *
 * @author      76426
 * @date        2025/11/9
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
 *    - Added the logger initialization fixture and its lifecycle diagnostics.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#ifndef XTEST_LOGTEST_H
#define XTEST_LOGTEST_H
#include "XTestSupport/GoogleTest.h"
#include "log/log.h"
#include "XPlat/File/File.h"

class LogTest : public xtest::Test {
protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    LogTest() {
        // You can do set-up work for each test here.
    }

    ~LogTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }
    static void SetUpTestSuite() {
        spdlog::info("run before first case");
    }

    static void TearDownTestSuite() {
        spdlog::info("run after last case");
    }
    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    void SetUp() override {
        spdlog::info("SetUp()");
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override {
        spdlog::info("TearDown()");
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

public:
    static std::shared_ptr<class logger> m_log;
};

std::shared_ptr<class logger> LogTest::m_log = std::make_shared<class logger>();

TEST_F(LogTest,init)
{
    m_log->initialize("LOGTEST");
    EXPECT_EQ(0, 0);
}

#endif //XTEST_LOGTEST_H
