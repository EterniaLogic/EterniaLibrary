The CharString is a complex implementation of char* to increase the ease of functionality of string functions.

**Usage**
    
    CharString s = "string";
    cout << s << endl;
    
    s += "ending"; // same as s.concata("ending");
    
    if(s.Compare("stringending")){
        cout << "same string!" << endl;
    }
    

**Base String Functions**
| Function | Returns | Description |
|---|---|---|
| set(char*) | void | Sets the underlying character array. |
| get() | char* | Gets the underlying character array. |
| getInt() | int | returns an integer from the string. (Returns 0 if not possible) |
| getLong() | long | returns a long integer from the string. (Returns 0 if not possible) |
| getFloat() | float | returns a float from the string. (Returns 0 if not possible) |
| getScientific(float val) | float | Returns a scientific value, where val is the 10x multiplier. |

**Special String Functions**

| Function | Returns | Description |
|---|---|---|

| shiftLeft(int times) | char* | returns characters that are removed when shifted left. |
| split(char splitter, char stopper) | LinkedList<CharString>  | splits a string into parts based off of the splitter, stops as stopper character. |
| split(charstring splitter) | LinkedList<CharString>  | splits a string into parts based off of the splitter. |
| replace(char* find, char* replaceWith) | void | Replaces 'find' string with 'replaceWith' string in all instances. |
| equals(CharString) | bool | Same as Compare function. |
| compare(CharString) | bool | compares another string to see if it is has the same characters. |
| contains(char*) | bool | searches string to find any instances of input string. |
| Clone() | CharString | Copy String, enables editing of the new string without effecting the original. |
| concata(CharString) | void | 'Concatenate After' Append string at the end of this one. |
| concatb(CharString) | void | 'Concatenate Before' Append string at the beginning of this one. |
| substr(int index, int len) | CharString | grab a string of size LEN beginning at index. |
| removeChar(int index) | void | remove character at index. |
| fixZeroing(char replacement) | void | replaces NULL characters with replacement. |
|  |  |  |
|  |  |  |
|  |  |  |


**Boolean returns**
| Function | Returns | Description |
|---|---|---|
| isValidCharString() | bool | returns true if string is initialized, false if null or 0 length |
| isValidNumber() | bool  | returns true if string is a number (12 or 12.122) |
| isValidScientific() | bool | returns true if string is a scientific number (1.0012E12)  |
| isEmpty() | bool | returns true if length=0 or null |
| startsWith(CharString starter) | bool | string starts with the starter. |
| endsWith(CharString ender) | bool | string ends with the ender. |
|  |  |  |

**Operators**
| Function | Returns | Description |
|---|---|---|
| = | CharString | appends a string (b) with another at the end of return value (b). |
| += | CharString | appends this string with another at the end of return value, changes value. |
| << | friend ostream & | enables a string to be used with the cout operator. |
| >> | friend istream & | enables a string to be used with the cin operator. |

**Global Static Conversion**
| Function | Returns | Description |
|---|---|---|
| ConvertFromInt(int) | CharString | Convert integer into String. |
| ConvertFromLong(long) | CharString | Convert long integer into String. |
| ConvertFromFloat(float) | CharString | Convert float into String. |

