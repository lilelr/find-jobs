//
// Created by YuXiao on 4/13/18.
//


#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;
//

//6
//45 12 45 32 5 6
//3
//3 2 1
//1
//1
//2
//1 1
//4
//1 1 1 1
//4
//1 1 2 2

/** 请完成下面这个函数，实现题目要求的功能 **/
/** 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^  **/
int calculate(int cash00, int rows, int cols, int **entryfees, int **prices) {
//    for (int i=0;i<rows;i++){
//        for(int j=0;j<cols;j++){
//            cout<< entryfees[i][j];
//        }
//        cout<<endl;
//    }
    vector<vector<int>> dp_own(rows);
    vector<vector<int>> dp_nonown(rows);
    for (int i = 0; i < rows; i++) {
        dp_own[i] = vector<int>(cols, 0);
        dp_nonown[i] = vector<int>(cols, 0);
    }

    dp_own[0][0] = cash00 - prices[0][0];
    dp_nonown[0][0] = cash00;
    int terminate = -1;
    for (int j = 1; j < cols; j++) {
        int &ans_own = dp_own[0][j];
        int &ans_nonown = dp_nonown[0][j];
        if (dp_own[0][j - 1] >= entryfees[0][j]) {
            int remain = dp_own[0][j - 1] - entryfees[0][j];
            ans_own = remain;
            ans_nonown = remain + prices[0][j];

        } else {
            ans_own = terminate;
            ans_nonown = terminate;
        }

        if (dp_nonown[0][j - 1] >= entryfees[0][j]) {

            int remain = dp_nonown[0][j - 1] - entryfees[0][j];
            ans_nonown = max(ans_nonown, remain);
            ans_own = max(ans_own, remain - prices[0][j]);
        }
    }

    for (int i = 1; i < rows; i++) {
        int &ans_own = dp_own[i][0];
        int &ans_nonown = dp_nonown[i][0];
        if (dp_own[i - 1][0] >= entryfees[i][0]) {
            int remain = dp_own[i - 1][0] - entryfees[i][0];
            ans_own = remain;
            ans_nonown = remain + prices[i][0];
        } else {
            ans_own = terminate;
            ans_nonown = terminate;
        }

        if (dp_nonown[i - 1][0] >= entryfees[i][0]) {
            int remain = dp_nonown[i - 1][0] - entryfees[i][0];
            ans_own = max(ans_own, remain - prices[i][0]);
            ans_nonown = max(ans_nonown, remain);
        }
    }

    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            int &ans_own = dp_own[i][j];
            int &ans_nonown = dp_nonown[i][j];

            int pre_own = max(dp_own[i - 1][j], dp_own[i][j - 1]);
            int pre_nonown = max(dp_nonown[i - 1][j], dp_nonown[i][j - 1]);

            if (pre_own >= entryfees[i][j]) {
                int remain = pre_own - entryfees[i][j];
                ans_own = remain;
                ans_nonown = remain + prices[i][j];
            } else {
                ans_own = ans_nonown = terminate;
            }

            if (pre_nonown >= entryfees[i][j]) {
                int remain = pre_nonown - entryfees[i][j];
                ans_own = max(ans_own, remain - prices[i][j]);
                ans_nonown = max(ans_nonown, remain);
            }
        }
    }

    int res = max(dp_own[rows - 1][cols - 1], dp_nonown[rows - 1][cols - 1]);
    return res;


}

int main() {
    int res;

    int _cash00;
    scanf("%d", &_cash00);

    int _rows;
    scanf("%d", &_rows);

    int _cols;
    scanf("%d", &_cols);

    int _entryfees_rows = _rows;
    int _entryfees_cols = _cols;

    int **_entryfees = (int **) malloc(_entryfees_rows * sizeof(int *));
    int _entryfees_init_i = 0;
    for (_entryfees_init_i = 0; _entryfees_init_i < _entryfees_rows; ++_entryfees_init_i) {
        _entryfees[_entryfees_init_i] = (int *) malloc(_entryfees_cols * (sizeof(int)));
    }

    int _entryfees_i, _entryfees_j;
    for (_entryfees_i = 0; _entryfees_i < _entryfees_rows; _entryfees_i++) {
        for (_entryfees_j = 0; _entryfees_j < _entryfees_cols; _entryfees_j++) {
            int _entryfees_item;
            scanf("%d", &_entryfees_item);

            _entryfees[_entryfees_i][_entryfees_j] = _entryfees_item;
        }
    }
    int _prices_rows = _rows;
    int _prices_cols = _cols;

    int **_prices = (int **) malloc(_prices_rows * sizeof(int *));
    int _prices_init_i = 0;
    for (_prices_init_i = 0; _prices_init_i < _prices_rows; ++_prices_init_i) {
        _prices[_prices_init_i] = (int *) malloc(_prices_cols * (sizeof(int)));
    }

    int _prices_i, _prices_j;
    for (_prices_i = 0; _prices_i < _prices_rows; _prices_i++) {
        for (_prices_j = 0; _prices_j < _prices_cols; _prices_j++) {
            int _prices_item;
            scanf("%d", &_prices_item);

            _prices[_prices_i][_prices_j] = _prices_item;
        }
    }

    res = calculate(_cash00, _rows, _cols, _entryfees, _prices);
    printf("%d\n", res);

    return 0;

}
