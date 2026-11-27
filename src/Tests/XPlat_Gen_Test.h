/**
 *------------------------------------------------------------------------------
 * @file        XPlat_Gen_Test
 * @brief       Defines the legacy GoogleTest fixture for signature compatibility.
 * @details     The case records examples of the earlier XPlat trait API. Its assertions are
 *              commented out.
 *
 * @author      XSilver
 * @date        2026/1/9
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
 *    - Added the fixture and its candidate signature-compatibility checks.
 *  [V1.0.0] - 2026/11/26 by XSilver
 *    - Recorded the MIT license adopted by the project.
 * ------------------------------------------------------------------------------
 */

#ifndef XPLAT_GEN_TEST_H
#define XPLAT_GEN_TEST_H

#include "XTestSupport/GoogleTest.h"
#include "XPlat/Gen/Core.h"

class XPlatGenTest : public xtest::Test 
{
public:
    XPlatGenTest() {
        // You can do set-up work for each test here.
    }

    ~XPlatGenTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }
};

TEST_F(XPlatGenTest, TestIsCompatibleSignature) 
{
    // bool t1 = xplat::gen::IsCompatibleSignature<int(int), int>::value;
    // bool t2 = xplat::gen::IsCompatibleSignature<int(float), int>::value;
    // EXPECT_TRUE(t1);
    // EXPECT_FALSE(t2);
}

#endif // XPLAT_GEN_TEST_H