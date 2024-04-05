#include "main.hpp"

/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */

template<typename T>
class List {
public:
    virtual ~List() = default;
    virtual void push_back(T value) = 0;
    virtual void push_front(T value) = 0;
    virtual void insert(int index, T value) = 0;
    virtual void remove(int index) = 0;
    virtual T& get(int index) const = 0;
    virtual int length() const = 0 ;
    virtual void clear() = 0;
    virtual void print() const = 0;
    virtual void reverse() = 0;
};

template<typename T>
class node{
public:
    T val;
    node* next;
    node(T data): val(data), next(NULL){}
};

template<typename T>
class dslk: public List<T>{
//private:
public:
    node<T>* head;
    node<T>* tail;
    int size;
public:
    dslk();
    ~dslk();
    void push_back(T value);
    void push_front(T value);
    void insert(int index, T value);
    void remove(int index);
    T& get(int index) const;
    int length() const;
    void clear();
    void print() const;
    void reverse();
};

class list: public List<int>{
public:
    node<int>* head;
    node<int>* tail;
    int size;
public:
    list();
    ~list();
    void push_back(int value);
    void push_front(int value);
    void insert(int index, int value);
    void remove(int index);
    int& get(int index) const;
    int length() const;
    void clear();
    void print() const;
    void reverse();
    void setval(int index, int val);
};

class Dataset {
private:
    dslk<list*>* data; //list = dslk<int>
    //int nrow; //total number of row --> data.size()
    //int ncol; //total number of col --> data[0].size()
    string info; //label + ixj
    //You may need to define more
public:
    Dataset();
    ~Dataset();
    Dataset(const Dataset& other);
    Dataset& operator=(const Dataset& other);
    bool loadFromCSV(const char* fileName);
    void printHead(int nRows = 5, int nCols = 5) const;
    void printTail(int nRows = 5, int nCols = 5) const;
    void getShape(int& nRows, int& nCols) const;
    void columns() const;
    bool drop(int axis = 0, int index = 0, std::string columns = "");
    Dataset extract(int startRow = 0, int endRow = -1, int startCol = 0, int endCol = -1) const;
    string getinfo() const;
    dslk<list*>* getData() const;
    void setinfo(string s);
    void push(list* row);//push 1 row to data
};

class kNN {
private:
    int k;
    Dataset xtrain;
    Dataset ytrain;
    //You may need to define more
public:
    kNN(int k = 5);
    void fit(const Dataset& X_train, const Dataset& y_train);
    Dataset predict(const Dataset& X_test);
    double score(const Dataset& y_test, const Dataset& y_pred);
};

void train_test_split(Dataset& X, Dataset& y, double test_size,
                      Dataset& X_train, Dataset& X_test, Dataset& y_train, Dataset& y_test);

//double dis(list train, list test);

class map{
private:
    class pair{
    public:
        int key;
        int val;
        pair* next;
        pair(int key): key(key), val(1), next(NULL){}
    };
    pair* head;
public:
    map();
    ~map();
    void add(int key);
    int maxkey(); //tìm nhãn phổ biến nhất
    void clear();
};

