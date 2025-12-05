class Integer {
private:
    int value;

public:
    Integer(int val);

    int getValue() const;

    void setValue(int val);

    // Overloading the + operator for Integer addition
    Integer operator+(const Integer& other) const;
};
