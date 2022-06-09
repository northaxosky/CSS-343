#include "customer.h"

ostream& operator<<(ostream& out, const Customer& cust) {
    return out << cust.getID() << " " << cust.getName();
}

Customer::Customer()    {
    first = "";
    last = "";
    id = 0;
}

Customer::Customer(string first, string last, int id)   {
    this->first = first;
    this->last = last;
    this->id = id;
}

void Customer::addHistory(string hist)  {
    history.push_back(hist);
}

void Customer::getHistory() const {
    cout << getName() << "'s History" << endl;
    for (auto& str : history)
        cout << str << endl;
    cout << endl;
}

void Customer::borrow(Movie* movie)   {
    if (movie)  {
        int quantity = 1;
        if (collection.retrieve(movie->hash(), quantity))   {
            quantity++;
        }
        collection.insert(movie->hash(), quantity);
    }
}

bool Customer::release(Movie* movie)    {
    if (movie)  {
        int quantity = 0;
        if (collection.retrieve(movie->hash(), quantity) && quantity > 0)   {
            quantity--;
            if (quantity > 0)   {
                collection.insert(movie->hash(), quantity);
            }
            else    {
                collection.remove(movie->hash());
            }
        }
        else    {
            return false;
        }
        return true;
    }
    cout << "Movie is Invalid" << endl;
    return false;
}

bool Customer::setInfo(istream& line)   {
    if (line.eof())
        return false;
    
    try {
        string temp;
        getline(line, temp, ' ');
        if (temp.length() == 0)
            return false;
        id = stoi(temp);
        getline(line, first, ' ');
        getline(line, last);
    }   catch (const char *msg) {
        return false;
    }
    return true;
}