#include "version.h"

#ifdef __cplusplus
    #include <iostream>
    #include <string>

    using namespace std;
    void _version()
    {
        /* prints the C++ dialect the compiler intends to comply with */
        long int versions_id[] = {0L, 1L, 199700L, 201100L, 201400L, 201700L, 210704L};
        string version_name[] = {"Pre C++ 98", "C++ 98", "C++ 11", "C++ 14", "C++ 17"};
        size_t size = sizeof(versions_id)/sizeof(versions_id[0]);
        for(size_t i = 0; i < size-1; ++i)
        {
            if(__cplusplus >= versions_id[i] && __cplusplus < versions_id[i+1])
            {
                cout << "C++ version: " << version_name[i] << endl;
            }
        }
    }
#endif

#ifndef __cplusplus
    #ifdef __STDC_VERSION__
        #include <stdio.h>
        #include <stdlib.h>
        void _version()
        {
            /* prints the  C dialect the compiler intends to comply with */
            long int versions_id[] = {0L, 199000L, 199400L, 199900L , 201100L, 201710L, 201711L};
            char* version_name[] = {"Pre C99","C90", "C95", "C99", "C11", "C17"};
            size_t size = sizeof(versions_id)/sizeof(versions_id[0]);
            for(size_t i = 0; i < size-1; ++i)
            {
                if(__STDC_VERSION__ >= versions_id[i] && __STDC_VERSION__ < versions_id[i+1])
                {
                    printf("C version: %s\n", version_name[i]);
                }
            }
        }
    #endif
#endif
