// Kuzey Gok
// CSS 343
// Parser Class cpp
// The parser class is used to parse the input files given
// and act accordingly for the business.
#include "parser.h"
Parser::Parser()    {}

// parse the movies from the given file and add to shop
void Parser::parseInventory(string name)   {
    string line;
    ifstream file(name);

    while(getline(file, line))  {
        Movie* movie = createMovie(line);

        if (movie)
            shop.addMovie(movie);
    }

    file.close();
}

void Parser::parseCustomers(string name)    {
    string line;
    ifstream file(name);

    while (!file.eof())  {
        Customer *cust = new Customer();
        if (cust->setInfo(file))
            shop.addCustomer(cust);
    }

    file.close();
}

void Parser::parseTransactions(string name) {
    ifstream file(name);
    string line;

    while (getline(file, line)) {
        processTransaction(line);
    }
}


/////////////////////////// HELPER FUNCTIONS ///////////////////////////////

// Create Movie function for parsing the inventory
Movie* Parser::createMovie(string line) {
    if (line.length() <= 0)   {
        return nullptr;
    }

    Movie* movie = nullptr;
    istringstream ss(line);
    string genre;
    ss >> genre;

    switch (genre[0])   {
    case 'F':
        movie = new Comedy();
        break;
    case 'D':
        movie = new Drama();
        break;
    case 'C':
        movie = new Classic();
        break;
    default:
        cerr << "Movie type not recognized: " << genre[0] << endl;
    }
    if (movie)
        movie->setInfo(ss);
    return movie;
}

Customer* Parser::createCustomer(string line)   {
    if (line.length() <= 0)
        return nullptr;

    stringstream ss(line);

    string id;
    ss >> id;
    string first;
    ss >> first;
    string last;
    ss >> last;

    int num = stoi(id);
    string name = first + " " + last;
    Customer* customer = new Customer(first, last, num);
    return customer;
}

void Parser::processTransaction(string line)    {
    if (line.length() <= 0)
        return;
    stringstream ss(line);
    string transaction;
    ss >> transaction;

    if (transaction[0] == 'I')  {
        shop.processInventory();
    }

    else if (transaction[0] == 'H')  {
        string strID;
        ss >> strID;
        int id = stoi(strID);
        shop.processHistory(id);
    }
    else if (transaction[0] == 'B') {
        string command = ss.str();
        string strID;
        ss >> strID;
        int id = stoi(strID);
        string temp;
        ss >> temp;
        string movieType;
        ss >> movieType;
        string details;
        getline(ss, details);
        string movie = details;
        movie.erase(remove(movie.begin(), movie.end(), ','), movie.end());
        if (transaction[0] == 'B')
            shop.processBorrow(id, movieType[0], movie, command);
        shop.processReturn(id, movieType[0], movie, command);
    }

}

void Parser::parseString(string& str, const string& chars)   {
    str.erase(str.find_last_not_of(chars) + 1);
    str.erase(0, str.find_first_not_of(chars));
}