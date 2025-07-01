# COMPILER-DESIGN-BASICS

COMPANY: CODTECH IT SOLUTIONS

NAME: AMAN SULEMAN MARANDI

INTERN ID: CT04DG658

DOMAIN: C PROGRAMMING

DURATION: 4 WEEKS

MENTOR: NEELA SANTHOSH KUMAR



# Introduction to Compiler
A compiler is a specialized software program that translates code written in a high-level programming language (like C or Java) into a lower-level language, typically machine code, that a computer’s processor can execute. It performs this transformation through several sequential stages, each addressing a specific aspect of the source code. These stages typically include:
- Lexical analysis
- Syntax analysis
- Semantic analysis
- Optimization
- Code generation
The lexical analyzer, or lexer, is the first and one of the most critical stages. It reads the raw source code and converts it into a series of tokens, which are the building blocks for understanding the syntactic structure of the program.

# Role of a Lexical Analyzer
A lexical analyzer’s main job is to process the input stream of characters and group them into meaningful sequences called lexemes. It then categorizes each lexeme as a token, such as a keyword (int, while, return), an operator (+, ==, /), or an identifier (main, x, sum). This simplifies the job of subsequent compiler stages, like the parser.
When implementing a lexical analyzer in C, a basic and educationally valuable approach is to scan the input character by character from a file, identify the components of the language, and tag them accordingly.

# Design of a Simple Lexical Analyzer in C
Here's a conceptual overview of how a basic lexical analyzer works:
1. Reading Input
The analyzer reads the contents of a text file containing C code. This file is typically opened using the standard fopen() function, and the contents are scanned using functions like fgetc() or fscanf().
2. Skipping Whitespace and Comments
Whitespace (spaces, tabs, newlines) is generally ignored during tokenization. The analyzer skips over these characters. Basic handling of single-line (//) and multi-line (/* */) comments can also be integrated to ignore them during scanning.
3. Identifying Keywords
Keywords are reserved words in the C language with fixed meanings. Common examples include if, else, while, return, int, float, etc.
To identify keywords, the analyzer collects characters until a delimiter (like whitespace or a punctuation mark) is reached. Then, it compares the string with a predefined list of C keywords. If it matches any, it's classified as a keyword.
4. Detecting Identifiers
Identifiers are names given by the programmer to variables, functions, arrays, etc. For instance, in int age = 30;, the word age is an identifier.
If a lexeme starts with a letter or underscore and contains letters, digits, or underscores, and is not a keyword, it is marked as an identifier.
5. Recognizing Operators
Operators are symbols that perform operations on variables and values. These include arithmetic (+, -, *, /), relational (<, >, ==), logical (&&, ||, !), assignment (=, +=, -=), and others.
The analyzer checks each character (or pair of characters in the case of compound operators like ==) and determines whether it forms an operator. A lookup table or a series of conditional checks can assist in this identification.

# Output of the Analyzer
Each time a token is identified—whether a keyword, identifier, or operator—the analyzer usually prints the token and its category. For example:
Token: int        → Keyword  
Token: x          → Identifier  
Token: =          → Operator  
Token: 5          → Constant  



# Educational Value and Applications
This basic lexical analyzer lays the groundwork for more advanced compiler design topics, such as symbol table management, regular expressions, finite automata, and syntax-directed translation. Although this version focuses only on identifying three types of tokens, the same principles can be extended to recognize constants, delimiters, string literals, and more complex patterns using tools like Lex and Flex.
Such projects help deepen one’s understanding of how programming languages are structured under the hood—valuable knowledge for any programmer with a curiosity for compilers, interpreters, or even programming language design itself.


