#include "CSV.h"

LinkedList<LinkedList<CharString>> getTableFromCSV(CharString csvFile){
    LinkedList<LinkedList<CharString>> table;
    
    CharString readx;
    LinkedList<CharString> splitc; // line split by commas
    ifstream filex;
    fileOpen(filex, csvFile.get());

    // Read lines from the file
    while((readx = fileGetLine(filex)).getSize() > -1) {
        try{
            
            if(readx.contains(",")){
                splitc = readx.split(',', '|');
                table.add(splitc); // adds row
            }else{
                LinkedList<CharString> row;
                row.add(readx); // single column on this row?
                table.add(row);
            }
        }catch(int e){
            cout << "getTableFromCSV file error caught: " << e << endl; cout.flush();
        }
    }
    
    return table;
}


void toCSVFromTable(CharString csvFile, LinkedList<LinkedList<CharString>> tablerows){
    ofstream filex;
    filex.open(csvFile.get());
    
    LinkedListIterator<LinkedList<CharString>> itr = tablerows.getIterator();
    while(itr.hasNext()){
        bool first = itr.first();
        LinkedList<CharString> row = itr.next();
        LinkedListIterator<CharString> itc = row.getIterator();
        while(itc.hasNext()){
            CharString col = itc.next();
            
            filex.write(col.get(), sizeof(char)*col.getSize());
            
            if(!first)
                filex.write(",",sizeof(char));
        }
        
        if(!itr.last()) // newline CLRF
            filex.write("\r\n",2*sizeof(char));
    }
}
