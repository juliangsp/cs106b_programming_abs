/* File: PlayingFair.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 */
#include "PlayingFair.h"
#include "Testing/PlayingFairTests.h"
#include "error.h"
using namespace std;

string aSequenceOfOrder(int n) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */
    //(void) n;
    //return "";
    cout << "order: " << n << endl;
    if(n < 0)
        error("Negative numbers are not allowed!");
    if(n == 0){
        return "A";
    }

    string ret;
    ret = aSequenceOfOrder(n-1) + bSequenceOfOrder(n-1);
    cout << "Called aSequenceOfOrder " << ret << endl;
    return ret;
}

string bSequenceOfOrder(int n) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */
    //(void) n;
    //return "";
    if(n < 0)
        error("Negative numbers are not allowed!");
    if(n == 0){
        return "B";
    }
    string ret;
    ret = bSequenceOfOrder(n-1) + aSequenceOfOrder(n-1);
    return ret;
}






/* * * * * * Tests Below This Point * * * * * */

ADD_TEST("Sequences of order 3 are correct.") {
    /* Some very basic checks. */
    EXPECT(aSequenceOfOrder(3) == "ABBABAAB");
    EXPECT(bSequenceOfOrder(3) == "BAABABBA");
}

ADD_TEST("Triggers error on negative inputs.") {
    /* The EXPECT_ERROR macro expects the given expression to call error(). Remember that
     * you need to guard against invalid inputs.
     */
    EXPECT_ERROR(aSequenceOfOrder(-137));
    EXPECT_ERROR(bSequenceOfOrder(-137));
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */

