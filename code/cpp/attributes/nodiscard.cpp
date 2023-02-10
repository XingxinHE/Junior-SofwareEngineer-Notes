class Point3d
{
private:
    double m_x{0};
    double m_y{0};
public:
    double getX() const { return m_x; }
    [[nodiscard]] double getY() const { return m_y; }
};

int main()
{
    Point3d pt;
    pt.getX();  //✅OK
    pt.getY();  //❌Warning!

    return 0;
}
