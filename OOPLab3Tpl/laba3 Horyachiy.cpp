/*#include <iostream>
#include <stdexcept>

class Rectangle {
private:
    double height;
    double width;
    std::string color;

public:
    // ����������� �� �������������
    Rectangle() : height(0.0), width(0.0), color("white") {}

    // ����������� � �����������
    Rectangle(double h, double w, const std::string& c) : height(h), width(w), color(c) {
        // �������� �� ���������� ���������
        if (h <= 0.0 || w <= 0.0) {
            throw std::invalid_argument("Invalid height or width");
        }
    }

    // �������-���� ��� ���������� �����-
    double calculateArea() const {
        return height * width;
    }

    // �������-���� ��� ���������� ���������
    double calculatePerimeter() const {
        return 2 * (height + width);
    }

    // �������-����� ��� ������������ ������� ���� � ��������� ����������
    void setHeight(double h) {
        if (h > 0.0) {
            height = h;
        }
        else {
            throw std::invalid_argument("Invalid height");
        }
    }

    void setWidth(double w) {
        if (w > 0.0) {
            width = w;
        }
        else {
            throw std::invalid_argument("Invalid width");
        }
    }

    void setColor(const std::string& c) {
        color = c;
    }

    // �������-����� ��� ��������� ������� ����
    double getHeight() const {
        return height;
    }

    double getWidth() const {
        return width;
    }

    std::string getColor() const {
        return color;
    }

    // ������� �����
    void print() const {
        std::cout << "Rectangle - Height: " << height << ", Width: " << width << ", Color: " << color << std::endl;
    }
};

int main() {
    try {
        // ���������� ����� Rectangle
        Rectangle rectangle1;  // ��������������� ����������� �� �������������
        rectangle1.print();

        Rectangle rectangle2(5.0, 3.0, "blue");  // ��������������� ����������� � �����������
        rectangle2.print();

        // ������ ��������� � ������� ���������
        rectangle2.setHeight(8.0);
        rectangle2.setWidth(4.0);
        rectangle2.setColor("red");
        rectangle2.print();

        std::cout << "Area: " << rectangle2.calculateArea() << std::endl;
        std::cout << "Perimeter: " << rectangle2.calculatePerimeter() << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
*/
#include <iostream>

class Vector {
private:
    double* data;
    int size;
    int& state;  // ����� �����

public:
    // ������������
    Vector() : data(new double[1]), size(1), state(size) {
        data[0] = 0.0;
    }

    Vector(int newSize) : data(new double[newSize]), size(newSize), state(size) {
        for (int i = 0; i < size; ++i) {
            data[i] = 0.0;
        }
    }

    Vector(int newSize, double initValue) : data(new double[newSize]), size(newSize), state(size) {
        for (int i = 0; i < size; ++i) {
            data[i] = initValue;
        }
    }

    Vector(const Vector& other) : data(new double[other.size]), size(other.size), state(size) {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // �������� ���������
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            state = size;
            data = new double[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // ����������
    ~Vector() {
        delete[] data;
    }

    // �������
    void setValue(int index, double value = 0.0) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
        else {
            state = -1;  // ��� �������
        }
    }

    double getValue(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            state = -1;  // ��� �������
            return 0.0;
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    Vector add(const Vector& other) const {
        if (size == other.size) {
            Vector result(size);
            for (int i = 0; i < size; ++i) {
                result.data[i] = data[i] + other.data[i];
            }
            return result;
        }
        else {
            state = -1;  // ��� �������
            return Vector();
        }
    }

    Vector subtract(const Vector& other) const {
        if (size == other.size) {
            Vector result(size);
            for (int i = 0; i < size; ++i) {
                result.data[i] = data[i] - other.data[i];
            }
            return result;
        }
        else {
            state = -1;  // ��� �������
            return Vector();
        }
    }

    Vector multiply(double scalar) const {
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    Vector divide(double scalar) const {
        if (scalar != 0.0) {
            Vector result(size);
            for (int i = 0; i < size; ++i) {
                result.data[i] = data[i] / scalar;
            }
            return result;
        }
        else {
            state = -1;  // ��� �������
            return Vector();
        }
    }

    bool isEqual(const Vector& other) const {
        if (size == other.size) {
            for (int i = 0; i < size; ++i) {
                if (data[i] != other.data[i]) {
                    return false;
                }
            }
            return true;
        }
        else {
            state = -1;  // ��� �������
            return false;
        }
    }

    bool isGreater(const Vector& other) const {
        if (size == other.size) {
            for (int i = 0; i < size; ++i) {
                if (data[i] <= other.data[i]) {
                    return false;
                }
            }
            return true;
        }
        else {
            state = -1;  // ��� �������
            return false;
        }
    }

    bool isLess(const Vector& other) const {
        if (size == other.size) {
            for (int i = 0; i < size; ++i) {
                if (data[i] >= other.data[i]) {
                    return false;
                }
            }
            return true;
        }
        else {
            state = -1;  // ��� �������
            return false;
        }
    }

    static int getObjectCount() {
        // ϳ�������� ������� ��'����
        // (���� ������������ �� ��������� �������� ����� �����)
        static int objectCount = 0;
        return objectCount;
    }
};

int main() {
    // ���������� ����� Vector
    std::cout << "Initial number of Vector objects: " << Vector::getObjectCount() << std::endl;

    Vector v1;  // ������ ������������ ��� ���������
    std::cout << "v1: ";
    v1.print();

    Vector v2(5);  // ������ ������������ � ����� ����������
    std::cout << "v2: ";
    v2.print();

    Vector v3(3, 2.5);  // ������ ������������ � ����� �����������
    std::cout << "v3: ";
    v3.print();

    Vector v4 = v2;  // ������ ������������ ��ﳿ
    std::cout << "v4: ";
    v4.print();

    Vector v5;
    v5 = v3;  // ������ ��������� ���������
    std::cout << "v5: ";
    v5.print();

    v1.setValue(0, 1.1);
    std::cout << "v1 after setValue: ";
    v1.print();

    std::cout << "Value at index 2 in v3: " << v3.getValue(2) << std::endl;

    Vector v6 = v2.add(v3);  // ���������� ������� ���������
    std::cout << "v6 (v2.add(v3)): ";
    v6.print();

    Vector v7 = v3.subtract(v2);  // ���������� ������� ��������
    std::cout << "v7 (v3.subtract(v2)): ";
    v7.print();

    double scalar = 2.0;
    Vector v8 = v3.multiply(scalar);  // ���������� ������� �������� �� ������
    std::cout << "v8 (v3.multiply(" << scalar << ")): ";
    v8.print();

    Vector v9 = v3.divide(scalar);  // ���������� ������� ������ �� ������
    std::cout << "v9 (v3.divide(" << scalar << ")): ";
    v9.print();

    if (v2.isEqual(v4)) {
        std::cout << "v2 is equal to v4." << std::endl;
    }
    else {
        std::cout << "v2 is not equal to v4." << std::endl;
    }

    if (v3.isGreater(v2)) {
        std::cout << "v3 is greater than v2." << std::endl;
    }
    else {
        std::cout << "v3 is not greater than v2." << std::endl;
    }

    if (v2.isLess(v3)) {
        std::cout << "v2 is less than v3." << std::endl;
    }
    else {
        std::cout << "v2 is not less than v3." << std::endl;
    }

    std::cout << "Number of Vector objects: " << Vector::getObjectCount() << std::endl;

    return 0;
}

