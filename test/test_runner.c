/***********************************************************************************
 *                                                                                 *
 * NAME: test_runner.c                                                             *
 *                                                                                 *
 * AUTHOR: Michael Brockus.                                                        *
 *                                                                                 *
 * CONTACT: <mailto:michael@squidfarts.com>                                        *
 *                                                                                 *
 * PURPOSE:                                                                        *
 *                                                                                 *
 * In this file the `main()` function will call `UNITY_BEGIN()`, then `RUN_TEST`   *
 * for each test, and finally `UNITY_END()`.  This is what will actually trigger   *
 * each of those test functions to run, so it is important that each function      *
 * gets its own `RUN_TEST` call.                                                   *
 *                                                                                 *
 * NOTICES:                                                                        *
 *                                                                                 *
 * License: Apache 2.0 :http://www.apache.org/licenses/LICENSE-2.0                 *
 *                                                                                 *
 ***********************************************************************************/
#include <unity.h>
#include "queue.h"

/*
 *  Prototype functions for setup and teardown.
 */
extern void setUp(void);
extern void tearDown(void);

/*
 *  Prototype functions from the external test file.
 */
extern void test_enqueue(void);

/*
 *  This function runs test from the external test
 *  file.
 */
int main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_enqueue);
    
    return UNITY_END();
}//end of function main
