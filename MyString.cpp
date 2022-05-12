#include "MyString.h"
#include <cstring>
#include <exception>

void MyString::CopyFromOther(const char *other)
{
    Free();
    mSize = strlen(other);
    mCapacity = mSize * 2;
    mData = new char[mCapacity];
    strcpy(mData, other);
}

bool MyString::ShouldBeResized(unsigned int other) const
{
    if (other < GetCapacity() / 4 || other > (GetCapacity() * 3) / 4)
    {
        return true;
    }
    return false;
}

void MyString::Resize()
{
    char *other = new char[mSize + 1];
    strcpy(other, this->mData);
    Free();
    SetData(other);
    delete[] other;
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

void MyString::SetData(const char *data)
{
    mSize = strlen(data);
    if (data == nullptr)
    {
        CreateEmpty();
        return;
    }
    else if (ShouldBeResized(mSize))
    {
        CopyFromOther(data);
    }
    else
    {
        strcpy(mData, data);
    }
}
MyString::MyString()
{
    CreateEmpty();
}
MyString::MyString(const char *data)
{
    if (data == nullptr)
    {
        CreateEmpty();
    }
    else
    {
        SetData(data);
    }
}
MyString::MyString(const MyString &other)
{
    if (this == &other)
    {
        throw 2;
    }
    SetData(other.mData);
}
MyString &MyString::operator=(const MyString &other)
{
    if (this == &other)
    {
        return *this;
    }
    Free();
    this->SetData(other.mData);
    return *this;
}
MyString::~MyString()
{
    Free();
}

