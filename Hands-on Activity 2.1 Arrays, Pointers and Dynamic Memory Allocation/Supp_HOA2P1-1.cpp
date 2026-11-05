#include <iostream>
#include <string>

class GroceryItem{
protected:
    std::string name;
    double price;
    int quantity;

public:
    GroceryItem();
    GroceryItem(std::string, double, int);
    GroceryItem(const GroceryItem&);
    GroceryItem& operator=(const GroceryItem&);
    virtual ~GroceryItem();

    virtual double calculateSum() const = 0;
    virtual void displayItem() const = 0;
};

// grocery definition
GroceryItem::GroceryItem(){
    name="";
    price=0;
    quantity=0;
}

GroceryItem::GroceryItem(std::string n,double p,int q){
    name=n;
    price=p;
    quantity=q;
}

GroceryItem::GroceryItem(const GroceryItem& other){
    name=other.name;
    price=other.price;
    quantity=other.quantity;
}

GroceryItem& GroceryItem::operator=(const GroceryItem& other){
    if(this!=&other){
        name=other.name;
        price=other.price;
        quantity=other.quantity;
    }
    return *this;
}

GroceryItem::~GroceryItem(){}

// fruit class

class Fruit : public GroceryItem{
public:
    // constructor
    Fruit();
    Fruit(std::string, double, int q);
    Fruit(const Fruit&); // copy constructor
    Fruit& operator=(const Fruit&); // copy assignment operator
    ~Fruit() override; // destructor

    // getters
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    // setters
    void setPrice(double);
    void setQuantity(int);

    double calculateSum() const override;
    double calculateDiscount(double percent) const;
    bool isAvailable() const;
    void updateItem(std::string, double, int);
    void displayItem () const override;
};

// function definition
// Fruit:: - tells compiler fruit belongs to fruit class
// != &other - prevents assigning an object to itself in the copy asgn op
// return *this - returns the current obj 

Fruit::Fruit() : GroceryItem() {} // constructor

//parametized constructor
Fruit::Fruit(std::string n, double p, int q) : GroceryItem(n,p,q) {}

//copy constructor
Fruit::Fruit(const Fruit& other) : GroceryItem(other) {}

// copy assignment operator
Fruit& Fruit::operator=(const Fruit& other){
    if (this != &other){
        GroceryItem::operator=(other);
    }
    return *this;
}

Fruit::~Fruit() {}

// getters
std::string Fruit::getName() const{
    return name;
}
double Fruit::getPrice() const{
    return price;
}
int Fruit::getQuantity() const{
    return quantity;
}

//setters
void Fruit::setPrice(double p){
    price = p;
}
void Fruit::setQuantity(int q){
    quantity = q;
}

// other funcs:
double Fruit::calculateSum() const{ // total price
    return price * quantity;
}

double Fruit::calculateDiscount(double percent) const{
    return calculateSum() * (1 - percent / 100); // discount
}

bool Fruit::isAvailable() const{ // availability
    return quantity > 0;
}

void Fruit::updateItem(std::string n, double p, int q){
    name = n;
    price = p;
    quantity = q; // updates item detail
}

void Fruit::displayItem() const{
    std::cout << "Fruit" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Price: PHP " << price << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Total: PHP " << calculateSum() << std::endl;
}

class Vegetable : public GroceryItem{
public:
    // Constructors
    Vegetable();
    Vegetable(std::string, double, int);
    Vegetable(const Vegetable&);              // Copy Constructor
    Vegetable& operator=(const Vegetable&);   // Copy Assignment Operator
    ~Vegetable() override;                        // Destructor

    // Getters
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;

    // Setters
    void setPrice(double);
    void setQuantity(int);

    // Other Functions
    double calculateSum() const override;
    double calculateDiscount(double percent) const;
    bool isAvailable() const;
    void updateItem(std::string, double, int);
    void displayItem() const override;
};

// vegetable funcs
Vegetable::Vegetable() : GroceryItem() {}

Vegetable::Vegetable(std::string n, double p, int q) : GroceryItem(n,p,q) {}

Vegetable::Vegetable(const Vegetable& other) : GroceryItem(other) {}

Vegetable& Vegetable::operator=(const Vegetable& other){
    if (this != &other){
        GroceryItem::operator=(other);
    }
    return *this;
}

Vegetable::~Vegetable() {}

// getters
std::string Vegetable::getName() const{
    return name;
}
double Vegetable::getPrice() const{
    return price;
}
int Vegetable::getQuantity() const{
    return quantity;
}

// setters
void Vegetable::setPrice(double p){
    price = p;
}
void Vegetable::setQuantity(int q){
    quantity = q;
}

// other funs: vegies
double Vegetable::calculateSum() const{
    return price * quantity;
}

// Computes the total after discount
double Vegetable::calculateDiscount(double percent) const{
    return calculateSum() * (1 - percent / 100);
}

// Checks if the item is available
bool Vegetable::isAvailable() const{
    return quantity > 0;
}

// Updates all item information
void Vegetable::updateItem(std::string n, double p, int q){
    name = n;
    price = p;
    quantity = q;
}

// Displays the item details
void Vegetable::displayItem() const{
    std::cout << "Vegetables" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Price: PHP " << price << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
    std::cout << "Total: PHP " << calculateSum() << std::endl;
}


double TotalSum(GroceryItem* GroceryList[], int size){ // problem 3   
    double total = 0;

    // adds price for all 
    for(int i = 0; i < size; i++){
        if(GroceryList[i] != nullptr){
            total += GroceryList[i]->calculateSum();
        }
    } 
    return total;
}

int main(){

    // array of pointers (dynamic memory allocation) problem 2
    GroceryItem* GroceryList[4];

    // allocate memory using 'new'
    GroceryList[0] = new Fruit("Apple",10,7);
    GroceryList[1] = new Fruit("Banana",10,8);
    GroceryList[2] = new Vegetable("Broccoli",60,12);
    GroceryList[3] = new Vegetable("Lettuce",50,10);

    std::cout << "JENNA'S GROCERY LIST" << std::endl << std::endl;
    // display all
    for(int i = 0; i < 4; i++){
        GroceryList[i]->displayItem(); // uses -> because GroceryList[i] is a ptr
        std::cout << std::endl;
    }

    std::cout << "---------------------" << std::endl; // problem 3
    std::cout << "Total Grocery Cost: PHP " << TotalSum(GroceryList, 4) << std::endl 
                << std::endl;

    // problem 4
    std::cout << "Deleting Lettuce..." << std::endl;

    delete GroceryList[3];
    GroceryList[3] = nullptr;

    std::cout << "Lettuce has been removed from the grocery list." << std::endl << std::endl;

    std::cout << "UPDATED GROCERY LIST: " << std::endl;
    for(int i = 0; i < 4; i++){
        if(GroceryList[i] != nullptr){
            GroceryList[i]->displayItem();
            std::cout << std::endl;
        }
    }

    // freeing dynamically allocated memory
    for(int i = 0; i < 4; i++){
        delete GroceryList[i];
}

    return 0;
}
