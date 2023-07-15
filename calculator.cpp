//Auther: Shuaijie Chen
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

//Use define PI and e as strings to improve code readability
#define PI acos(-1.0)
#define e exp(1.0)

using namespace std;

bool contains_decimal(string& str) {//Check whether the string contains a decimal point and, if so, consider it a decimal
    return str.find('.') != std::string::npos;
}


string factorial(string a){
    double a_double = stod(a);
    if (contains_decimal(a) || a_double<0) {//not valid when the number is float
        throw "invalid";
    }
    else if(a_double==0){ // define 0!=1
        return "1";
    }
    else {
        double result = 1;
        for(int i = 1; i <= a_double; i++) {
            result *= i;
        }
        if(result==(int)result){
            return to_string((int)result);
        }else{
            return to_string(result);
        }
    }
}

string calculate_atrig(string num, char op){
    double num_double = stod(num);
    if(op=='s'){
        if(isnan(asin(num_double))){
            throw "invalid";
        }else{
            return to_string(asin(num_double));
        }
    }else if(op=='c'){
        if(isnan(acos(num_double))){
            throw "invalid";
        }else{
            return to_string(acos(num_double));
        }
    }else if(op=='t'){
        if(isnan(atan(num_double))){
            throw "invalid";
        }else{
            return to_string(atan(num_double));
        }
    }else{
        return 0;
    }
}

string calculate_trig(string num, char op) {//Calculate trigonometric functions
    double num_double = stod(num);
    if(op=='s'){
        if(isnan(sin(num_double))){
            throw "invalid";
        }
        else{
            return to_string(sin(num_double));
        }
    }else if(op=='c'){
        if(isnan(cos(num_double))){
            throw "invalid";
        }else{
            return to_string(cos(num_double));
        }
    }else if(op=='t'){
        if(isnan(tan(num_double))||(num_double-PI/2)-(int)((num_double-PI/2)/PI)<1e-9){
            if(num_double-0<1e-9){
                return ("0.0");
            }else{
                throw "invalid";
            }
        }else{
            return to_string(tan(num_double));
        }
    }else{
        return 0;
    }
}

bool is_atrig_function(string str){
    return str == "asin" || str == "acos" || str == "atan";
}
bool is_trig_function(string str) {
    return str == "sin" || str == "cos" || str == "tan" || str == "asin" || str == "acos" || str == "atan";
}

int priority(char op) {//Specify the order of calculations
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/' || op == '%') {
        return 2;
    } else if (op == '^') {
        return 3;
    } else {
        return 0;
    }
}

class calculator{
    private: 
        //operands
        string num1; 
        string num2;
        //operators
        char op;

    public:
        calculator(string num1, string num2, char op){
            this->num1 = num1;
            this->num2 = num2;
            this->op = op;
        }
        char getOP(){
            return op;
        }
        string operator+() {//Overload + makes it add num1 and num2 in the calculator
            bool is_num1_float = (num1.find('.') != std::string::npos);
            bool is_num2_float = (num2.find('.') != std::string::npos);

            if (is_num1_float || is_num2_float) {
                double result;
                double num1_double = stod(num1);
                double num2_double = stod(num2);
                result = num1_double + num2_double;
                return to_string(result);
            }
            else {
                int result;
                int num1_int = stoi(num1);
                int num2_int = stoi(num2);
                result = num1_int + num2_int;
                return to_string(result);
            }
        }

        string operator-() {//Overload - makes it subtract num1 and num2 in the calculator
            bool is_num1_float = (num1.find('.') != std::string::npos);
            bool is_num2_float = (num2.find('.') != std::string::npos);

            if (is_num1_float || is_num2_float) {
                double result;
                double num1_double = stod(num1);
                double num2_double = stod(num2);
                result = num1_double - num2_double;
                return to_string(result);
            }
            else {
                int result;
                int num1_int = stoi(num1);
                int num2_int = stoi(num2);
                result = num1_int - num2_int;
                return to_string(result);
            }
        }

        string operator*() {//Overload * makes it multiply num1 and num2 in the calculator
            bool is_num1_float = (num1.find('.') != std::string::npos);
            bool is_num2_float = (num2.find('.') != std::string::npos);

            if (is_num1_float || is_num2_float) {
                double result;
                double num1_double = stod(num1);
                double num2_double = stod(num2);
                result = num1_double * num2_double;
                return to_string(result);
            }
            else {
                int result;
                int num1_int = stoi(num1);
                int num2_int = stoi(num2);
                result = num1_int * num2_int;
                return to_string(result);
            }
        }

        string operator/(calculator &c) {//Overload / makes it divide num1 and num2 in the calculator
            bool is_num1_float = (num1.find('.') != std::string::npos);
            bool is_num2_float = (num2.find('.') != std::string::npos);
            double num2_d = stod(num2);
            if(num2_d==0){
                throw "invalid";
            }

            if (is_num1_float || is_num2_float) {
                double result;
                double num1_double = stod(num1);
                double num2_double = stod(num2);
                result = num1_double / num2_double;
                return to_string(result);
            }
            else {
                double result;
                int num1_int = stoi(num1);
                int num2_int = stoi(num2);
                result = num1_int / num2_int;
                if(result==(int)result){
                    return to_string((int)result);
                }else{
                    return to_string(result);
                }
            }
        }

        string operator%(calculator &c) {//Overload % Take the balance of num1 and num2 in the calculator
            bool is_num1_float = (num1.find('.') != std::string::npos);
            bool is_num2_float = (num2.find('.') != std::string::npos);

            if (is_num1_float || is_num2_float) {
                throw "invalid";
            }
            else {
                double result;
                int num1_int = stoi(num1);
                int num2_int = stoi(num2);
                if(num2_int == 0){
                    throw "invalid";
                }
                else{
                    result = num1_int % num2_int;
                    if(result==(int)result){
                        return to_string((int)result);
                    }else{
                        return to_string(result);
                    }
                }
            }
        }

        string operator^(calculator &c) {//Overload ^ makes it exponent of num1 and num2 in the calculator
            bool is_num1_float = (num1.find('.') != std::string::npos);
            bool is_num2_float = (num2.find('.') != std::string::npos);

            if (is_num1_float || is_num2_float) {
                double result;
                double num1_double = stod(num1);
                double num2_double = stod(num2);
                result = pow(num1_double, num2_double);
                return to_string(result);
            }
            else {
                int result;
                int num1_int = stoi(num1);
                int num2_int = stoi(num2);
                result = pow(num1_int,num2_int);
                return to_string(result);
            }
        }
};

string calculate(calculator calc) {//Use the operator to determine what calculation should be made
    if (calc.getOP() == '+') {
        return +calc;
    } else if (calc.getOP() == '-') {
        return -calc;
    } else if (calc.getOP() == '*') {
        return *calc;
    } else if (calc.getOP() == '/') {
        return calc/calc;
    } else if (calc.getOP() == '^') {
        return calc^calc;
    } else if (calc.getOP() == '%'){
        return calc%calc;
    } else {
        return 0;
    }
}



string evaluate(string expression) {//Read the equation entered by the user
    stack<string> operands;//store numbers read from user
    stack<char> operators;//store operators read from user

    for (unsigned int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            continue;
        } else if (expression[i] == '(') {
            operators.push(expression[i]);
        } 
        // else if (isdigit(expression[i]) || expression[i] == '.') {
        //     string num_str;
        //     while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
        //         num_str += expression[i];
        //         i++;
        //     }
        //     i--;
        //     operands.push(num_str);
        // } 
        else if (isdigit(expression[i]) || expression[i] == '.') {
            string num_str;
            int dot_count = 0; // Record the number of times the decimal point occurs
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    dot_count++;
                    if (dot_count > 1 || i == expression.length() - 1 || !isdigit(expression[i+1]) || !isdigit(expression[i-1])) {
                        // If the decimal point appears more than once, or appears at the end of the decimal point, or is not a number before or after the decimal point, the input is invalid
                        throw "invalid";
                    }
                }
                num_str += expression[i];
                i++;
            }
            i--;
            operands.push(num_str);
        }
        else if (expression[i] == '-' && (i == 0 || (!isdigit(expression[i-1]) && expression[i-1] != '.'))) {//For negative numbers, such as -1, treat it as 0-1
            operands.push("0");
            operators.push('-');
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^' || expression[i] == '%') {
            while (!operators.empty() && operators.top() != '(' && priority(operators.top()) >= priority(expression[i])) {//Calculations are made based on the arithmetic priority
                if(operands.empty()){//Each time data is read from the top of the stack, first determine whether the stack is empty, if it is empty, the judgment program has an exception
                    throw "invalid";
                }
                string num2 = operands.top();
                operands.pop();
                if(operands.empty()){
                    throw "invalid";
                }
                string num1 = operands.top();
                operands.pop();
                if(operators.empty()){
                    throw "invalid";
                }
                char op = operators.top();
                operators.pop();
                operands.push(calculate(calculator(num1,num2,op)));
            }
            operators.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                if(operands.empty()){
                    throw "invalid";
                }
                string num2 = operands.top();
                operands.pop();
                if(operands.empty()){
                    throw "invalid";
                }
                string num1 = operands.top();
                operands.pop();
                if(operators.empty()){
                    throw "invalid";
                }
                char op = operators.top();
                operators.pop();
                operands.push(calculate(calculator(num1,num2,op)));
            }
        operators.pop();
        } else if (expression[i] == '!') {//factorial
            if(operands.empty()){
                throw "invalid";
            }
            string num = operands.top();
            operands.pop();
            operands.push(factorial(num));
        } else if (expression[i] == 'a' && i + 2 < expression.length() && expression.substr(i, 3) == "abs") {//abs
            i += 2;
            string num;
            if (expression[i + 1] == '(') {
                // read the argument of abs
                unsigned int j = i + 2;
                int num_parentheses = 1;
                while (j < expression.length() && num_parentheses > 0) {
                    if (expression[j] == '(') {
                        num_parentheses++;
                    } else if (expression[j] == ')') {
                        num_parentheses--;
                    }
                    j++;
                }
                string num_str = expression.substr(i + 2, j - i - 3);
                num = evaluate(num_str);
                i = j - 1;
            } else {
                // read the argument of abs
                unsigned int j = i + 1;
                while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.')) {
                j++;
                }
                string num_str = expression.substr(i + 1, j - i - 1);
                num = stod(num_str);
                i = j - 1;
            }
            double num_double = stod(num);
            operands.push(to_string(abs(num_double)));
        } else if (is_trig_function(expression.substr(i, 3))) {//trigonometric function
            string func = expression.substr(i, 3);
            i += 2;
            string num;
            if (expression[i + 1] == '(') {
                // read the argument of the trig function
                unsigned int j = i + 2;
                int num_parentheses = 1;
                while (j < expression.length() && num_parentheses > 0) {
                    if (expression[j] == '(') {
                        num_parentheses++;
                    } else if (expression[j] == ')') {
                        num_parentheses--;
                    }
                    j++;
                }
                string num_str = expression.substr(i + 2, j - i - 3);
                num = evaluate(num_str);
                i = j - 1;
            } else {
                // read the argument of the trig function
                unsigned int j = i + 1;
                while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.' || expression[j] == '-')) {
                    j++;
                }
                string num_str = expression.substr(i + 1, j - i - 1);
                num = stod(num_str);
                i = j - 1;
            }
            operands.push(calculate_trig(num, func[0]));
        }else if (is_atrig_function(expression.substr(i,4))) { // asin
            string func = expression.substr(i,4);
            i += 3;
            string num;
            if (expression[i + 1] == '(') {
                // read the argument of asin
                unsigned int j = i + 2;
                int num_parentheses = 1;
                while (j < expression.length() && num_parentheses > 0) {
                    if (expression[j] == '(') {
                        num_parentheses++;
                    } else if (expression[j] == ')') {
                        num_parentheses--;
                    }
                    j++;
                }
                string num_str = expression.substr(i + 2, j - i - 3);
                num = evaluate(num_str);
                i = j - 1;
            } else {
                // read the argument of asin
                unsigned int j = i + 1;
                while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.')) {
                    j++;
                }
                string num_str = expression.substr(i + 1, j - i - 1);
                num = stod(num_str);
                i = j - 1;
            }
            operands.push(calculate_atrig(num, func[1]));
        }                        
            else if (expression[i] == 'e' && i + 2 < expression.length() && expression.substr(i, 3) == "exp") {//exp
            i += 2;
            string num;
            if (expression[i + 1] == '(') {
                // read the argument of exp
                unsigned int j = i + 2;
                int num_parentheses = 1;
                while (j < expression.length() && num_parentheses > 0) {
                    if (expression[j] == '(') {
                        num_parentheses++;
                    } else if (expression[j] == ')') {
                        num_parentheses--;
                    }
                    j++;
                }
                string num_str = expression.substr(i + 2, j - i - 3);
                num = evaluate(num_str);
                i = j - 1;
            } else {
                // read the argument of exp
                unsigned int j = i + 1;
                while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.')) {
                j++;
                }
                string num_str = expression.substr(i + 1, j - i - 1);
                num = stod(num_str);
                i = j - 1;
            }
            double num_double = stod(num);
            operands.push(to_string(exp(num_double)));
        }else if (expression[i] == 'l' && i + 2 < expression.length() && expression.substr(i, 3) == "log") {//log10
            i += 2;
            string num;
            if (expression[i + 1] == '(') {
                // read the argument of log
                unsigned int j = i + 2;
                int num_parentheses = 1;
                while (j < expression.length() && num_parentheses > 0) {
                    if (expression[j] == '(') {
                        num_parentheses++;
                    } else if (expression[j] == ')') {
                        num_parentheses--;
                    }
                    j++;
                }
                string num_str = expression.substr(i + 2, j - i - 3);
                num = evaluate(num_str);
                i = j - 1;
            } else {
                // read the argument of log
                unsigned int j = i + 1;
                while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.')) {
                j++;
                }
                string num_str = expression.substr(i + 1, j - i - 1);
                num = stod(num_str);
                i = j - 1;
            }
            double num_double = stod(num);
            operands.push(to_string(log10(num_double)));
        }else if (expression[i] == 'l' && i + 1 < expression.length() && expression[i + 1] == 'n') {//loge
            i += 1;
            string num;
            if (expression[i + 1] == '(') {
                // read the argument of ln
                unsigned int j = i + 2;
                int num_parentheses = 1;
                while (j < expression.length() && num_parentheses > 0) {
                    if (expression[j] == '(') {
                        num_parentheses++;
                    } else if (expression[j] == ')') {
                        num_parentheses--;
                    }
                    j++;
                }
                string num_str = expression.substr(i + 2, j - i - 3);
                num = evaluate(num_str);
                i = j - 1;
            } else {
                // read the argument of ln
                unsigned int j = i + 1;
                while (j < expression.length() && (isdigit(expression[j]) || expression[j] == '.')) {
                    j++;
                }
                string num_str = expression.substr(i + 1, j - i - 1);
                num = stod(num_str);
                i = j - 1;
            }
            double num_double = stod(num);
            operands.push(to_string(log(num_double)));
        } 
        else if (expression[i] == 'P') {//PI
            i += 1;
            
            operands.push(to_string(PI));
        } else if (expression[i] == 'e') {//e
            operands.push(to_string(e));
        }else{
            throw "invalid";
        }
    }
    while (!operators.empty()) {//Before the stack where the operators are stored is not empty, take out the numbers at the top of the stack of operators and operands and calculate them
        if(operands.empty()){
            throw "invalid";
        }
        string num2 = operands.top();
        operands.pop();
        if(operands.empty()){
            throw "invalid";
        }
        string num1 = operands.top();
        operands.pop();
        if(operators.empty()){
            throw "invalid";
        }
        char op = operators.top();
        operators.pop();
        operands.push(calculate(calculator(num1,num2,op)));
    }

    return operands.top();
}

bool isValidExpression(string expression) {
    // Check that the parentheses match
    stack<char> parentheses;
    for (char c : expression) {
        if (c == '(') {
            parentheses.push(c);
        } else if (c == ')') {
            if (parentheses.empty() || parentheses.top() != '(') {
                return false;
            }
            parentheses.pop();
        }
    }
    if (!parentheses.empty()) {
        return false;
    }

    return true;
}

int main() {
    string expression;
    getline(cin, expression);
    if(isValidExpression(expression)){//check if the expression is valid
        try{
            string result = evaluate(expression);
            cout << result;
            // double result_double = stod(result);
            //cout << fixed << setprecision(6) << result_double;
        }catch (const char* msg) {
            cout << msg << endl;
        }
    } else{
        cout << "invalid";
    }
    return 0;
}