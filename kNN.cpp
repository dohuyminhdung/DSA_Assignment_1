#include "kNN.hpp"
#define INT_MAX 2147483647
/* TODO: You can implement methods, functions that support your data structures here.*/
// DSLK WORKS
template <typename T>
dslk<T>::dslk() : head(NULL), tail(NULL), size(0){}

template <typename T>
dslk<T>::~dslk(){
    clear(); }

template <typename T>
void dslk<T>::push_back(T value){
    node<T>* tmp = new node<T>(value);
    if(!size){
        head = tmp;
        tail = tmp;
        size = 1;
    }
    else{
        tail->next = tmp;
        tail = tmp;
        size++;
    }
}

template <typename T>
void dslk<T>::push_front(T value){
    node<T>* tmp = new node<T>(value);
    if(!size){
        head = tmp;
        tail = tmp;
        size = 1;
    }
    else{
        tmp->next = head;
        head = tmp;
        size++;
    }
}

template <typename T>
void dslk<T>::insert(int index, T value){
    if(index < 0 || index > size) return;
    if(index == 0) push_front(value);
    else if(index == size) push_back(value);
    else{
        node<T>* ans = new node<T>(value);
        node<T>* tmp = head;
        for(int i = 0; i < index - 1; i++) tmp = tmp->next;
        ans->next = tmp->next;
        tmp->next = ans;
        size++;
    }
}

template <typename T>
void dslk<T>::remove(int index){
    if(index < 0 || index >= size) return;

    if(size == 1){
        delete head;
        head = tail = NULL;
    }

    else if(index == 0){
        node<T>* tmp = head;
        head = head->next;
        delete tmp;
    }
    else if (index == size -1) {
        node<T>* p = head;
        for (int i = 0; i < size-2; ++i) {
            p = p->next;
        }
        delete tail;
        tail = p; tail->next = NULL;
    }
    else{
        node<T>* pre = NULL;
        node<T>* cur = head;
        for(int i = 0; i < index; i++){
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
    }
    size--;
}

template <typename T>
T& dslk<T>::get(int index) const{
    if(index < 0 || index >= size)
        throw std::out_of_range("get(): Out of range");
    node<T>* tmp = head;
    for(int i = 0; i < index; i++) tmp = tmp->next;
    return tmp->val;
}

template <typename T>
int dslk<T>::length() const{ return size; }

template <typename T>
void dslk<T>:: clear(){
    while(head){
        node<T>* del = head;
        head = head->next;
        delete del;
    }
    tail = NULL;
    size = 0;
}

template <typename T>
void dslk<T>::print() const{ cout << "can't print" << endl; }

template <typename T>
void dslk<T>::reverse(){
    node<T>* pre = NULL;
    node<T>* in = head;
    node<T>* post = NULL;

    tail = head;
    while(in){
        post = in->next;
        in->next = pre;
        pre = in;
        in = post;
    }
    head = pre;
}

//LIST WORKS
list::list():head(NULL), tail(NULL), size(0){}
list::~list(){} //kh goi clear

void list::push_back(int value){
    node<int>* tmp = new node<int>(value);
    if(!size){
        head = tmp;
        tail = tmp;
        size = 1;
    }
    else{
        tail->next = tmp;
        tail = tmp;
        size++;
    }
}

void list::push_front(int value){
    node<int>* tmp = new node<int>(value);
    if(!size){
        head = tmp;
        tail = tmp;
        size = 1;
    }
    else{
        tmp->next = head;
        head = tmp;
        size++;
    }
}

void list::insert(int index, int value){
    if(index < 0 || index > size) return;
    if(index == 0) push_front(value);
    else if(index == size) push_back(value);
    else{
        node<int>* ans = new node<int>(value);
        node<int>* tmp = head;
        for(int i = 0; i < index - 1; i++) tmp = tmp->next;
        ans->next = tmp->next;
        tmp->next = ans;
        size++;
    }
}

void list::remove(int index){
    if(index < 0 || index >= size) return;

    if(size == 1){
        delete head;
        head = tail = NULL;
    }

    else if(index == 0){
        node<int>* tmp = head;
        head = head->next;
        delete tmp;
    }
    else if (index == size -1) {
        node<int>* p = head;
        for (int i = 0; i < size-2; ++i) {
            p = p->next;
        }
        delete tail;
        tail = p; tail->next = NULL;
    }
    else{
        node<int>* pre = NULL;
        node<int>* cur = head;
        for(int i = 0; i < index; i++){
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        delete cur;
    }
    size--;
}

int& list::get(int index) const{
    if(index < 0 || index >= size)
        throw std::out_of_range("get(): Out of range");
    node<int>* tmp = head;
    for(int i = 0; i < index; i++) tmp = tmp->next;
    return tmp->val;
}

int list::length() const{ return size; }

void list::clear(){
    while(head){
        node<int>* del = head;
        head = head->next;
        delete del;
    }
    tail = NULL;
    size = 0;
}

void list::reverse(){
    node<int>* pre = NULL;
    node<int>* in = head;
    node<int>* post = NULL;

    tail = head;
    while(in){
        post = in->next;
        in->next = pre;
        pre = in;
        in = post;
    }
    head = pre;
}

void list::print() const{
    node<int>* tmp = this->head;
    string s = "";
    while(tmp){
        s += to_string(tmp->val) + ' ';
        tmp = tmp -> next;
    }
    s.pop_back();
    cout << s;// << endl;
}

void list::setval(int index, int val){
    if(index < 0 || index >= size)
        throw std::out_of_range("get(): Out of range");
    node<int>* tmp = head;
    for(int i = 0; i < index; i++) tmp = tmp->next;
    tmp->val = val;
}


//DATASET WORKS
Dataset::Dataset(): data(new dslk<list*>()), info("") {}
Dataset::~Dataset(){
    for(int i = 0; i < data->length(); i++){
        data->get(i)->clear();
    }
    delete data;
    info = "";
}
Dataset::Dataset(const Dataset& other): data(new dslk<list*>()),
                                        info(other.info){
    int col  = other.data->get(0)->length();
    for(int i = 0; i < other.data->length(); i++){
        list* tmp = other.data->get(i);
        node<int>* curNode = tmp->head;
        list* cur = new list();
        //this->data->push_back(new list());
        for(int j = 0; j < col; j++){
            cur->push_back(curNode->val);
            curNode = curNode->next;
            //this->data->get(i)->push_back(tmp->get(j));
        }
        this->data->push_back(cur);
    }
}

Dataset& Dataset::operator=(const Dataset& other){
    for(int i = 0; i < this->data->length(); i++){
        this->data->get(i)->clear();
    }
    delete this->data;


    this->data = new dslk<list*>();
    int col = other.data->get(0)->length();


    for(int i = 0; i < other.data->length(); i++){
        list* tmp = other.data->get(i);
        node<int>* curNode = tmp->head;
        list* cur = new list();
        //this->data->push_back(new list());
        for(int j = 0; j < col; j++){
            cur->push_back(curNode->val);
            curNode = curNode->next;
            //this->data->get(i)->push_back(tmp->get(j));
        }
        this->data->push_back(cur);
    }
    this->info = other.info;
    return *this;
}

bool Dataset::loadFromCSV(const char* fileName){
    //open file
    std::ifstream file(fileName);
    if(!file.is_open()) return 0;

    //reset data
    for(int i = 0; i < data->length(); i++){
        this->data->get(i)->clear();
    }
    delete this->data;
    this->info = "";
    this->data = new dslk<list*>();

    //find mrow, mcol and info
    string line;
    std::getline(file, line);

    std::istringstream iss(line);
    string token;

    while (std::getline(iss, token, ',')) {
        info += token + ' ';
    }
    info.pop_back();

    //read line, type input
    while(std::getline(file, line)){
        std::istringstream in(line);
        string tmp;
        list* newr = new list();

        while(std::getline(in, tmp, ',')){
            int num;
            //std::istringstream(tmp) >> num;
            num = stoi(tmp);
            newr->push_back(num);
        }
        this->data->push_back(newr);
    }

    file.close();
    return 1;

}
void Dataset::printHead(int nRows, int nCols) const{
    if(nRows <= 0 || nCols <= 0) return;

    if(nRows > this->data->length())
        nRows = this->data->length();
    if(nCols > this->data->get(0)->length())
        nCols = this->data->get(0)->length();


    std::istringstream iss(info);
    string s = "";
    for(int i = 0; i < nCols; i++){
        string tmp = "";
        getline(iss, tmp, ' ');
        s += tmp + ' ';
    }
    s.pop_back();
    cout << s << endl;

    node<list*>* cur = this->data->head;
    for(int i = 0; i < nRows; i++){
        list* tmp = cur->val;
        cur = cur->next; 
        node<int>* curNum = tmp->head;
        //list* tmp = this->data->get(i);
        for(int j = 0; j  < nCols; j++){
            //cout<<tmp->get(j);
            cout << curNum->val;
            curNum = curNum->next;
            if(j != nCols - 1) cout<<' ';
        }
        if(i!= nRows - 1) cout<<endl;
    }
}
void Dataset::printTail(int nRows, int nCols) const{
    if(nRows <= 0 || nCols <= 0) return;

    int mrow = this->data->length();
    int mcol = this->data->get(0)->length();

    if(nRows > mrow) nRows = mrow;
    if(nCols >= mcol) nCols = mcol;


    int count = mcol - nCols;
    int row = mrow - nRows;

    std::istringstream iss(info);
    string tmp = "";
    for(int i = 0; i < count; i++) getline(iss, tmp, ' ');
    string ifm = "";
    for(int i = count; i < mcol; i++){
        getline(iss, tmp, ' ');
        ifm += tmp + ' ';
    }
    ifm.pop_back();
    cout << ifm << endl;

     for(int i = row; i < mrow; i++){
         list* tmp = this->data->get(i);
         for(int j = count; j  < mcol; j++){
             cout<<tmp->get(j);
             if(j != this->data->get(0)->length() - 1)
                 cout<<' ';
         }
         if(i != mrow - 1) cout<<endl;
     }

}
void Dataset::getShape(int& nRows, int& nCols) const{ nRows = data->length();     nCols = data->get(0)->length(); }
void Dataset::columns() const{ cout<<this->info; }
bool Dataset::drop(int axis, int index, std::string columns){
    if(axis != 0 && axis != 1) return 0;
    if(!axis){ //delete row
        if(index >= this->data->length() || index < 0) return 0;
        this->data->remove(index);
    }
    else{
        int count = 0;
        std::istringstream iss(info);
        string s = "", tmp = "";
        bool flag = 1;
        while(getline(iss, tmp, ' ')){
            if(tmp == columns){ flag = 0; continue; }
            s += tmp + ' ';
            if(flag) count++;
        }
        if(flag) return 0;
        s.pop_back(); info = s;

        node<list*>* cur = this->data->head;
        for(int i = 0; i < this->data->length(); i++){
            list* tmp = cur->val;
            cur = cur->next; 
            tmp->remove(count);
            //this->data->get(i)->remove(count);
        }

    }
    return 1;
}
string Dataset::getinfo() const {return this->info;}
dslk<list*>* Dataset::getData() const{ return this->data; }
//list là danh sách liên kết riêng cho int
Dataset Dataset::extract(int startRow, int endRow, int startCol, int endCol) const{
    Dataset ans;

    if(endRow == -1) endRow = this->data->length() - 1;
    else endRow = min(endRow, this->data->length() - 1);
    if(endCol == -1) endCol = this->data->get(0)->length() - 1;
    else endCol = min(endCol, this->data->get(0)->length() - 1);
    //int newi = 0; //index of the return data

    for(int i = startRow; i <= endRow; i++){
        list* copy = this->data->get(i);
        list* cur = new list();
        //ans.data->push_back(new list());
        for(int j = startCol; j <= endCol; j++){
            cur->push_back(copy->get(j));
            //ans.data->get(newi)->push_back(copy->get(j));
        }
        ans.data->push_back(cur);
        //newi++;
    }


    int count = 0; //count how many times that (' ') appear
    int start = 0, end = 0;
    while(count < startCol && start < this->info.size()){
        if( start < this->info.size() && this->info[start++] == ' ') count++;
    }

    end = start;
    while(count <= endCol && end < this->info.size()){
        if(end < this->info.size() && this->info[end++] == ' ') count++;
    }
    ans.info = this->info.substr(start, end - start);


    return ans;
}

void Dataset::setinfo(string s){ info = s; }
void Dataset::push(list* row){data->push_back(row);}



//other class

map::map() : head(NULL){}
map::~map(){ clear(); }
void map::add(int key){
    if(head){
        pair* tmp = head;
        pair* tail = NULL;
        while(tmp){
            tail = tmp;
            if(tmp->key == key){ tmp->val++; return; }
            tmp = tmp->next;
        }
        tail->next = new pair(key);
    }
    else head = new pair(key);
}
int map::maxkey(){
    if(!head) return -1; //error
    int key = -1, val = 0;
    pair* tmp = head;
    while(tmp){
        if(tmp->val > val){
            key = tmp->key;
            val = tmp->val;
        }
        else if(tmp->val == val && tmp->key < key) key = tmp->key;
        tmp = tmp->next;
    }
    return key;
}
void map::clear(){
    while(head){
        pair* del = head;
        head = head->next;
        delete del;
    }
}


kNN::kNN(int k): k(k){}

//1. Tải dữ liệu.
void kNN::fit(const Dataset& X_train, const Dataset& y_train){ 
    if(X_train.getData()->length() < k)
        throw std::out_of_range("get(): Out of range");
    xtrain = X_train;    
    ytrain = y_train;
}


Dataset kNN::predict(const Dataset& X_test){

    int trainr = 0, col = 0, testr = 0;
    X_test.getShape(testr, col);
    xtrain.getShape(trainr, col);

    dslk<list> cd; //counting distance
    node<list*>* curNode = X_test.getData()->head;
    for(int row = 0; row < testr; row++){
        //list* testdata = X_test.getData()->get(row);
        //cd.push_back(list());
        list* testdata = curNode->val;
        curNode = curNode->next;
        list dis;

        node<list*>* tmpNode = xtrain.getData()->head;
        for(int i = 0; i < trainr; i++){
            //list* traindata = xtrain.getData()->get(i);
            list* traindata = tmpNode->val;
            tmpNode = tmpNode->next;

            int sum = 0;
            for(int j = 0; j < col; j++){
                int a = traindata->get(j);
                int b = testdata->get(j);
                int sub = a - b;
                sum += sub * sub;
            }
            //cd.get(row).push_back(sum);
            dis.push_back(sum);
        }
        cd.push_back(dis);
    }

    dslk<list> idx;//save indices of k smallest label of ytrain
    node<list>* nodeDis = cd.head;
    for(int row = 0; row < testr; row++){
        //idx.push_back(list());
        //list tmp = cd.get(row);
        list tmp = nodeDis->val;
        nodeDis = nodeDis->next;
        list tmpIdx;

        node<int>* Head = tmp.head;
        for(int i = 0; i < k; i++){
            int mini = 0; //index
            node<int>* minVal = Head;
            node<int>* curVal = Head->next;
            for(int j = 1; j < tmp.length(); j++){
                if(minVal->val > curVal->val){
                    mini = j;
                    minVal = curVal;
                } 
                curVal = curVal->next;
            }
            //idx.get(row).push_back(mini);
            //tmp.setval(mini, INT_MAX);
            tmpIdx.push_back(mini);
            minVal->val = INT_MAX;
        }
        idx.push_back(tmpIdx);
        //idx.get(row).print();
    }


    Dataset y_test; y_test.setinfo("label");
    dslk<list*>* trainres = ytrain.getData();//label of train data
    node<list>* nodeKfound = idx.head; 

    for(int row = 0; row < testr; row++){
        //y_test.getData()->push_back(new list());
        //list kfound = idx.get(row);//chứa k vị trí của ytrain
        list kfound = nodeKfound->val;
        nodeKfound = nodeKfound->next;
        list* ans = new list(); 

        node<int>* kVal = kfound.head;
        map search;
        for(int i = 0; i < k; i++){
            //int inOY = kfound.get(i);
            int inOY = kVal->val;
            kVal = kVal->next;
            search.add(trainres->get(inOY)->get(0));
        }
        //y_test.getData()->get(row)->push_back(search.maxkey());
        ans->push_back(search.maxkey());
        y_test.getData()->push_back(ans);
        //y_test.getData()->get(row)->print();
    }

    return y_test;
}
double kNN::score(const Dataset& y_test, const Dataset& y_pred){
    int correct = 1, total = 0; //total is row
    y_test.getShape(total, correct);
    correct = 0;

    //dslk<list*>* test = y_test.getData();
    //dslk<list*>* pred = y_pred.getData();
    node<list*>* test = y_test.getData()->head;
    node<list*>* pred = y_pred.getData()->head;

    for(int i = 0; i < total; i++){
        if(test->val->get(0) == pred->val->get(0))
            correct++;
        test = test->next;
        pred = pred->next;
    }
    double ans = (correct / 1.0) / (total / 1.0);
    return ans;
}


void train_test_split(Dataset& X, Dataset& y, double test_size,
                      Dataset& X_train, Dataset& X_test, Dataset& y_train, Dataset& y_test){
    test_size = 1 - test_size;
    int trainr = 0, col = 0;
    X.getShape(trainr, col);
    int row = trainr;
    trainr = int(test_size * trainr);

    X_train = X.extract(0     , trainr - 1, 0, -1);
    X_test =  X.extract(trainr, -1        , 0, -1);
    y_train = y.extract(0     , trainr - 1, 0, 0);
    y_test =  y.extract(trainr, -1        , 0, 0);
}


































