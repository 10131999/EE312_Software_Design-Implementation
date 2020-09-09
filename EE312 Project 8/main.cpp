//
// Created by zanez on 8/8/2020.
// 1 slip day used
//


#include "Parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
//#include "Var_linkedlist.h"
#include "math_op.h"
#include "string.h"
#include "var_exp.h"
#include "var_hashtable.h"



using namespace std;

//VARIABLES






// everything above should be deleted before turning in (fixed)



void eval_unary(HashTable ht){
    int x;
    if (!strcmp(next_token(),"~")){
        read_next_token();
        cout << "-" << token_number_value;

    }else if (!strcmp(next_token(),"!")){
        read_next_token();
        if (token_number_value != 0){
            cout << "0";
        }else{
            cout << "1";
        }
    }
    //cout << "done unary" << endl;
}

int eval_logic(math_op w, int y){
        int which;
        if (w.ptr[y] == '&') {
            which = 1;
        }else {
            which = 0;
        }
        //cout << w.ptr[y] ;
        //cout << w.ptr[y + 1] << endl;
        y = y + 3;
        int p = y;
        int z = 1;
        int m = 0;
        int num = 0;
        while (w.ptr[p + 1] != ' ' && w.ptr[p + 1] != '\0'){
            m++;
            p++;
        }
        if(m != 0) {
            while (m != 0) {
                z *= 10;
                m--;
            }
            while (z != 1) {
                num += (w.ptr[y] - 48) * z;
                y++;
                z /= 10;
            }
            num += (w.ptr[y] - 48);
        }else{
            num = w.ptr[y] - 48;
        }
        p = y + 2;
        z = 1;
         m = 0;
        int num1 = 0;
        while (w.ptr[p + 1] != ' ' && w.ptr[p + 1] != '\0'){
            m++;
            p++;
        }
        if(m != 0) {
            while (m != 0) {
                z *= 10;
                m--;
            }
            while (z != 1) {
                num1 += (w.ptr[y] - 48) * z;
                y++;
                z /= 10;
            }
            num1 += (w.ptr[y] - 48);
        }else{
            num1 = w.ptr[y] - 48;
        }

        if ( which == 1){
            if (num != 0 && num1 != 0){
                return 1;
            }else{
                return 0;
            }
        }else{
            if (num == 0 && num1 == 0){
                return 0;
            }else{
                return 1;
            }
        }
}

void eval_comparison(void){
    int x;
    int y;
    if (!strcmp(next_token(),"==")){
        read_next_token();
        x = token_number_value;
        read_next_token();
        y = token_number_value;
        if (x == y){
            cout << "1";
        }else{
            cout << "0";
        }

    }else if (!strcmp(next_token(),"<")){
        read_next_token();
        x = token_number_value;
        read_next_token();
        y = token_number_value;
        if (x < y){
            cout << "1";
        }else{
            cout << "0";
        }
    }else if (!strcmp(next_token(),">")){
        read_next_token();
        x = token_number_value;
        read_next_token();
        y = token_number_value;
        if (x > y){
            cout << "1";
        }else{
            cout << "0";
        }
    }else if (!strcmp(next_token(),"!=")){
        read_next_token();
        x = token_number_value;
        read_next_token();
        y = token_number_value;
        if (x != y){
            cout << "1";
        }else{
            cout << "0";
        }
    }else if (!strcmp(next_token(),"<=")){
        read_next_token();
        x = token_number_value;
        read_next_token();
        y = token_number_value;
        if (x <= y){
            cout << "1";
        }else{
            cout << "0";
        }
    }else if (!strcmp(next_token(),">=")){
        read_next_token();
        x = token_number_value;
        read_next_token();
        y = token_number_value;
        if (x >= y){
            cout << "1";
        }else{
            cout << "0";
        }
    }
    //cout << "done comparison" << endl;
}

void eval_expression(void){
    int i = 0;
    math_op x;
    strcat(x.ptr, next_token());
    //cout << x.ptr << " ";
    x.len ++;


    while(strcmp(peek_next_token(), "text")){
        //
        //
        //
        //DO WORK HERE
        //
        //
        //
        strcat(x.ptr, " ");
        x.len++;
        strcat(x.ptr, next_token());
        x.len ++;

        read_next_token();
    }
    //cout << x.ptr << " ";
    var_exp* vars [x.len];
    int y = 0;
    bool exp;
    while (y <= x.len){
        if (((x.ptr[y] == '+') || (x.ptr[y] == '-') || (x.ptr[y] == '*') || (x.ptr[y] == '/') || (x.ptr[y] == '%')) != 0){
            vars[i] = new var_exp(false, 0, x.ptr[y]);
            i++;
        }else if (((x.ptr[y] == '&') || (x.ptr[y] == '|')) == 1){
            int q = eval_logic(x, y);
            int num_it = 0;
            vars[i] = new var_exp(true, q, '\0');
            i ++;
            while (num_it < 3){
                if(x.ptr[y] == ' '){
                    num_it++;
                }
                y ++;
            }
            y --;


            //cout << "logic read";
        }else if(x.ptr[y] == '~'){
            y ++;
            int p = y;
            int z = 1;
            int m = 0;
            int num = 0;
            while (x.ptr[p + 1] != ' ' && x.ptr[p + 1] != '\0'){
                m++;
                p++;
            }
            if(m != 0) {
                while (m != 0) {
                    z *= 10;
                    m--;
                }
                while (z != 1) {
                    num += (x.ptr[y] - 48) * z;
                    y++;
                    z /= 10;
                }
                num += (x.ptr[y] - 48);
            }else{
                num = x.ptr[y] - 48;
            }

            vars[i] = new var_exp(true, num * -1, '\0');

            i++;
        }else if (x.ptr[y] != ' '){
            int p = y;
            int z = 1;
            int m = 0;
            int num = 0;
            while (x.ptr[p + 1] != ' ' && x.ptr[p + 1] != '\0'){
                m++;
                p++;
            }
            if(m != 0) {
                while (m != 0) {
                    z *= 10;
                    m--;
                }
                while (z != 1) {
                    num += (x.ptr[y] - 48) * z;
                    y++;
                    z /= 10;
                }
                num += (x.ptr[y] - 48);
            }else{
                num = x.ptr[y] - 48;
            }

            vars[i] = new var_exp(true, num, '\0');

            i++;
        }
        y ++;
    }
    vector<var_exp*> expr;
    for (y = 0; y < x.len; y ++){
        expr.push_back(vars[y]);
    }

    //cout << endl;
    ExpTree myTree(expr);
    cout << myTree.parse();
    //myTree.printTree();

}



void output_check (HashTable ht){
    //cout << next_token() << " ";
    math_op check;
    strcat(check.ptr,next_token());
    check.len++;
    if (!strcmp(next_token(),"+") || !strcmp(next_token(),"-") || !strcmp(next_token(),"*") || !strcmp(next_token(),"/") || !strcmp(next_token(),"%")){
        //cout << "Binary math operators" << endl;
        eval_expression();
    }else if (!strcmp(next_token(),"==") || !strcmp(next_token(),"!=") || !strcmp(next_token(),"<=") || !strcmp(next_token(),"<") || !strcmp(next_token(),">") || !strcmp(next_token(),">=")){
        //cout << "Comparison Operators" << endl;
        eval_comparison();
    }else if (!strcmp(next_token(), "&&") || !strcmp(next_token(), "||")){
        //cout << "Logic operators" << endl;
        if (!strcmp(next_token(),"&&")){
            read_next_token();
            int x = token_number_value;
            read_next_token();
            int y = token_number_value;
            if (x != 0 && y !=0){
                cout << "1" << endl;
            }else{
                cout << "0" << endl;
            }
        }else{
            read_next_token();
            int x = token_number_value;
            read_next_token();
            int y = token_number_value;
            if (x == 0 && y ==0){
                cout << "0" << endl;
            }else{
                cout << "1" << endl;
            }
        }

    }else if (!strcmp(next_token(),"!") || !strcmp(next_token(),"~")){
        //cout << "Unary Operators" << endl;
        eval_unary(ht);
    }else{
        cout << ht.find_num(check.ptr);
        //cout << next_token();
    }


}
//where program starts write sub functions above
void run (void){

    read_next_token();
    math_op p;
    HashTable ht(20);
    while (next_token_type != END){
        if (next_token_type == NAME){
            if (!strcmp(next_token(), "text")){
                // doesnt print text
                read_next_token();
                cout << next_token();
            }else if (!strcmp(next_token(), "output")){
                read_next_token();
                // write function for determining if symbol table
                output_check(ht);
                //cout << token_number_value;
            }else if (!strcmp(next_token(), "set")){
                read_next_token();
                //output_check(ht);

                //cout << "run algo for set" << endl;
            }else if (!strcmp(next_token(), "var")){

                read_next_token();
                //write function for creating variable
                strcat(p.ptr, next_token());
                //cout << x.ptr << " ";
                p.len ++;


                while(strcmp(peek_next_token(), "text")){
                    strcat(p.ptr, " ");
                    p.len++;
                    strcat(p.ptr, next_token());
                    p.len ++;

                    read_next_token();
                }
                char name1 [p.len];
                int y = 0;

                while (p.ptr[y] != ' ' ){
                    name1[y] = p.ptr[y];
                    y++;
                }
                name1[y] = '\0';
                y++;
                int t = y;
                int z = 1;
                int m = 0;
                int num = 0;

                while (p.ptr[t + 1] != ' ' && p.ptr[t + 1] != '\0'){
                    m++;
                    t ++;
                }
                if(m != 0) {
                    while (m != 0) {
                        z *= 10;
                        m--;
                    }
                    while (z != 1) {
                        num += (p.ptr[y] - 48) * z;
                        y++;
                        z /= 10;
                    }
                    num += (p.ptr[y] - 48);
                }else{
                    num = p.ptr[y] - 48;
                }

                ht.insert(name1, num);
                //ht.printMe();

                //var_check();

                //cout << "run algo for var" << endl;
            }


        }else{
            //cout << "it does not" << endl;
        }
        read_next_token();
    }
}


int main(void) {

    //cout << "test case 1" << endl;
    //set_input("C:\\Users\\zanez\\CLionProjects\\Project8\\test1.blip");
    //run();
    //cout << "***End of test case 1***" << endl;


    //cout << endl << endl << "test case 2" << endl;
    //set_input("C:\\Users\\zanez\\CLionProjects\\Project8\\test2.blip");
    //run();
    //cout << "***End of test case 2***" << endl;


    //cout << endl << endl << "test case 3" << endl;
    //set_input("C:\\Users\\zanez\\CLionProjects\\Project8\\test3.blip");
    //run();
    //cout << "***End of test case 3***" << endl;


    //cout << endl << endl << "test case 4" << endl;
    set_input("test_grader.blip");
    run();
    //cout << "***End of test case 4***" << endl;


    //cout << endl << endl << "my test cases" << endl;
    //set_input("C:\\Users\\zanez\\CLionProjects\\Project8\\My_test.txt");
    //run();
    //cout << "***End of my test cases***" << endl;


}

