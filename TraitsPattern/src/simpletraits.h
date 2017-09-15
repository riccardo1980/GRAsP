
#include <complex>

/**
  * Collection of traits
  * Most of them will be deprecated
  * when adpting c++11 (or boost) 
  */ 
namespace simpletraits {

  /**
    * Checks whether T is a pointer to object or a pointer to function 
    * Provides the member constant value which is equal to true, if T 
    * is a object pointer type. Otherwise, value is equal to false.
    * 
    */
template <typename T>
struct is_pointer {
  static const bool value = false;
};

template <typename T>
struct is_pointer<T*> {
  static const bool value = true;
};

/**
  * Provides the member typedef type which is the 
  * type pointed to by T, or, if T is not a pointer,
  * then type is the same as T
  */
template <typename T>
struct remove_pointer {
  typedef T type;
};

template <typename T>
struct remove_pointer<T*> {
  typedef T type;
};

/**
  * If T is a complex number type then true 
  * (of type std::complex<U> for some type U), otherwise false.
  */
template < typename T >
struct is_complex {
  static const bool value = false;
};
template < typename T >
struct is_complex< std::complex<T> > {
  static const bool value = true;
};


/* the following are extension */

/**
 * Returns true if T is double
 */
template <typename T>
struct is_double { 
  static const bool value = false; 
};
template <>
struct is_double<double> { 
  static const bool value = true; 
};

/**
 * Returns true if T is float
 */
template <typename T>
struct is_float { 
  static const bool value = false; 
};
template <>
struct is_float<float> { 
  static const bool value = true; 
};

/**
 * Returns true if T is std::complex<double>
 */
template <typename T>
struct is_complex_double {
  static const bool value = false;
};
template <>
struct is_complex_double< std::complex<double> > {
  static const bool value = true;
};

/**
 * Returns true if T is std::complex<float>
 */
template <typename T>
struct is_complex_float {
  static const bool value = false;
};

template <>
struct is_complex_float< std::complex<float> > {
  static const bool value = true;
};

/**
  * returns true if is_complex<T>::value is false
  */ 
template < typename T >
struct is_real {
  static const bool value = ! is_complex<T>::value;
};

} // end of namespace simpletraits
