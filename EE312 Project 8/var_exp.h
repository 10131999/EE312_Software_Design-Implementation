//
// Created by zanez on 8/13/2020.
//

#ifndef PROJECT8_VAR_EXP_H
#define PROJECT8_VAR_EXP_H
#include <vector>
#include <iostream>
using namespace std;

class var_exp {
public:
    bool isval;
    int val;
    char variable;
    var_exp* left;
    var_exp* right;
    /*
    * If the node carries an operator, what should be the value of     *
     * operand passed in?     *
     * A: 0     *
     * B: NULL     *
     * C: Any int you like     *
     * D: Anything at all     */
    var_exp(bool isOperand, int operand, char optr) {
        left = nullptr;
        right = nullptr;
        this->isval = isOperand;
        this->val = operand;
        this->variable = optr;
    }
    void print() {
        if (isval) {
            cout << val << endl;
        } else {
            cout << variable << endl;
        }
    }
};
class ExpTree {
private:
    const int spaces_per_level = 4;
    var_exp* overallRoot;
    var_exp* add(var_exp* root, vector<var_exp*>&);
    void printTree(var_exp*, int);
    void printSpaces(int);
    int parse(var_exp*);
    var_exp* copy(const var_exp* that);
    void destroy(var_exp*);
public:
    int parse();
    ExpTree(vector<var_exp*>& expr);// constructor
    void printTree();
    ExpTree(const ExpTree& that);
    ExpTree& operator=(const ExpTree& that);
    ~ExpTree();
};


#endif //PROJECT8_VAR_EXP_H
