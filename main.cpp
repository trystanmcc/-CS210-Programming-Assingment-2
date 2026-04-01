#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    // TODO
    string numbers = "";

    for (int i=0; i<line.length(); i++)
    {
        if (isdigit(line[i]))
        {
            numbers += line[i];
        }
        else
        {
            if (!numbers.empty())
            {
                Token a;
                a.value = numbers;
                tokens.push_back(a);
                numbers = "";
            }
            if (line[i] == '(' || line[i] == ')' || line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
            {
                Token b;
                b.value = string(1, line[i]);
                tokens.push_back(b);
            }
        }
    }

    if (!numbers.empty())
    {
        Token c;
        c.value = numbers;
        tokens.push_back(c);
    }

    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    // TODO
    if (op == "+" || op == "-")
        return 2;
    if (op == "+" || op == "-")
        return 1;
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    // TODO
    int count = 0;

    for (int i=0; i<tokens.size(); i++)
    {
        if (tokens[i].value == "(" || tokens[i].value == ")")
            return false;
        if (isOperator(tokens[i].value))
            count--;
        else
            count++;
    }

    if (count == 1)
        return true;

    return false;
}

bool isValidInfix(const vector<Token>& tokens) {
    // TODO
    int change = 0;
    int count = 0;
    bool cont = true;

    for (int i=0; i<tokens.size(); i++)
    {
        if (tokens[i].value == "(")
        {
            count++;
            cont = false;
        }

        if (tokens[i].value == ")")
        {
            count--;
        }

        if (cont == true)
        {
            if (change == 0)
            {
                if (isOperator(tokens[i].value))
                {
                    return false;
                }
                change++;
            } else if (change == 1)
            {
                if (!isOperator(tokens[i].value))
                {
                    return false;
                }
                change--;
            }
        }
        cont = true;
    }

    if (count == 0 && change == 1)
        return true;
    return false;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO
    ArrayStack<Token> stack;

    for (int i=0; i<tokens.size(); i++)
    {
        if (!isOperator(tokens[i].value) && tokens[i].value != "(" && tokens[i].value != ")")
        {
            output.push_back(tokens[i]);
        }
        else if (tokens[i].value == "(")
        {
            stack.push(tokens[i]);
        }
        else if (tokens[i].value == ")")
        {
            while (!stack.empty())
            {
                output.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        }
        else if (isOperator(tokens[i].value))
        {
            while (!stack.empty() && precedence(stack.top().value) >= precedence(tokens[i].value))
            {
                output.push_back(stack.top());
                stack.pop();
            }
            stack.push(tokens[i]);
        }

    }

    while (!stack.empty())
    {
        output.push_back(stack.top());
        stack.pop();
    }

    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    return 0.0;
}

// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}
