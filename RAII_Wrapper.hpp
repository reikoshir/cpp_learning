#include <utility>


template <typename T>
class RaiiPtr
{
public:
    // constructor
    explicit RaiiPtr(T* ptr = nullptr)
        : mPtr(ptr)
    {}

    // destructor
    ~RaiiPtr()
    {
        delete mPtr;
    }
    // delete defaults
    RaiiPtr(const RaiiPtr&) = delete;
    RaiiPtr& operator=(const RaiiPtr&) = delete;

    // move constructor
    RaiiPtr(RaiiPtr&& other)
        : mPtr(other.mPtr)
    {
        other.mPtr = nullptr;
    }

    // move assignment
    RaiiPtr& operator=(RaiiPtr&& other)
    {
        if (this != &other)
        {
            delete mPtr;
            mPtr = other.mPtr;
            other.mPtr = nullptr;
        }
        return *this;
    }

    // getter
    T* get() const
    {
        return mPtr;
    }

private:
    T* mPtr;
};