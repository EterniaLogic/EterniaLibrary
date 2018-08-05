

#include "Eval.h"

using namespace std;

// initialize stacks! :D
Stack* NumStack = new Stack();
Stack* OpStack = new Stack();

// returns a MOperator from a certain character type
MOperator getOperatorFromChar(char character) {
    MOperator ret = none;
    if(character == '+') ret = addition;
    else if(character == '-') ret = subtraction;
    else if(character == '*') ret = multiplication;
    else if(character == '/') ret = division;
    else if(character == '^') ret = exponent;
    else if(character == '>') ret = Greater;
    else if(character == '<') ret = Less;
    else if(character == '=') ret = equals;
    else if(character == '%') ret = Modulus;
    //cout << character << " is " << ret << endl;
    return ret;
}

// Used to combine operators such as >=, <=, ect.
MOperator combineOperators(MOperator o1, MOperator o2) {
    MOperator ret = none;
    if(o1 == Greater && o2 == equals) ret = greaterequals;
    else if(o1 == Less && o2 == equals) ret = lessequals;
    return ret;
}

// Determines if the character is a number
bool isCharNumber(char in) {
    int g = (int)in;
    if(g <= 57 && g >= 48) return true;

    return false;
}

// do the operation! :D
int doOp() {
    int item, item2;
    item2 = NumStack->pop();
    item = NumStack->pop();
    MOperator op = ((MOperator)OpStack->pop());
    // pop first 2 numbers and first operator

    // massive list, process input:
    if(op == addition) return item+item2;
    else if(op == subtraction) return item-item2;
    else if(op == multiplication) return item*item2;
    else if(op == division) return item/item2;
    else if(op == Modulus) return item%item2;
    else if(op == exponent) {
        int t = 1;
        for(int i=0; i<item2; i++) {
            t*= item;
        }
        return t;
    } else if(op == Less) return (item < item2) ? -99 : -98;
    else if(op == Greater) return (item > item2) ? -99 : -98;
    else if(op == equals) return (item == item2) ? -99 : -98;
    else if(op == greaterequals) return (item >= item2) ? -99 : -98;
    else if(op == lessequals) return (item <= item2) ? -99 : -98;

    return 0;
}

// Return the order of precedence for each.
int prec(MOperator op) {
    if(op == addition) return 20;
    else if(op == subtraction) return 20;
    else if(op == multiplication) return 40;
    else if(op == division) return 40;
    else if(op == Modulus) return 40;
    else if(op == exponent) return 999;
    else if(op == Less) return 0;
    else if(op == Greater) return 0;
    else if(op == equals) return 0;
    else if(op == greaterequals) return 0;
    else if(op == lessequals) return 0;

    return 0; // has zero procedence (Used at the end)
}

// repeat operators if the current operator is less in precedence then the top of the stack.
void repeatOps(MOperator op) {
    /*while ( valStk.size() > 1 || prec(refOp) <= prec(opStk.top())){
        doOp()
    }*/

    while(NumStack->size > 1 && (prec(op) <= prec((MOperator)OpStack->poll()) ) ) {
        int res = doOp();
        NumStack->push(res);
    }
}

// assigns Number from Temp String. Posts number to NumStack.
void dumpNum(char* numString, int strlen) {
    if(strlen > 0) {
        CharString* NTemp = new CharString(numString,strlen);
        numString[strlen] = 0x0;
        NumStack->push(NTemp->getInt());

        delete NTemp;
    }
}

// Posts Operator to NumStack after determining it's precedence.
void dumpOp(MOperator op) {
    if(op != none) {
        repeatOps(op);
        OpStack->push(op);
    }
}

/*
 * Desc: Takes in a single line and expresses the line in a math formula to solve it.
 * Input: CharString* Line.
 * Output: (Console) Output of all expressions.
 * */
CharString Eval(CharString Line) {
    //cout << line << endl;
    // get length of line
    int lsize = 0;
    for(int i=0; i<Line.getSize(); i++) {
        if(Line.get()[i] != 0x0) {
            lsize++;
        }
    }
    Line.setSize(lsize);


    // PARSE each section. Format SHOULD be like this:
    // 1 + 2 [number operator number]
    // 1 + 2 * 3 [n o n o n]
    // 1 + 5 * 10^2 [n o n o non]
    // 110/ 98 [no n] (Automatic parse finding)

    // list of operators:
    // () + - / * ^ % < > = <= >= [NOTE that as of this time, parentheses will not be used]

    // Thus, it can be infered that we can break up each system by placing the most important
    //  System (order of operations) on the top of the stack and placing the least important
    // +/- at the bottom of the stack...

    // Order of operations:
    //  ^  /  *  +  -  (>= = <= < > [END-CLASS operators])

    // Parse method:
    //  1.) loop-through n times to get full stack.

    NumStack = new Stack(); // NumStack is used to store the initial numbers
    OpStack = new Stack(); // OpStack is used to store the initial operators

    // note that both stacks store information through the same MathOperationNode Type.
    //  This will be solved later when we interlace the operators with the variables.
    char* LineD = Line.get();
    char* NumTemp = new char();
    int NumTempLen = 0;
    MOperator OpTemp = none;
    for(int i=0; i<Line.getSize(); i++) {
        char g = LineD[i];
        MOperator tOp = getOperatorFromChar(g);

        if(isCharNumber(g)) { // is this a number?
            // this is a single digit for NumTemp. Add to it.
            NumTemp[NumTempLen] = g;
            NumTempLen++;

            // dump OpTemp if it is available.
            dumpOp(OpTemp);
            OpTemp = none;
        } else if (tOp != none) {
            if(OpTemp != none) {
                MOperator gox = combineOperators(tOp,OpTemp);
                if(gox != none) OpTemp = gox;
            } else {
                OpTemp = tOp;
            }

            // dump NumTemp if it is available.
            dumpNum(NumTemp,NumTempLen);
            NumTempLen=0;
        } else {
            // dump NumTemp if it is available.
            // dump OpTemp if it is available.
            dumpNum(NumTemp,NumTempLen);
            NumTempLen=0;
            dumpOp(OpTemp);
            OpTemp = none;
        }
    }

    // dump NumTemp if it is available.
    // dump OpTemp if it is available.
    dumpNum(NumTemp,NumTempLen);
    NumTempLen=0;
    dumpOp(OpTemp);
    OpTemp = none;

    while(OpStack->size > 0) {
        int res = doOp();
        //cout << "=" << res << endl;
        NumStack->push(res);
    }
    int c = NumStack->pop();
    if(c == -98) cout << "F";
    else if(c == -99) cout << "T";
    else cout << c;

    return CharString::ConvertFromInt(c);
}
