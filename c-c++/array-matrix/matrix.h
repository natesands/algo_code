/* Stroustrup's implementation of Matrix class */

template<typename T, size_t N>
class Matrix {
public:
  static constexpr size_t order = N;          /* constexpr are implicitly const and must 
                                                 be initialized by a constant expression,
                                                 i.e. an expression whose value cannot
                                                 change and that can be evaluated at compile
                                                 time.  

                                                 A static member variable is shared by
                                                 all instances of the class.
                                                 */
  using value_type = T;                         /* typedef */

  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;    /* a const_iterator may read by not write elements */

  Matrix() = default;
  Matrix(Matrix&&) = default;       /* 
