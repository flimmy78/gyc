#ifndef TOKEN
#error "You must define TOKEN macro before include this file"
#endif

//keywords
TOKEN(TK_AUTO,      "auto")		// 0
TOKEN(TK_EXTERN,    "extern")	// 1
TOKEN(TK_REGISTER,  "register")	// 2
TOKEN(TK_STATIC,    "static")	// 3
TOKEN(TK_TYPEDEF,   "typedef")	// 4
TOKEN(TK_CONST,     "const")	// 5
TOKEN(TK_VOLATILE,  "volatile")	// 6
TOKEN(TK_SIGNED,    "signed")	// 7
TOKEN(TK_UNSIGNED,  "unsigned")	// 8
TOKEN(TK_SHORT,     "short")	// 9
TOKEN(TK_LONG,      "long")		// 10
TOKEN(TK_CHAR,      "char")		// 11
TOKEN(TK_INT,       "int")		// 12
TOKEN(TK_INT64,     "__int64")	// 13
TOKEN(TK_FLOAT,     "float")	// 14
TOKEN(TK_DOUBLE,    "double")	// 15
TOKEN(TK_ENUM,      "enum")		// 16
TOKEN(TK_STRUCT,    "struct")	// 17
TOKEN(TK_UNION,     "union")	// 18
TOKEN(TK_VOID,      "void")		// 19
TOKEN(TK_BREAK,     "break")	// 20
TOKEN(TK_CASE,      "case")		// 21
TOKEN(TK_CONTINUE,  "continue")	// 22
TOKEN(TK_DEFAULT,   "default")	// 23
TOKEN(TK_DO,        "do")		// 24
TOKEN(TK_ELSE,      "else")		// 25
TOKEN(TK_FOR,       "for")		// 26
TOKEN(TK_GOTO,      "goto")		// 27
TOKEN(TK_IF,        "if")		// 28
TOKEN(TK_RETURN,    "return")	// 29
TOKEN(TK_SWITCH,    "switch")	// 30
TOKEN(TK_WHILE,     "while")	// 31
TOKEN(TK_SIZEOF,    "sizeof")	// 32

//identifier
TOKEN(TK_ID,        "ID")		// 33

//constant
TOKEN(TK_COMMENT,      "comment")				// 34
TOKEN(TK_INTCONST,     "int")					// 35
TOKEN(TK_UINTCONST,    "unsigned int")			// 36
TOKEN(TK_LONGCONST,    "long")					// 37
TOKEN(TK_ULONGCONST,   "unsigned long")			// 38
TOKEN(TK_LLONGCONST,   "long long")				// 39
TOKEN(TK_ULLONGCONST,  "unsigned long long")	// 40
TOKEN(TK_FLOATCONST,   "float")					// 41
TOKEN(TK_DOUBLECONST,  "double")				// 42
TOKEN(TK_LDOUBLECONST, "long double")			// 43
TOKEN(TK_STRING,       "STR")
TOKEN(TK_WIDESTRING,   "WSTR")

//operators
TOKEN(TK_COMMA,         ",")
TOKEN(TK_QUESTION,      "?")
TOKEN(TK_COLON,         ":")
TOKEN(TK_ASSIGN,        "=")
TOKEN(TK_BITOR_ASSIGN,  "|=")
TOKEN(TK_BITXOR_ASSIGN, "^=")
TOKEN(TK_BITAND_ASSIGN, "&=")
TOKEN(TK_LSHIFT_ASSIGN, "<<=")
TOKEN(TK_RSHIFT_ASSIGN, ">>=")
TOKEN(TK_ADD_ASSIGN,    "+=")
TOKEN(TK_SUB_ASSIGN,    "-=")
TOKEN(TK_MUL_ASSIGN,    "*=")
TOKEN(TK_DIV_ASSIGN,    "/=")
TOKEN(TK_MOD_ASSIGN,    "%=")
TOKEN(TK_OR,            "||")
TOKEN(TK_AND,           "&&")
TOKEN(TK_BITOR,         "|")
TOKEN(TK_BITXOR,        "^")
TOKEN(TK_BITAND,        "&")
TOKEN(TK_EQUAL,         "==")
TOKEN(TK_UNEQUAL,       "!=")
TOKEN(TK_GREAT,         ">")
TOKEN(TK_LESS,          "<")
TOKEN(TK_GREAT_EQ,      ">=")
TOKEN(TK_LESS_EQ,       "<=")
TOKEN(TK_LSHIFT,        "<<")
TOKEN(TK_RSHIFT,        ">>")
TOKEN(TK_ADD,           "+")
TOKEN(TK_SUB,           "-")
TOKEN(TK_MUL,           "*")
TOKEN(TK_DIV,           "/")
TOKEN(TK_MOD,           "%")
TOKEN(TK_INC,           "++")
TOKEN(TK_DEC,           "--")
TOKEN(TK_NOT,           "!")
TOKEN(TK_COMP,          "~")
TOKEN(TK_DOT,           ".")
TOKEN(TK_POINTER,       "->")
TOKEN(TK_LPAREN,        "(")
TOKEN(TK_RPAREN,        ")")
TOKEN(TK_LBRACKET,      "[")
TOKEN(TK_RBRACKET,      "]")
TOKEN(TK_HASH,          "#")

//punctuators
TOKEN(TK_LBRACE,        "{")
TOKEN(TK_RBRACE,        "}")
TOKEN(TK_SEMICOLON,     ";")
TOKEN(TK_ELLIPSE,       "...")
TOKEN(TK_POUND,         "#")
TOKEN(TK_NEWLINE,       "\n")

TOKEN(TK_END,           "EOF")
