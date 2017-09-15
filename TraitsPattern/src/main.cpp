#include <iostream>
#include <cstdlib>
#include <complex>

#include "simpletraits.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::complex;

using namespace simpletraits;

template <typename T>
void detect( T a){
string t;

  if ( is_pointer<T>::value )
   t += "pointer to ";

  if (is_float< typename remove_pointer<T>::type >::value)
    t += "float "; 
  if (is_double< typename remove_pointer<T>::type >::value)
    t += "double "; 
  if (is_complex_float< typename remove_pointer<T>::type >::value)
    t += "complex float "; 
  if (is_complex_double< typename remove_pointer<T>::type >::value)
    t += "complex double "; 

  if ( is_real< typename remove_pointer<T>::type >::value )
   t += " (real)"; 

  if ( is_complex< typename remove_pointer<T>::type >::value )
   t += " (complex)"; 

  cout << t << endl;
}

int main(int argc, char *argv[]){

  float f=0.0f;
  float *pf=NULL;
  double d=0.0;
  double *pd=NULL;
  complex<float> cf(0.0f,0.0f);
  complex<double> cd(0.0f,0.0f);;
  complex<float> *pcf = NULL;
  complex<double> *pcd = NULL;

  cout << "f:   " ; detect(f);
  cout << "d:   " ; detect(d);
  cout << "pf:  " ; detect(pf);
  cout << "pd:  " ; detect(pd);
  cout << "cf:  " ; detect(cf);
  cout << "cd:  " ; detect(cd);
  cout << "pcf: " ; detect(pcf);
  cout << "pcd: " ; detect(pcd);


  exit (EXIT_SUCCESS);
}

