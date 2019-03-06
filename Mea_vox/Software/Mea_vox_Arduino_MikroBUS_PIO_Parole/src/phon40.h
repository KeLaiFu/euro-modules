/*
- table 4.2 from "BENOIT Herv‚ et WEISSGERBER Michel: Parole et micros. Synthèse vocale. TO7.... Cedic/Nathan 1985."
- fixed frame duration 16 ms
- constant pitch 120 Hz
- Address on LSB byte relevant
- no need for fake silent ending
- corrected 12-mai-2018 with book not microsystem
*/

const char* tPhon[]  = {"a","e","i","O","u","è","é","eu","ou","an","in","on","oi","b","d","f","g"
                     ,"j","k","l","m","n","p","R","r","S","t","v","z","ch","gn","ail","eil","euil","ien","oin","o","s",
                     "s32","s64"," ","PI up","PI dwn","PI =","FD up","FD dwn","whisper"};

const uint8_t phon[] PROGMEM =  {
  0x00, 0x54, 0x00, 0x78, 0x00, 0x9C, 0x00, 0xC0, 0x00, 0xE4, 0x01, 0x08, 0x01, 0x2C, 0x01, 0xF8,
 0x02, 0x1C, 0x01, 0x50, 0x01, 0x74, 0x01, 0x98, 0x01, 0xBC, 0x02, 0x40, 0x02, 0x5C, 0x02, 0x78,
 0x02, 0x9C, 0x02, 0xB0, 0x02, 0xC8, 0x02, 0xDC, 0x02, 0xF4, 0x03, 0x18, 0x03, 0x2C, 0x03, 0x44,
 0x03, 0x58, 0x03, 0x70, 0x03, 0x90, 0x03, 0xA4, 0x03, 0xC4, 0x03, 0xD8, 0x03, 0xF8, 0x04, 0x30,
 0x04, 0x70, 0x04, 0xB0, 0x04, 0xF0, 0x05, 0x30, 0x05, 0x5C, 0x05, 0xA0, 0x05, 0x80, 0x05, 0x8C,
 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x24, 0x3C, 0x3C, 0x86, 0xB3, 0xCD, 0xA0, 0x86, 0xB3, 0xCD, 0xA0,
 0x86, 0xB2, 0xD6, 0xA0, 0x86, 0xB2, 0xD6, 0xA0, 0x96, 0xB2, 0xCE, 0xA0, 0x96, 0xB2, 0xCE, 0xA0,
 0x97, 0xB1, 0xCD, 0xA0, 0x97, 0xB1, 0xCD, 0xA0, 0x00, 0x24, 0x3C, 0x3C, 0xAF, 0xB3, 0x85, 0x20,
 0xAF, 0xB3, 0x85, 0x20, 0xAB, 0xB3, 0x7E, 0x20, 0xAB, 0xB3, 0x7E, 0x20, 0xAB, 0xB3, 0x86, 0x20,
 0xAB, 0xB3, 0x86, 0x20, 0xFF, 0xB3, 0x85, 0x20, 0xFF, 0xB3, 0x85, 0x20, 0x00, 0x24, 0x3C, 0x3C,
 0xAF, 0xDA, 0x5D, 0x20, 0xAF, 0xDA, 0x5D, 0x20, 0xAF, 0xDA, 0x5E, 0x20, 0xAF, 0xDA, 0x5E, 0x20,
 0xAF, 0xDA, 0x66, 0x20, 0xAF, 0xDA, 0x66, 0x20, 0xAF, 0xDA, 0x65, 0x20, 0xAF, 0xDA, 0x65, 0x20,
 0x00, 0x24, 0x3C, 0x3C, 0xC7, 0xAC, 0x84, 0xA0, 0xC7, 0xAC, 0x84, 0xA0, 0xC6, 0xAB, 0x85, 0x20,
 0xC6, 0xAB, 0x85, 0x20, 0xC6, 0xAB, 0x85, 0x20, 0xC6, 0xAB, 0x85, 0x20, 0xD6, 0xAB, 0x84, 0xA0,
 0xD6, 0xAB, 0x84, 0xA0, 0x00, 0x24, 0x3C, 0x3C, 0xB7, 0xB7, 0x5D, 0x20, 0xB7, 0xB7, 0x5D, 0x20,
 0xB7, 0xB7, 0x66, 0xA0, 0xB7, 0xB7, 0x66, 0xA0, 0xB7, 0xB7, 0x66, 0xA0, 0xB7, 0xB7, 0x66, 0xA0,
 0xB7, 0xB7, 0x5D, 0x20, 0xB7, 0xB7, 0x5D, 0x20, 0x00, 0x24, 0x3C, 0x3C, 0xA6, 0xB6, 0xB5, 0x20,
 0xA6, 0xB6, 0xB5, 0x20, 0xB6, 0xB6, 0xBF, 0x20, 0xB6, 0xB6, 0xBF, 0x20, 0xB6, 0xB6, 0xB7, 0x20,
 0xB6, 0xB6, 0xB7, 0x20, 0xFA, 0xB7, 0xA5, 0x20, 0xFA, 0xB7, 0xA5, 0x20, 0x00, 0x24, 0x3C, 0x3C,
 0xBB, 0xB8, 0x85, 0xA0, 0xBB, 0xB8, 0x85, 0xA0, 0xBB, 0xB8, 0x87, 0x20, 0xBB, 0xB8, 0x87, 0x20,
 0xBB, 0xB8, 0x87, 0x20, 0xBB, 0xB8, 0x87, 0x20, 0xFB, 0xB8, 0x85, 0xA0, 0xFB, 0xB8, 0x85, 0xA0,
 0x00, 0x24, 0x3C, 0x3C, 0x52, 0xCA, 0xBD, 0x20, 0x52, 0xCA, 0xBD, 0x20, 0x97, 0xCA, 0xBD, 0xA0,
 0x97, 0xCA, 0xBD, 0xA0, 0x97, 0xCA, 0xBD, 0xA0, 0x97, 0xCA, 0xBD, 0xA0, 0x83, 0xCA, 0xBD, 0x20,
 0x83, 0xCA, 0xBD, 0x20, 0x00, 0x24, 0x3C, 0x3C, 0x66, 0xB4, 0xBD, 0xA0, 0x66, 0xB4, 0xBD, 0xA0,
 0x66, 0xB5, 0xBF, 0x20, 0x66, 0xB5, 0xBF, 0x20, 0x65, 0xB5, 0xC7, 0x20, 0x65, 0xB5, 0xC7, 0x20,
 0x61, 0xB5, 0xD5, 0xA0, 0x61, 0xB5, 0xD5, 0xA0, 0x00, 0x24, 0x3C, 0x3C, 0x82, 0xD1, 0xA5, 0x20,
 0x82, 0xD1, 0xA5, 0xA0, 0x83, 0xCF, 0xAE, 0xA0, 0xC3, 0xCE, 0xAE, 0xA0, 0xC3, 0xD1, 0x9E, 0xA0,
 0xD2, 0xD3, 0x96, 0x20, 0x92, 0xD2, 0x95, 0x20, 0x92, 0xD2, 0x95, 0x20, 0x00, 0x3C, 0x3C, 0x3C,
 0x5A, 0x84, 0x9C, 0x20, 0x5A, 0x84, 0x9C, 0x20, 0x5A, 0x84, 0x9D, 0x20, 0x5A, 0x84, 0x9D, 0x20,
 0x5A, 0x8A, 0xB6, 0xA0, 0x5A, 0x8A, 0xB6, 0xA0, 0x87, 0xAD, 0xC6, 0xA0, 0x87, 0xAD, 0xC6, 0xA0,
 0x47, 0xB1, 0xCE, 0xA0, 0x47, 0xB1, 0xCE, 0xA0, 0x97, 0xB2, 0xC6, 0x20, 0x97, 0xB2, 0xC6, 0x20,
 0x9B, 0xB1, 0xC4, 0x20, 0x9B, 0xB1, 0xC4, 0x20, 0x00, 0x24, 0x3C, 0x3C, 0xD6, 0xB3, 0x6C, 0xA0,
 0xD6, 0xB3, 0x6D, 0x20, 0xFA, 0xB4, 0x66, 0x20, 0xFA, 0xB4, 0x66, 0x20, 0xFA, 0xB4, 0x66, 0x20,
 0xFA, 0xB4, 0x66, 0x20, 0xF6, 0xB4, 0x65, 0x20, 0xEA, 0xB4, 0x64, 0xA0, 0x00, 0x24, 0x3C, 0x3C,
 0x9B, 0xAD, 0x6C, 0xA0, 0x9B, 0xAD, 0x6C, 0xA0, 0xDB, 0xAE, 0x6D, 0x20, 0xDB, 0xAE, 0x6D, 0x20,
 0xDB, 0xAE, 0x6D, 0x20, 0xDB, 0xAE, 0x6D, 0x20, 0x9B, 0xAE, 0x6C, 0xA0, 0x9B, 0xAE, 0x6C, 0xA0,
 0x00, 0x1C, 0x3C, 0x3C, 0x80, 0xD6, 0x18, 0x20, 0x80, 0xD6, 0x1A, 0xA0, 0x90, 0xB2, 0x13, 0xA0,
 0xA4, 0xB2, 0x13, 0xA0, 0xA5, 0xB1, 0x24, 0xA0, 0xEA, 0x91, 0x76, 0x20, 0x00, 0x1C, 0x3C, 0x3C,
 0x80, 0xB5, 0x18, 0x20, 0x80, 0xB5, 0x1B, 0xA0, 0x10, 0xD5, 0x04, 0xA0, 0xA0, 0xD5, 0x0C, 0x20,
 0x40, 0xD2, 0x2C, 0xA0, 0x40, 0xD9, 0x5E, 0x20, 0x00, 0x24, 0x3C, 0x3C, 0x16, 0xB7, 0xFD, 0xB0,
 0x16, 0xB7, 0xFE, 0x30, 0x16, 0xB7, 0xFE, 0xB0, 0x16, 0xB7, 0xFE, 0xB0, 0x16, 0xB7, 0xFE, 0xB0,
 0x16, 0xB7, 0xFE, 0xB0, 0x16, 0xB7, 0xFE, 0x30, 0x16, 0xB7, 0xFD, 0xB0, 0x00, 0x14, 0x3C, 0x3C,
 0xFF, 0x97, 0x60, 0x20, 0xFF, 0x97, 0x63, 0xA0, 0xFA, 0x97, 0x66, 0xA0, 0xA6, 0x97, 0x66, 0xA0,
 0x00, 0x18, 0x3C, 0x3C, 0x1E, 0xBA, 0x7C, 0x30, 0x1E, 0xBA, 0x7D, 0xA0, 0x1E, 0xBA, 0x76, 0xB0,
 0x1E, 0xBA, 0x76, 0xA0, 0x1E, 0xBA, 0x75, 0xB0, 0x00, 0x14, 0x3C, 0x3C, 0x09, 0x97, 0x88, 0x30,
 0x0D, 0x97, 0x8F, 0xB0, 0x09, 0x97, 0x8E, 0xB0, 0x67, 0x96, 0x86, 0x20, 0x00, 0x18, 0x3C, 0x3C,
 0x74, 0xB5, 0x55, 0x20, 0x74, 0xB5, 0x55, 0x20, 0x74, 0xB6, 0x2E, 0x20, 0x74, 0xB6, 0x2E, 0x20,
 0x28, 0xB5, 0x55, 0x20, 0x00, 0x24, 0x3C, 0x3C, 0x4C, 0xB4, 0x5C, 0xA0, 0x4C, 0xB4, 0x5C, 0xA0,
 0x4C, 0xB4, 0x5D, 0x20, 0x4C, 0xB4, 0x5D, 0xA0, 0x4A, 0xB4, 0x5E, 0xA0, 0x4A, 0xB4, 0x5E, 0x20,
 0x4A, 0xB4, 0x5D, 0xA0, 0x4A, 0xB4, 0x5D, 0x20, 0x00, 0x14, 0x3C, 0x3C, 0x88, 0xB4, 0x55, 0x20,
 0x48, 0xB4, 0x5E, 0x20, 0x4C, 0xB4, 0x5F, 0x20, 0x4A, 0xB4, 0x5E, 0x20, 0x00, 0x18, 0x3C, 0x3C,
 0xC2, 0xB9, 0x38, 0x30, 0xC2, 0xB9, 0x38, 0x30, 0x11, 0xB6, 0x97, 0xB0, 0x16, 0xB3, 0x8E, 0x30,
 0x5B, 0xB2, 0x8D, 0xA0, 0x00, 0x14, 0x3C, 0x3C, 0x3A, 0xB3, 0x84, 0x20, 0x36, 0xB3, 0x8D, 0xA0,
 0x79, 0xB2, 0x96, 0x20, 0x97, 0xB1, 0xCD, 0x20, 0x00, 0x18, 0x3C, 0x3C, 0xF5, 0xB0, 0xA4, 0xA0,
 0xB5, 0x8F, 0x86, 0x20, 0xB5, 0x8F, 0x83, 0xA0, 0x54, 0xB0, 0x3C, 0xA0, 0x54, 0xB0, 0x3A, 0xA0,
 0x00, 0x20, 0x3C, 0x3C, 0x09, 0xF3, 0xBD, 0x30, 0x09, 0xF3, 0xBD, 0x30, 0x09, 0xF3, 0xBD, 0xB0,
 0x09, 0xF3, 0x8D, 0xB0, 0x09, 0xF3, 0x8D, 0xB0, 0x09, 0xF3, 0x8D, 0x30, 0x09, 0xF3, 0x8D, 0x30,
 0x00, 0x14, 0x3C, 0x3C, 0xB6, 0xF6, 0x90, 0x30, 0xB6, 0xF6, 0x94, 0x30, 0xB6, 0xF6, 0x96, 0x30,
 0x9B, 0xB4, 0x8D, 0xA0, 0x00, 0x20, 0x3C, 0x3C, 0x6A, 0xB2, 0x84, 0xA0, 0x6A, 0xB2, 0x85, 0x20,
 0x6A, 0xB2, 0x86, 0x20, 0x6A, 0xB2, 0x86, 0xA0, 0x6A, 0xB2, 0x86, 0xB0, 0x6A, 0xB2, 0x86, 0xB0,
 0x6A, 0xB2, 0x86, 0x30, 0x00, 0x14, 0x3C, 0x3C, 0x12, 0xF5, 0x76, 0x20, 0x12, 0xF5, 0x76, 0xA0,
 0x12, 0xF5, 0x77, 0x30, 0xAA, 0xB4, 0x76, 0xA0, 0x00, 0x20, 0x3C, 0x3C, 0x29, 0xBA, 0x8E, 0x30,
 0x29, 0xBA, 0x8E, 0xB0, 0x29, 0xBA, 0x8E, 0xB0, 0x29, 0xBA, 0x8E, 0xB0, 0x29, 0xBA, 0x8E, 0xB0,
 0x29, 0xBA, 0x8E, 0xB0, 0x29, 0xBA, 0x8E, 0x30, 0x00, 0x38, 0x3C, 0x3C, 0x98, 0xD7, 0x5D, 0xA0,
 0x98, 0xD7, 0x5D, 0xA0, 0x98, 0xD7, 0x5D, 0xA0, 0x99, 0xD6, 0x55, 0x20, 0x8E, 0xD6, 0x5C, 0x20,
 0x8F, 0xD8, 0x5E, 0x20, 0x8F, 0xD8, 0x5E, 0x20, 0xAF, 0xD8, 0x56, 0xA0, 0xAF, 0xD8, 0x56, 0xA0,
 0xAF, 0xD8, 0x56, 0xA0, 0x7F, 0xD8, 0x5F, 0x20, 0x7F, 0xD8, 0x5F, 0x20, 0x6B, 0xB7, 0x6F, 0xA0,
 0x00, 0x40, 0x3C, 0x3C, 0x57, 0xB3, 0xDD, 0xA0, 0x46, 0xB4, 0xE7, 0xA0, 0x46, 0xB4, 0xDF, 0xA0,
 0xAB, 0xB4, 0xCF, 0xA0, 0xAB, 0xB4, 0xCF, 0xA0, 0xEA, 0xB5, 0xC7, 0x20, 0xEA, 0xB5, 0xC7, 0x20,
 0xFA, 0xB6, 0xB6, 0xA0, 0xFA, 0xB6, 0xB6, 0xA0, 0xBA, 0xB7, 0x9E, 0x20, 0xBA, 0xB7, 0x9E, 0x20,
 0xBA, 0xD8, 0x7D, 0x20, 0xBA, 0xD8, 0x7D, 0x20, 0xFA, 0xD8, 0x73, 0x20, 0xFA, 0xD8, 0x73, 0x20,
 0x00, 0x40, 0x3C, 0x3C, 0xBB, 0xB7, 0xB6, 0x20, 0xBB, 0xB7, 0xB6, 0x20, 0xFB, 0xB7, 0xAF, 0x20,
 0xFB, 0xB7, 0xAF, 0x20, 0xFB, 0xB7, 0xAF, 0xA0, 0xFB, 0xB7, 0xAF, 0xA0, 0xBB, 0xB7, 0x9F, 0xA0,
 0xBB, 0xB7, 0x9F, 0xA0, 0xB6, 0xB8, 0x9F, 0x20, 0xBA, 0xD8, 0x8F, 0x20, 0xBA, 0xD8, 0x8F, 0x20,
 0xBA, 0xD8, 0x7E, 0xA0, 0xBA, 0xD8, 0x7E, 0xA0, 0xFA, 0xD8, 0x75, 0xA0, 0xFA, 0xD8, 0x75, 0xA0,
 0x00, 0x40, 0x3C, 0x3C, 0xEB, 0xB3, 0xAE, 0x20, 0xEB, 0xB3, 0xAE, 0x20, 0x97, 0xB4, 0xA7, 0x20,
 0x97, 0xB4, 0xA7, 0x20, 0x97, 0xB4, 0xA7, 0xA0, 0x57, 0xB4, 0xA7, 0xA0, 0x67, 0xB6, 0x9F, 0x20,
 0x67, 0xB6, 0x9F, 0x20, 0x77, 0xB6, 0x87, 0x20, 0xBB, 0xB7, 0x7E, 0xA0, 0xEB, 0xB7, 0x7E, 0xA0,
 0xAB, 0xB8, 0x7E, 0x20, 0xAB, 0xD8, 0x76, 0x20, 0x6B, 0xD8, 0x76, 0x20, 0xBA, 0xB7, 0x8C, 0xA0,
 0x00, 0x40, 0x3C, 0x3C, 0x7F, 0xD8, 0x6D, 0x20, 0x7F, 0xD8, 0x6E, 0xA0, 0x7F, 0xD8, 0x6E, 0xA0,
 0xBF, 0xD7, 0x87, 0x20, 0xFB, 0xD7, 0x8F, 0x20, 0xBB, 0xD7, 0x9F, 0xA0, 0x67, 0xD6, 0xBF, 0xA0,
 0x67, 0xD6, 0xBF, 0xA0, 0x67, 0xD5, 0xBF, 0x20, 0x67, 0xD5, 0xBF, 0x20, 0x61, 0xD5, 0xBE, 0x20,
 0x61, 0xD5, 0xBE, 0x20, 0x61, 0xD5, 0xBE, 0x20, 0x61, 0xD4, 0xC5, 0x20, 0x61, 0xD4, 0xC5, 0x20,
 0x00, 0x2C, 0x3C, 0x3C, 0x86, 0x94, 0xBD, 0xA0, 0x86, 0x94, 0xBE, 0xA0, 0x86, 0x96, 0xC7, 0x20,
 0x42, 0xB4, 0xD7, 0xA0, 0x53, 0xB5, 0xCF, 0xA0, 0x62, 0xB5, 0xC7, 0x20, 0x62, 0xB5, 0xC6, 0xA0,
 0x62, 0xB5, 0xC6, 0x20, 0x62, 0xB5, 0xC5, 0xA0, 0x62, 0xB5, 0xC5, 0x20, 0x00, 0x24, 0x3C, 0x3C,
 0xAD, 0xAF, 0xA5, 0x20, 0xAD, 0xAF, 0xA5, 0x20, 0xAD, 0xAF, 0xA6, 0x20, 0xAD, 0xAF, 0xA6, 0x20,
 0xAD, 0xAD, 0x96, 0x20, 0xAD, 0xAD, 0x96, 0x20, 0xF9, 0xAD, 0x8D, 0x20, 0xF9, 0xAD, 0x8D, 0x20,
 0x00, 0x0C, 0x3C, 0x3C, 0xAB, 0xB3, 0x80, 0x20, 0xAB, 0xB3, 0x80, 0x20, 0x00, 0x14, 0x3C, 0x3C,
 0xAB, 0xB3, 0x80, 0x20, 0xAB, 0xB3, 0x80, 0x20, 0xAB, 0xB3, 0x80, 0x20, 0xAB, 0xB3, 0x80, 0x20,
 0x00, 0x18, 0x3C, 0x3C, 0x09, 0xF3, 0xBD, 0x30, 0x09, 0xF3, 0xBD, 0x30, 0x09, 0xF3, 0x8D, 0xB0,
 0x09, 0xF3, 0x8D, 0x30, 0x09, 0xF3, 0x8D, 0x30, 0x75, 0x30, 0x69, 0xB6, 0x55, 0xA0, 0xAD, 0xB7
 };
