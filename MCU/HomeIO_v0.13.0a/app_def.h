/* 
 * File:   app_def.h
 * Author: axel
 *
 * Created on July 3, 2017, 3:39 PM
 */

#ifndef APP_DEF_H
#define	APP_DEF_H

#ifdef	__cplusplus
extern "C" {
#endif

    

    #define KG // LED OG DG EG KG HEIZUNG TEST


    #if defined(KG) || defined(EG) || defined(OG) || defined(DG) || defined(HEIZUNG) || defined(TEST)
        #define Home8   
    #endif
    
    #if defined(KG)
    
        //#define main void main_kg(void)

    #endif
    



#ifdef	__cplusplus
}
#endif

#endif	/* APP_DEF_H */

