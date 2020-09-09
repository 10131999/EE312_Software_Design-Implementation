//
// Created by zanez on 8/13/2020.
//

#include "var_exp.h"
#define DEBUG true
ExpTree::ExpTree(vector<var_exp*>& expr) { // construct from expression vector
    overallRoot = add(overallRoot, expr);}
    // private method
var_exp* ExpTree::add(var_exp* root, vector<var_exp*>& expr) { // passing expr as a reference
    var_exp* first = expr[0]; // store the first element
    expr.erase(expr.begin()); // remove the first element
    root = first; // root points to the first token Node
    if (!(first->isval)) { // if first is an operator, add 2 operands
        root->left = add(root->left, expr);
        root->right = add(root->right, expr);
    }
    return root; // return the new sub-tree
}
void ExpTree::printTree() {
    printTree(overallRoot, 0); // call helper method
}
void ExpTree::printSpaces(int level) { // print 4 spaces per level, for indentation
    for (int i = 0; i < level*4; i++) {
        cout << ' ';
    }
}// private recursive helper method
void ExpTree::printTree(var_exp* root, int level) {
    if (root == nullptr) return;
    printTree(root->right, level+1); // print the right sub-tree
    printSpaces(level); // print the indentation for the root of sub-tree
    root->print(); // print the root
    printTree(root->left, level+1); // print the left sub-tree

}
int ExpTree::parse() {
    return parse(overallRoot);
}
int ExpTree::parse(var_exp* root) {
    if (root->isval) return root->val;
    int arg1 = parse(root->left);
    int arg2 = parse(root->right);
    if (root->variable == '+'){
        return arg1 + arg2;
    }else if (root->variable == '-'){
        return arg1 - arg2;
    }else if (root->variable == '*'){
        return arg1 * arg2;
    }else if (root->variable == '/'){
        return arg1 / arg2;
    }else if (root->variable == '%'){
        return  arg1 % arg2;
    }

}// copy constructor, assignment operator, destructor
var_exp* ExpTree::copy(const var_exp* that) {
    var_exp* n = new var_exp(that->isval, that->val, that->variable );
    if (that->left != nullptr)
        n->left = copy(that->left);
    if (that->right != nullptr)
        n->right = copy(that->right);
    return n;
}
ExpTree::ExpTree(const ExpTree& that) {
    overallRoot = copy(that.overallRoot);
}
ExpTree& ExpTree::operator=(const ExpTree& that) {
    if (this != &that) {
        destroy(overallRoot);
        overallRoot = copy(that.overallRoot);
    }
    return *this;
}
ExpTree::~ExpTree() {
    destroy(overallRoot);
}
void ExpTree::destroy(var_exp* n) {
    if (n == nullptr)
        return;
    destroy(n->left);
    destroy(n->right);
    delete n;
    n = nullptr;
}
