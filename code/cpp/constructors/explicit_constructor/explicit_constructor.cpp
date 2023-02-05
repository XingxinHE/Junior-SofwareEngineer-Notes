class Box
{
public:
    explicit Box(int num)
        : m_width(num), m_length(num), m_height(num){}
private:
    int m_width;
    int m_length;
    int m_height;
};

int main(){
    Box box1(1);        //✅
    Box box2(2.13);     //✅
    Box box3 = 3;       //❌
    Box box4 = 4.3;     //❌

    return 0;
}