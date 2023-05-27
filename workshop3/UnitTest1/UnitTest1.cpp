/*Course: SFT221 | Workshop: 1 | Professor: Robin Huang
Section: NEE | Student Name: Julia Alekseev | Student ID: 051292134
*/

#include "pch.h"
#include "CppUnitTest.h"
#include "customer_r.h"
#include <cstring>
#include <cctype>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
	};

}

bool stringIsValid(const string& tempString);

namespace blackBoxString
{
    TEST_CLASS(StringTest)
    {
    public:
        TEST_METHOD(TestStringIsValid)
        {
            bool isValid = stringIsValid("Micropachycephalosaurus"); //checking to see if a long string is allowed 
            Assert::IsTrue(isValid);
        }
    };

    TEST_CLASS(StringTest2)
    {

        TEST_METHOD(TestStringIsValid)
        {
            bool isValid = stringIsValid("Dog");
            Assert::IsTrue(!isValid); //failling on purpose to see that the test is working
        }
    };

    TEST_CLASS(StringTest3) //testing to check a string with spaces 
    {
        TEST_METHOD(TestStringIsValid)
        {
            bool isValid = stringIsValid("Hello World!");
            Assert::IsTrue(isValid); 
        }
    };

    TEST_CLASS(StringTest4) //testing to check an upper case string
    {
        TEST_METHOD(TestStringIsValid)
        {
            bool isValid = stringIsValid("HELLO WORLD");
            Assert::IsTrue(isValid);
        }
    };

}
namespace whiteBoxString
{
    TEST_CLASS(StringTest)
    {
    public:
        TEST_METHOD(TestStringIsValid)
        {
            bool isValid = stringIsValid(" "); //checking to see if a space would be treated as nothing, test passes as space is a character, something to be taken into account if the code will be updated 
            Assert::IsTrue(!isValid);
        }
    };

    TEST_CLASS(StringTest2)
    {
        TEST_METHOD(TestStringIsValid)
        {
            bool isValid = stringIsValid("\n"); //checking to see if a new line would be rejected as planned
            Assert::IsTrue(!isValid);
        }
    };

}

bool stringIsValid(const string& tempString) {
    return !tempString.empty();
}
namespace blackBoxPostal
{
    TEST_CLASS(PostalTest)
    {
    public:
        TEST_METHOD(stringIsValidPostalCode)
        {
            bool isValid = postIsValid("m2m4l2"); //chekcing to see that a valid postal code is passed properly 
            Assert::IsTrue(isValid);
        }
    };

    TEST_CLASS(PostalTest2)
    {
   
        TEST_METHOD(stringIsValidPostalCode)
        {
            bool isValid = postIsValid("m2m 4l2"); //chekcing to see that a valid postal code with space is passed properly 
            Assert::IsTrue(isValid);
        }
    };


    TEST_CLASS(PostalTest3)
    {
 
        TEST_METHOD(stringIsValidPostalCode)
        {
            bool isValid = postIsValid("M2M4L2"); //chekcing to see that a valid upper case postal code is passed properly 
            Assert::IsTrue(isValid);
        }
    };
}


namespace whiteBoxPostal
{
    TEST_CLASS(PostalTest4)
    {
    public:
        TEST_METHOD(stringIsValidPostalCode)
        {
            bool isValid = postIsValid("123n");//chekcing to see that an invalid postal code will fail as expected 
            Assert::IsTrue(!isValid);
        }
    };

    TEST_CLASS(PostalTest5)
    {
        TEST_METHOD(stringIsValidPostalCode)
        {
            bool isValid = postIsValid("m2m 41l");//chekcing to see that an invalid postal code will fail as expected, different variation

            Assert::IsTrue(!isValid);
        }
    };

    TEST_CLASS(PostalTest6)
    {
        TEST_METHOD(stringIsValidPostalCode)
        {
            bool isValid = postIsValid("m2m41l");//chekcing to see that an invalid postal code will fail as expected, different variation 
            Assert::IsTrue(!isValid);
        }
    };
}


bool stringIsValidPostalCode(int valid)
{
    return valid;
}








