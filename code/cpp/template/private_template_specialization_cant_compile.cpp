class Widget
{
public:
    //…
    template<typename T>
    void processPointer(T* ptr) { /*…*/ }
private:
    
    template<> 
    void processPointer<void>(void*); // ❌ERROR
};

int main()
{
    return 0;
}