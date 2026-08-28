//#define KEYWORD 01
//#define EXTERNAL 02
//#define STATIC 04

// or 
//enum {KEYWORD = 01, EXTERNAL = 02, STATIC = 04};

struct {
    unsigned int is_keyboard : 1;
    unsigned int is_extern   : 1; 
    unsigned int is_static   : 1; 
} flags;