#ifndef ABSTRACTDBDATE_H_
#define ABSTRACTDBDATE_H_

#include <time.h>

#define AbstractDBDate_LEN 64  // 64 bits for timestamp

// Unix timestamp info (may not be used, but is useful here...)
#define EPOCH_MIN 60
#define EPOCH_HR 3600
#define EPOCH_DAY 86400
#define EPOCH_WEEK 604800
#define EPOCH_MONTH 2629743
#define EPOCH_YEAR 31556926


class AbstractDBDate {
public:
        // 2038... cannot wait!
        uint64_t unixtimestamp; // 32-bit timestamp = time(NULL);   seconds since jan1, 1970
        
        int getDayOfYear();
        int getDayOfMonth();
        uint8_t getDayOfWeek(); // 0 = sunday, 6 = saturday
        int getMonth();
        int getYear();
        int getSecond();
        int getWeek(); // Week of month
        int getMinute();
        int getHour();
        
        void setTimestamp();
        unsigned int getTimestamp();
};

#endif
