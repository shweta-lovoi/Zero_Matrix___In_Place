//Write an algorithm suc that if an element in an MxN matrix is 0, it's entire row and column are set to 0(IN PLACE)

#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> matrix {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
//    std::vector<std::vector<int>> matrix {{2, 1, 2, 0}, {3, 0, 5, 2}, {1, 0, 3, 5}, {1,2,3,4}};
//  std::vector<std::vector<int>> v {{0, 1, 0}, {1, 1, 1}, {1, 1, 1}};
//  std::vector<std::vector<int>> v {{1, 1, 0, 1}};
//  std::vector<std::vector<int>> v {{0},{1}};
    //counters for first row or column having a 0. Need to check first since if we dont and it does have a 0 in the
    //first run through it will change all the rows and cols to 0 in 1st row and col leading to a matrix of all zero's
    std::cout << "Matrix before transformation: \n";
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << " " << matrix[i][j] << " ";
        std::cout << std::endl;
    }

    bool isRow = false, isCol = false;
    //find if first row or col has a zero
    //go over the first row
    int row = 0, col = 0;
    for(int i = 0; i < matrix[0].size(); i++){
        if(matrix[0][i] == 0) {
            isRow = true;
            break;
        }
    }
    //go over the first column
    for(int i = 0; i < matrix.size(); i++){
        if(matrix[i][0] == 0) {
            isCol = true;
            break;
        }
    }

    //check if rows have 0 and put it on the first row of the matrix. Start with 1 instead of 0 since we checked first
    //row and column already.
    for(int i = 1; i < matrix.size(); i++){
        for(int j = 1; j < matrix[i].size(); j++)
            if(matrix[i][j] == 0){
                //put a 0 in the row and column
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
    }

    //if first row or column is 0 change them.
    std::cout << "Matrix AFTER first sweep to transform the ourter row and column: \n";
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << " " << matrix[i][j] << " ";
        std::cout << std::endl;
    }

    //change the columns to zero based off of the first row
    for(int i = 1; i < matrix[0].size(); i++){
        if(matrix[0][i] == 0){
            for(int j = 0; j < matrix.size(); j++)
                matrix[j][i] = 0;
        }
    }

    //change the rows to 0 based off the first column
    for(int i = 1; i < matrix.size(); i++){
        if(matrix[i][0] == 0){
            for(int j = 0; j < matrix[0].size(); j++)
                matrix[i][j] = 0;
        }
    }

    //if the row 1 has 0 make all elements 0
    if(isRow) {
        for (int i = 0; i < matrix[0].size(); i++) {
            matrix[0][i] = 0;
        }
    }

    //if the col 1 has 0 then make all elements 0
    if(isCol){
        for(int i = 0; i < matrix.size(); i++){
            matrix[i][0] = 0;
        }
    }

    //if first row or column is 0 change them.
    std::cout << "Matrix AFTER transformation: \n";
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            std::cout << " " << matrix[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
