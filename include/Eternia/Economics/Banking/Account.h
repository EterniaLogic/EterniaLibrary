#ifndef Account_h_
#define Account_h_

// The key used to access the account is a special hash that cannot be reversed without calculating the hashes for 1 million years. (Each hashing method is special per account)

class Account
{
public:
  Account(double ID, double Value, double key);
   
  double getID(); // return the account id
  double getValue();
  double getKey();
  double createKey(char* passcode); // create a key based on a passcode
  
private:
  double id; // account id
  double value; // account value
  double key; // number-key for accessing account
};

#endif