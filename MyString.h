#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
#include <fstream>

class MyString
{
private:
    char *mData;
    unsigned int mSize;
    //unsigned int mCapacity;
    void Free();
    void CreateEmpty();
    void Resize();
    void CopyFromOther(const char *);
    bool ShouldBeResized(unsigned int) const;

public:
    unsigned int GetSize() const;
    //unsigned int GetCapacity() const;
    const char *GetData() const;
    void SetData(const char *);
    MyString();
    MyString(unsigned int);
    MyString(const char *);
    MyString(const MyString &);
    MyString &operator=(const MyString &);
    MyString &operator=(const char *);
    char operator[](unsigned int);
    ~MyString();
    friend std::ostream &operator<<(std::ostream &, const MyString &);
    //friend std::istream &operator>>(std::istream &, MyString &);
    MyString& operator+=(const char *);

};

bool operator==(const MyString &, const MyString &);

#endif
