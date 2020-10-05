//myRunif.c 
#include <R.h>
#include <Rinternals.h>

/* SEXP myRunif( SEXP n, SEXP min, SEXP max ){
  
  SEXP statsPackage;
  statsPackage = PROTECT( eval( lang2( install( "getNamespace" ),
                                ScalarString( mkChar( "stats" ) ) ),
                                R_GlobalEnv ) );  
  
  SEXP RCallBack;
  RCallBack = PROTECT( allocVector( LANGSXP, 4 ) ); 
  SETCAR( RCallBack,
          findFun( install("runif"), statsPackage ) );  
  
  SETCADR( RCallBack, n );
  SET_TAG( CDR( RCallBack ), install("n") );
  
  SETCADDR( RCallBack, min );
  SET_TAG( CDDR( RCallBack ), install("min") );
  
  SETCADDDR( RCallBack, max );
  SET_TAG( CDR(CDDR( RCallBack )), install("max"));
  
  SEXP randoms;
 randoms =  PROTECT( eval( RCallBack, statsPackage )
  );  
  
  UNPROTECT(3);
  return( randoms );
  
}
*/
// install(): install the name of an R object
SEXP myRunif( SEXP n, SEXP min, SEXP max ){
  
  SEXP statsPackage;
  statsPackage = PROTECT( eval( lang2( install("getNamespace"),
                                ScalarString( mkChar( "stats" ) ) ),
                                R_GlobalEnv ) );  
  SEXP randoms;
  randoms = PROTECT( eval( lang4( install("runif"),
                           n,
                           min,
                           max),
                           statsPackage ) );
  UNPROTECT(2); 
  return( randoms );
}