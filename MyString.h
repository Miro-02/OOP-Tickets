#ifndef MY_STRING_H
#define MY_STRING_H

class MyString
{
private:
    char *mData;
    unsigned int mSize;
    unsigned int mCapacity;
    void Free();
    void CreateEmpty();
    void Resize();
    void CopyFromOther(const char*);
    bool ShouldBeResized(unsigned int) const;
public:
    unsigned int GetSize() const;
    unsigned int GetCapacity() const;
    void SetData(const char *);
    MyString();
    MyString(const char *);
    MyString(const MyString &);
    MyString &operator=(const MyString &other);
    ~MyString();
};

#endif
