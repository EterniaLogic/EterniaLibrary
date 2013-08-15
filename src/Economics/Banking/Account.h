#ifndef Account_h_
#define Account_h_

// The key used to access the account is a special hash that cannot be reversed without calculating the hashes for 1 million years. (Each hashing method is special per account)

class Account
{
public:
  Account(float ID, float Value, float key);
   
  float getID(); // return the account id
  float getValue();
  float getKey();
  float createKey(char* passcode); // create a key based on a passcode
  
private:
  float id; // account id
  float value; // account value
  float key; // number-key for accessing account
};

#endif