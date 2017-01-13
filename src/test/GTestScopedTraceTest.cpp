#include <gtest/gtest.h>
#include <gmock/gmock.h>

void Sub1(int n) {
  EXPECT_EQ(1, (n));
  // EXPECT_EQ(2, (n + 1));
}

TEST(FooTest, Bar) {
  // {
    // SCOPED_TRACE("A");  // This trace point will be included in
                        // every failure in this scope.
    // Sub1(9);
  // }
  // Now it won't.
  // Sub1(1);
}
