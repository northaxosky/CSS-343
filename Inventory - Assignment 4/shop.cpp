#include "shop.h"

void Shop::addMovie(Movie* movie)   {
    inventory.add(movie);
}

void Shop::addCustomer(Customer* customer)  {
    if (customer && customer->getID())   {
        customers.insert(customer->getID(), customer);
    }
}

Customer* Shop::findCustomer(int id)  {
    Customer* c = nullptr;
    customers.retrieve(id, c);
    return c;
}

void Shop::processInventory() {
    cout << "Inventory: " << endl;
    cout << inventory << endl;

}

void Shop::processHistory(int id) {
    Customer* customer = nullptr;
    customers.retrieve(id, customer);
    if (customer)   {
        customer->getHistory();
    }
    else    {
        cout << "Customer ID: " << id << " not found";
    }
}

void Shop::processBorrow(int id, char type, string details, string command)   {
    Customer* customer = findCustomer(id);
    if (!customer)  {
        cout << "Customer ID: " << id << " not found";
        return;
    }

    Movie* movie = inventory.find(details);
    if (!movie) {
        cout << "Movie: " << details << " DNE" << endl;
        return;
    }
    if (type != movie->type)    {
        cout << " Movie Type not compatible" << endl;
        return;
    }
    if (!movie->updateStock(-1))    {
        cout << "No movies available to borrow";
    }
    else    {
        customer->addHistory(command);
        customer->borrow(movie);
    }
}

void Shop::processReturn(int id, char type, string details, string command)   {
    Customer* customer = findCustomer(id);
    if (!customer)  {
        cout << "Customer ID: " << id << " not found";
        return;
    }

    Movie* movie = inventory.find(details);
    if (!movie) {
        cout << "Movie: " << details << " DNE" << endl;
        return;
    }
    if (type != movie->type)    {
        cout << " Movie Type not compatible" << endl;
        return;
    }
    if (customer->release(movie))   {
        movie->updateStock(1);
        customer->addHistory(command);
    }
    else    {
        cout << movie->getTitle() << "failed to return by " << customer->getID() << endl;
    }
}