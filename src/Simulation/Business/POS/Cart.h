#ifndef POSCART_H_
#define POSCART_H_

// Point of Sale Cart
#include "../../../Data/includes.h"

class Cart{
private:
    LinkedList<Item*> cartItems;
    double discount; // coupon discounts
    CharString cardstring; // string using a credit/debit card magnetic strip / chip.
public:
    Cart();
    
    double getGrossTotal(); // total only counting up items
    double getTaxedTotal(); // total including tax and discounts
    
    void addCoupon(CharString couponcode);
    void addItem(CharString serial_id); // serial can be QR or barcode depending on the company
    
    double getChange(double valuegiven); // gets change based on currency given by customer (actual tabulation is based on cashier?)
    
    void finalizeSale(); // send credit card / debit card information, tabulate items removed from stock database.
    
    LinkedList<Item*> getItems();
};
