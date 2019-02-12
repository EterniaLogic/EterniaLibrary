#ifndef LANGCONTROLLER_H_
#define LANGCONTROLLER_H_

#include "../Data/CharString.h"

// Languages are incredibly unique...
// english, spanish, french, german, chinese, Bulgarian, Russian, Swedish, Italian, Japanese
// Standard language codes for google
enum LANG {
    LANG_ARABIC = 0x00,
    LANG_BULGARIAN = 0x01,
    LANG_CATALAN = 0x02,
    LANG_CHINESE = 0x03,
    LANG_CZECH = 0x04,
    LANG_DANISH = 0x05,
    LANG_GERMAN = 0x06,
    LANG_GREEK = 0x07,
    LANG_ENGLISH = 0x08,
    LANG_SPANISH = 0x09,
    LANG_FINNISH = 0x0a,
    LANG_FRENCH = 0x0b,
    LANG_HEBREW = 0x0c,
    LANG_HUNGARIAN = 0x0d,
    LANG_ICELANDIC = 0x0e,
    LANG_ITALIAN = 0x0f,
    LANG_JAPANESE = 0x10,
    LANG_KOREAN = 0x11,
    LANG_DUTCH = 0x12,
    LANG_NORWEGIAN = 0x13,
    LANG_POLISH = 0x14,
    LANG_PORTUGUESE = 0x15,
    LANG_ROMANIAN = 0x16,
    LANG_RUSSIAN = 0x18,
    LANG_CROATIAN = 0x19,
    LANG_SERBIAN = 0x1a,
    LANG_SLOVAK = 0x1a,
    LANG_ALBANIAN = 0x1b,
    LANG_SWEDISH = 0x1c,
    LANG_THAI = 0x1d,
    LANG_TURKISH = 0x1e,
    LANG_URDU = 0x1f,
    LANG_INDONESIAN = 0x20,
    LANG_UKRANIAN = 0x21,
    LANG_BELARUSIAN = 0x22,
    LANG_SLOVENIAN = 0x23,
    LANG_ESTONIAN = 0x24,
    LANG_LATVIAN = 0x25,
    LANG_LITHUANIAN = 0x26,
    LANG_FARSI = 0x27,
    LANG_VIETNAMESE = 0x29,
    LANG_ARMENIAN = 0x2a,
    LANG_AZERI = 0x2b,
    LANG_BASQUE = 0x2c,
    LANG_MACEDONIAN = 0x2d,
    LANG_AFRIKAANS = 0x2f,
    LANG_GEORGIAN = 0x36,
    LANG_FAEROESE = 0x37,
    LANG_HINDI = 0x38,
    LANG_MALAY = 0x39,
    LANG_KAZAK = 0x3e,
    LANG_SWAHILI = 0x3f,
    LANG_UZBEK = 0x41,
    LANG_TATAR = 0x43,
    LANG_BENGALI = 0x44,
    LANG_PUNJABI = 0x45,
    LANG_GUJARATI = 0x46,
    LANG_ORIYA = 0x47,
    LANG_TAMIL = 0x48,
    LANG_TELUGU = 0x49,
    LANG_KANNADA = 0x4a,
    LANG_MALAYALAM = 0x4b,
    LANG_ASSAMESE = 0x4c,
    LANG_MARATHI = 0x4d,
    LANG_SANSKRIT = 0x4e,
    LANG_KONKANI = 0x4f,
    LANG_MANIPURI = 0x57,
    LANG_SINDHI = 0x58,
    LANG_KASHMIRI = 0x59,
    LANG_NEPALI = 0x60,
};

class LanguageController {
    public:
        LanguageController();
        void addTranslation(LANG langid, CharString* english, CharString* language); // single-word translation

        CharString* translateWord(CharString* word);
        CharString* translateString(CharString* sentence); // Determine
};

const LanguageController languages[0xff];

#endif /*LANGCONTROLLER_H_*/
