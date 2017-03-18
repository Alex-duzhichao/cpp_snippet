#include "gmock/gmock.h"
#include "gtest/gtest.h"

class Turtle
{
public:
    virtual ~Turtle() {}
    virtual void PenUp() = 0;
    virtual void PenDown() = 0;
    virtual void Forward(int distance) = 0;
    virtual void Turn(int degrees) = 0;
    virtual void GoTo(int x, int y) = 0;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
};

class MockTurtle : public Turtle
{
public:
    MOCK_METHOD0(PenUp, void());
    MOCK_METHOD0(PenDown, void());
    MOCK_METHOD1(Forward, void(int distance));
    MOCK_METHOD1(Turn, void(int degrees));
    MOCK_METHOD2(GoTo, void(int x, int y));
    MOCK_CONST_METHOD0(GetX, int());
    MOCK_CONST_METHOD0(GetY, int());
};

class Painter
{
public:
    Painter(Turtle *pTurtle)
        : m_pTurtle(pTurtle),
          m_nTimes(0)
    {}
    bool DrawCircle(const int, const int, const int)
    {
        m_pTurtle->PenDown();
        return true;
        // return false;
    }
    // int GetX()
    // {
         // return ++m_nTimes;
         // return m_nTimes;
    // }
private:
    Turtle *m_pTurtle;
    int m_nTimes;
}; // class Painter

// using ::testing::AtLeast;                     // #1
using namespace ::testing;                     // #1

TEST(PainterTest, CanDrawSomething)
{
    MockTurtle turtle;                          // #2
    EXPECT_CALL(turtle, PenDown())              // #3
    .Times(AtLeast(1));

    Painter painter(&turtle);                   // #4
    EXPECT_TRUE(painter.DrawCircle(0, 0, 10));

    EXPECT_CALL(turtle, GetX())              // #3
    .Times(2)
    .WillOnce(Return(1))
    .WillOnce(Return(2));

    turtle.GetX();
    turtle.GetX();

    // EXPECT_CALL(turtle, Forward(_));
    EXPECT_CALL(turtle, Forward(Ge(100)));
    turtle.Forward(101);

}                                             // #5
