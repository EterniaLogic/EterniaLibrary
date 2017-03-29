//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#ifndef CRYPTO_DEFINER_CLASS_H_
#define CRYPTO_DEFINER_CLASS_H_

#include "Aes256.h"

enum PTypes {PCHAR_, PINT_, PFLOAT_, PLONG_, PBOOL_};

// CryptoDefiner is used to prevent actual values from being detected
//      in raw memory. Extra functions are used to maximize flexibility.

template<class T>
class CryptoDefiner {
        char* key; // randomly generated key
        T falseValue; // false value that can be changed, but will do nothing
        PTypes tpe;
        aes256_context cont;

        unsigned char memRegion[128]; // encrypted region of memory
    public:
        CryptoDefiner(PTypes t) {
            tpe = t;

            //aes256_init(&cont, key);
            //aes256_done(&ctx);
        }

        bool operator !() {
            return !get();
        }
        T operator ~() {
            return ~get();
        }

        // basic operators
        T operator =(CryptoDefiner<T> val) {
            set(val);
        }

        T operator ++() {
            set(get()+1);
        }
        T operator +(CryptoDefiner<T> val) {
            return get() + val->get();
        }
        T operator -(CryptoDefiner<T> val) {
            return get() - val->get();
        }
        T operator *(CryptoDefiner<T> val) {
            return get() * val->get();
        }
        T operator /(CryptoDefiner<T> val) {
            return get() / val->get();
        }
        T operator ^(CryptoDefiner<T> val) {
            return get() ^ val->get();
        }
        T operator &(CryptoDefiner<T> val) {
            return get() & val->get();
        }
        T operator |(CryptoDefiner<T> val) {
            return get() | val->get();
        }


        // compare operators
        bool operator <(CryptoDefiner<T> val) {
            return get() < val->get();
        }
        bool operator >(CryptoDefiner<T> val) {
            return get() > val->get();
        }

        // assigning values
        T operator +=(CryptoDefiner<T> val) {
            return set(get() + val->get());
        }
        T operator -=(CryptoDefiner<T> val) {
            return set(get() - val->get());
        }
        T operator *=(CryptoDefiner<T> val) {
            return set(get() * val->get());
        }
        T operator /=(CryptoDefiner<T> val) {
            return set(get() / val->get());
        }
        T operator ^=(CryptoDefiner<T> val) {
            return set(get() ^ val->get());
        }
        T operator &=(CryptoDefiner<T> val) {
            return set(get() & val->get());
        }
        T operator |=(CryptoDefiner<T> val) {
            return set(get() | val->get());
        }

        // bool operators
        bool operator ==(CryptoDefiner<T> val) {
            return get() == val->get();
        }
        bool operator <=(CryptoDefiner<T> val) {
            return get() <= val->get();
        }
        bool operator >=(CryptoDefiner<T> val) {
            return get() >= val->get();
        }
        bool operator !=(CryptoDefiner<T> val) {
            return get() != val->get();
        }


        ///////// T Value types
        // basic operators
        T operator =(T val) {
            set(val);
        }
        T operator +(T val) {
            return get() + val;
        }
        T operator -(T val) {
            return get() - val;
        }
        T operator *(T val) {
            return get() * val;
        }
        T operator /(T val) {
            return get() / val;
        }
        T operator ^(T val) {
            return get() ^ val;
        }
        T operator &(T val) {
            return get() & val;
        }
        T operator |(T val) {
            return get() | val;
        }


        // compare operators
        bool operator <(T val) {
            return get() < val;
        }
        bool operator >(T val) {
            return get() > val;
        }

        // assigning values
        T operator +=(T val) {
            return set(get() + val);
        }
        T operator -=(T val) {
            return set(get() - val);
        }
        T operator *=(T val) {
            return set(get() * val);
        }
        T operator /=(T val) {
            return set(get() / val);
        }
        T operator ^=(T val) {
            return set(get() ^ val);
        }
        T operator &=(T val) {
            return set(get() & val);
        }
        T operator |=(T val) {
            return set(get() | val);
        }

        // bool operators
        bool operator ==(T val) {
            return get() == val;
        }
        bool operator <=(T val) {
            return get() <= val;
        }
        bool operator >=(T val) {
            return get() >= val;
        }
        bool operator !=(T val) {
            return get() != val;
        }

        T get() {
            //aes256_decrypt_ecb(&cont, &memRegion);
        }

        T set(T val) {
            falseValue = val;

            /*unsigned char* tt = new char[128];
            tt = (T*) (&val);

            aes256_encrypt_ecb(&cont, tt);
            delete tt;*/

            return falseValue;
        }
};

#endif
