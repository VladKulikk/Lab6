#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    double m;

    cout << "enter the size of the square array" << endl;
    cin >> n;

    auto matrix = new double *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }

    cout <<"1-enter size of array from keyboard, another values-random values "<<endl;
    cin >> m ;

    if(m==1){

      cout << "Enter size of the value" << endl;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
      }
    }else{
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100 - 50 ;
        }
      }
    }
    for (int i = 0; i < n; i++) {
        cout << "\n";
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
    }

    cout << "\n\n\n";

    int i1 = 0, j1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(matrix[i][j]) > abs(matrix[i1][j1])) {
                i1 = i;
                j1 = j;
            }
        }
    }

    auto newMatrix = new double *[n - 1];
    for (int i = 0; i < n - 1; i++) {
        newMatrix[i] = new double[n - 1];
    }

    for (int i = 0; i < n; i++) {
        if (i == i1) continue;
        for (int j = 0; j < n; j++) {
            if (j == j1) continue;

            int ii = i > i1 ? i - 1 : i;
            int jj = j > j1 ? j - 1 : j;
            newMatrix[ii][jj] = matrix[i][j];
        }
    }

    for (int i = 0; i < n-1; i++) {
        cout << "\n";
        for (int j = 0; j < n-1; j++) {
            cout << newMatrix[i][j] << " ";
        }
    }

    delete[] matrix;
    delete[] newMatrix;
    return 0;
}