#include "kNN.hpp"

 void tc1(){
     Dataset dataset;
     dataset.loadFromCSV("mnist.csv");
    dataset.printHead();
    cout << endl;
    dataset.printTail();
    cout << endl;
     int nRows, nCols;
     dataset.getShape(nRows, nCols);
     cout << "Shape: " << nRows << "x" << nCols << endl;
     //dataset.printHead(200, 200);

     kNN knn;
     Dataset X_train, X_test, y_train, y_test;
     Dataset feature = dataset.extract(0, -1, 1, -1);
     Dataset label = dataset.extract(0, -1, 0, 0);
     train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
     //y_train.printHead(200, 200);
    knn.fit(X_train, y_train);
    Dataset y_pred = knn.predict(X_test);
    double accuracy = knn.score(y_test, y_pred);
    cout << "Accuracy: " << accuracy << endl;
 }

void tc_knn_p(int k, int size_X){
int nRows, nCols;
Dataset dataset;
dataset.loadFromCSV("mnist.csv");

kNN knn = kNN(k);
Dataset X_train, X_test, y_train, y_test;
Dataset feature = dataset.extract(0, size_X, 1, -1);
Dataset label = dataset.extract(0, size_X, 0, 0);

train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
knn.fit(X_train, y_train);
Dataset y_pred = knn.predict(X_test);

cout << "y_pred" << endl;
y_pred.printHead(10, 10);
cout << endl;
cout << "y_test" << endl;
y_test.printHead(10, 10);
cout << endl;
}

void tc_knn_score(int k, int size_X){
int nRows, nCols;
Dataset dataset;
dataset.loadFromCSV("mnist.csv");

kNN knn = kNN(k);
Dataset X_train, X_test, y_train, y_test;
Dataset feature = dataset.extract(0, size_X, 1, -1);
Dataset label = dataset.extract(0, size_X, 0, 0);

train_test_split(feature, label, 0.2, X_train, X_test, y_train, y_test);
knn.fit(X_train, y_train);
Dataset y_pred = knn.predict(X_test);
double accuracy = knn.score(y_test, y_pred);
cout << "Accuracy: " << accuracy << endl;
}
void tc1205()
{
tc_knn_score(10, 10);
}
void tc1204()
{
tc_knn_score(5, -1);
}
void tc1188()
{
tc_knn_p(3, -1);
}
int main() {
    tc1205();
    return 0;
}



