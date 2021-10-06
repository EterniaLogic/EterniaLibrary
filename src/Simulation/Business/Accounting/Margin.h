#ifndef MARGIN_H_
#define MARGIN_H_


// Margin is used when determining how much leverage a company has between debts vs assets

class Margin{
private:
    LinkedList<Liability> _debts;
    LinkedList<Asset> _equities;
public:
    Margin();
    Margin(LinkedList<Liability> debts, LinkedList<Asset> equities);
    
    void addAssets(LinkedList<Asset> equities);
    void addDebts(LinkedList<Liability> debts);
    
    double getTotalInterestRate(); // 
};


#endif
