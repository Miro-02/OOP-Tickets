#include "MyString.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

void MyString::CopyFromOther(const char *other)
{
    mSize = strlen(other);
    // mCapacity = mSize * 2;
    mData = new char[mSize + 1];
    strcpy(mData, other);
}

// bool MyString::ShouldBeResized(unsigned int other) const
// {
//     if (other < mCapacity / 4 || other > mCapacity)
//     {
//         return true;
//     }
//     return false;
// }
MyString::MyString(unsigned int size)
{
    mSize = size;
    // mCapacity = size;
    mData = new char[mSize];
}

MyString &MyString::operator+=(const char *other)
{

    mSize = mSize + strlen(other);
    char temp[mSize + 1];
    strcpy(temp, mData);
    strcat(temp, other);
    Free();
    mData = new char[mSize * 2];
    strcpy(mData, temp);
    return *this;
}
void MyString::CreateEmpty()
{
    mSize = 0;
    // mCapacity = 0;
    mData = new char[1];
    mData[0] = '\0';
}
void MyString::Free()
{
    delete[] mData;
}
unsigned int MyString::GetSize() const
{
    return mSize;
}
// unsigned int MyString::GetCapacity() const
// {
//     return mCapacity;
// }
const char *MyString::GetData() const
{
    return mData;
}

void MyString::SetData(const char *data)
{

    mSize = strlen(data);
    if (mSize>0&&data == nullptr)
    {
        Free();
        return;
    }
    mData = new char[strlen(data) + 1];
    strcpy(mData, data);
}
MyString::MyString()
{
    CreateEmpty();
}
MyString::MyString(const char *data)
{
    SetData(data);
}
MyString::MyString(const MyString &other)
{
    // if (this == &other)
    // {
    //     throw 2;
    // }
    mData = new char[other.mSize+1];
    strcpy(mData, other.mData);
}
MyString &MyString::operator=(const MyString &other)
{
    if (this == &other || other.mData == nullptr)
    {
        return *this;
    }
    Free();
    SetData(other.mData);
    return *this;
}
MyString &MyString::operator=(const char *other)
{
    if (mData == other)
    {
        return *this;
    }
    SetData(other);
    return *this;
}
MyString::~MyString()
{
    Free();
}

std::ostream &operator<<(std::ostream &stream, const MyString &string)
{
    char buff[string.mSize];
    strncpy(buff, string.mData, string.mSize);
    stream << buff;
    return stream;
}

// std::istream &operator>>(std::istream &stream, MyString &string)
// {
//     char buff[1024];
//     stream >> buff;
//     string.mSize = strlen(buff);
//     Free();
//     CopyFromOther()
//     strcpy(string.mData, buff);

//     return stream;
// }

bool operator==(const MyString &lhs, const MyString &rhs)
{
    unsigned int lSize = lhs.GetSize();
    if (lSize != rhs.GetSize())
    {
        return false;
    }
    return strncmp(lhs.GetData(), rhs.GetData(), lSize);
}
bool operator==(const MyString &lhs, const char *rhs)
{
    unsigned int rSize = strlen(rhs);
    if (lhs.GetSize() != rSize)
    {
        return false;
    }
    return strncmp(lhs.GetData(), rhs, rSize);
}

char MyString::operator[](unsigned int index)
{
    if (index > mSize)
    {
        cout << "Invalid index" << endl;
        throw 0;
    }
    return mData[index];
}

// int main(int argc, char const *argv[])
// {
//     char buff[20] = "asfdgsdf";
//     char buuf2[100] = "fksdjhaouusfhjygkubhjbjybhilubluyvuyb";
//     MyString string = "dfhpikjnu";
//     char buf[20];
//     // string = buff;
//     //  string = buuf2;
//     //std::cout << string[5];
//     return 0;
// }
