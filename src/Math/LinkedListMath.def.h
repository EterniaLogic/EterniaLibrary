
// only include in Math functions, do not directly include


#define LLMATHH(FUNC, TYPE) \
LinkedList<TYPE> FUNC(LinkedList<TYPE> x);

// Extra parameter is before x
#define LLMATHH_A(FUNC, TYPE, PARAM) \
LinkedList<TYPE> FUNC(LinkedList<TYPE> x, PARAM);

// Extra parameter is after x
#define LLMATHH_B(FUNC, TYPE, PARAM) \
LinkedList<TYPE> FUNC(LinkedList<TYPE> x, PARAM);



// 

#define LLMATH(FUNC, TYPE) \
LinkedList<TYPE> FUNC(LinkedList<TYPE> x){ \
    LinkedList<TYPE> outlist; \
    \
    for(int i=0;i<x.size();i++){ \
        TYPE v = x[i]; \
        outlist.add(FUNC(v)); \
    } \
    \
    return outlist; \
}


#define LLMATH_A(FUNC, TYPE, PARAM) \
LinkedList<TYPE> FUNC(LinkedList<TYPE> x, PARAM b){ \
   LinkedList<TYPE> outlist; \
    \
    for(int i=0;i<x.size();i++){ \
        TYPE v = x[i]; \
        outlist.add(FUNC(b, v)); \
    } \
    \
    return outlist; \
}

// Extra parameter is after x
#define LLMATH_B(FUNC, TYPE, PARAM) \
LinkedList<TYPE> FUNC(LinkedList<TYPE> x, PARAM b){ \
   LinkedList<TYPE> outlist; \
    \
    for(int i=0;i<x.size();i++){ \
        TYPE v = x[i]; \
        outlist.add(FUNC(v, b)); \
    } \
    \
    return outlist; \
}
