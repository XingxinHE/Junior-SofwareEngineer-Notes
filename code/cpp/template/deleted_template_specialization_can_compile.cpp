class Widget
{
public:
    //…
    template<typename T>
    void processPointer(T* ptr) { /*…*/ }
private:

};

// ✅ok
template<> 
void Widget::processPointer<void>(void*);

int main()
{
    return 0;
}