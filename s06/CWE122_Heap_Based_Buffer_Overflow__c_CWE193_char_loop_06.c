/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_loop_06.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-06.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

/* The variable below is declared "const", so a tool should be able
 * to identify that reads of this will always give its initialized value. */
static const int STATIC_CONST_FIVE = 5;

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_loop_06_bad()
{
    char * data;
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        /* FLAW: Did not leave space for a null terminator */
        data = (char *)malloc(10*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    {
        char source[10+1] = SRC_STRING;
        size_t i, sourceLen;
        sourceLen = strlen(source);
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        for (i = 0; i < sourceLen + 1; i++)
        {
            data[i] = source[i];
        }
        printLine(data);
        free(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodG2B1()
{
    char * data;
    data = NULL;
    if(STATIC_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Allocate space for a null terminator */
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    {
        char source[10+1] = SRC_STRING;
        size_t i, sourceLen;
        sourceLen = strlen(source);
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        for (i = 0; i < sourceLen + 1; i++)
        {
            data[i] = source[i];
        }
        printLine(data);
        free(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        /* FIX: Allocate space for a null terminator */
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    {
        char source[10+1] = SRC_STRING;
        size_t i, sourceLen;
        sourceLen = strlen(source);
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        for (i = 0; i < sourceLen + 1; i++)
        {
            data[i] = source[i];
        }
        printLine(data);
        free(data);
    }
}

void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_loop_06_good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_loop_06_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_loop_06_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
