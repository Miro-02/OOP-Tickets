#include "MyString.h"
#include <cstring>
#include <iostream>
#include <fstream>

void MyString::CopyFromOther(const char *other)
{
    mSize = strlen(other);
    mCapacity = mSize * 2;
    mData = new char[mCapacity];
    strcpy(mData, other);
}

bool MyString::ShouldBeResized(unsigned int other) const
{
    if (other < mCapacity / 4 || other > mCapacity)
    {
        return true;
    }
    return false;
}

void MyString::CreateEmpty()
{
    mSize = 0;
    mCapacity = 0;
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
unsigned int MyString::GetCapacity() const
{
    return mCapacity;
}
const char *MyString::GetData() const
{
    return mData;
}

void MyString::SetData(const char *data)
{
    if (mData == data)
    {
        return;
    }
    mSize = strlen(data);
    if (data == nullptr)
    {
        CreateEmpty();
        return;
    }
    else if (ShouldBeResized(strlen(data)))
    {
        Free();
        CopyFromOther(data);
        return;
    }
    strcpy(mData, data);
    return;
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
    SetData(other.mData);
}
MyString &MyString::operator=(const MyString &other)
{
    if (this == &other)
    {
        return *this;
    }
    else if (this->mData == nullptr)
    {
        SetData(other.mData);
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

std::istream &operator>>(std::istream &stream, MyString &string)
{
    char buff[1024];
    stream >> buff;
    string.mSize = strlen(buff);
    if (string.ShouldBeResized(string.mSize) || string.mCapacity == 0)
    {
        string.CopyFromOther(buff);
    }
    else
    {
        strcpy(string.mData, buff);
    }
    return stream;
}

bool operator==(const MyString &lhs, const MyString &rhs)
{
    unsigned int lSize = lhs.GetSize();
    if(lSize!=rhs.GetSize())
    {
        return false;
    }
    return strncmp(lhs.GetData(), rhs.GetData(), lSize);
}
bool operator==(const MyString &lhs, const char *rhs)
{
    unsigned int rSize = strlen(rhs);
    if(lhs.GetSize()!=rSize)
    {
        return false;
    }
    return strncmp(lhs.GetData(), rhs, rSize);
}

// int main(int argc, char const *argv[])
// {
//     char buff[20] = "asfdgsdf";
//     char buuf2[100] = "fksdjhaouusfhjygkubhjbjybhilubluyvuyb";
//     MyString string = nullptr;
//     char buf[20];
//     // string = buff;
//     // string = buuf2;
//     std::cout << string.GetCapacity() << " " << string.GetSize() << " " << string<<" "<<buf;
//     return 0;
// }
